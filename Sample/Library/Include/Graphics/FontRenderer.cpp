#include "FontRenderer.h"

#include "../Framework/Framework.h"


bool u22::graphics::FontRenderer::IsCodeValid(const char s) const {
    //return !(s == ' ' || s == '\t' || s == '\n' || s == '\r' || s == '\0');
    return !(s == '\n' || s == '\0');
}

bool u22::graphics::FontRenderer::RegisterCharacter(const char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        char text[3] = { 0 };
        uint32_t t = 0;
        if (::IsDBCSLeadByte(str[i])) {
            wchar_t wstr[2];
            ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, &str[i], 2, wstr, 2);
            t = wstr[0];
            text[0] = str[i]; text[1] = str[i + 1];
            i++;
        }
        else {
            //半角スペース、タブ、改行などの文字はアトラスには無視
            if (!this->IsCodeValid(str[i])) {
                continue;
            }
            t = str[i];
            text[0] = str[i];
        }
        if (_dest_offset_x + _font->GetSize() >= static_cast<std::uint32_t>(_texture->GetWidth())) {
            _dest_offset_x = 0;
            _dest_offset_y += _font->GetSize() + _margin;
            if (_dest_offset_y + _font->GetSize() >= static_cast<std::uint32_t>(_texture->GetHeight())) {
                return false;
            }
        }
        //Fontから取得
        auto img = _font->CreateFontImage(t);
        if (img == nullptr) {
            continue;
        }
        //データをRGPAの形式に変更
        uint8_t* b4Pixels = new uint8_t[img->width * img->height * 4];
        for (int y = 0; y < img->height; y++) {
            for (int x = 0; x < img->width; x++) {
                b4Pixels[(y * img->width + x) * 4 + 0] = img->pixels[y * img->width + x];
                b4Pixels[(y * img->width + x) * 4 + 1] = img->pixels[y * img->width + x];
                b4Pixels[(y * img->width + x) * 4 + 2] = img->pixels[y * img->width + x];
                b4Pixels[(y * img->width + x) * 4 + 3] = img->pixels[y * img->width + x];
            }
        }
        //テクスチャに転送
        _texture->SubImageUpdate(_dest_offset_x + img->offset_x, _dest_offset_y + img->offset_y, img->width, img->height, b4Pixels);
        //マップに登録
        _slices_map[text] = u22::shape::Rectangle((float)_dest_offset_x, (float)_dest_offset_y, (float)_dest_offset_x + img->offset_x + img->width, (float)_dest_offset_y + img->offset_y + img->height);
        delete[] b4Pixels;
        //次の書き込み場所へ
        _dest_offset_x += _font->GetSize() + _margin;
    }
    return true;
}

void u22::graphics::FontRenderer::TransferUniform(const std::shared_ptr<u22::graphics::EffectShader>& shader, const u22::shape::Rectangle& uniform_rectangle, const u22::math::Vector4F& uniform_color, const u22::math::Matrix4x4F& model_transform, const u22::graphics::Camera& camera) const {
    shader->TransferUniform("uniform_size", _texture->GetSize());
    shader->TransferUniform("uniform_rectangle", *reinterpret_cast<const u22::math::Vector4F*>(&uniform_rectangle));
    shader->TransferUniform("uniform_color", uniform_color);
    shader->TransferUniform("view_projection", camera.GetViewProjectionMatrix());
    shader->TransferUniform("model_transform", model_transform);
}

void u22::graphics::FontRenderer::Draw(void) const {
    _vao.Bind();
    _texture->Bind();
    _vao.DrawElements();
    _vao.UnBind();
    _texture->UnBind();
}

u22::graphics::FontRenderer::FontRenderer() :
    _font(),
    _vao(),
    _shader(),
    _texture(),
    _dest_offset_x(),
    _dest_offset_y(),
    _margin(2),
    _slices_map() {
}

u22::graphics::FontRenderer::~FontRenderer() {
}

void u22::graphics::FontRenderer::SetShader(const std::shared_ptr<u22::graphics::EffectShader>& ptr) {
    this->_shader = ptr;
}

bool u22::graphics::FontRenderer::Load(const char* path, uint32_t size) {
    _font = std::make_shared<u22::graphics::Font>();
    if (!_font->Generate(path, size)) {
        _font.reset();
        return false;
    } // if

    _texture = std::make_shared<u22::graphics::Texture>();
    _texture->Generate();
    _texture->TextureMapping(1024, 1024);

    if (!_vao.Generate<u22::graphics::SpriteVertex>(u22::graphics::kSpriteVertices, u22::graphics::kSpriteIndices)) {
        _vao.Delete();
        return false;
    } // if

    auto shader = u22::Framework::GetInfomation().graphics->GetEffectShader(u22::graphics::EffectShaderType::Sprite);
    if (!shader) {
        return false;
    } // if
    this->SetShader(shader);
    return true;
}

bool u22::graphics::FontRenderer::Render(const u22::math::Vector2F& position, const u22::math::Vector4F& color, const std::string& str, const u22::graphics::Camera& camera) {
    if (_shader.expired()) {
        return false;
    } // if
    auto shader = _shader.lock();

    //スライスマップ
    auto& map = _slices_map;
    //テクスチャ
    auto tex = _texture;
    //描画座標
    float dx = position.x;
    float dy = position.y;

    for (size_t i = 0; i < str.size(); i++) {
        //描画文字
        char text[3] = { 0 };
        if (IsDBCSLeadByte(str[i])) {
            text[0] = str[i]; text[1] = str[i + 1];
            i++;
        } // if
        else {
            //改行文字は次の行へ字下げ
            if (str[i] == '\n') {
                dx = position.x;
                dy += _font->GetSize();
                continue;
            }
            text[0] = str[i];
        } // else
        //マップから検索
        auto slice = map.find(text);
        if (slice == map.end()) {
            if (!this->RegisterCharacter(text)) {
                return false;
            } // if
            slice = map.find(text);
            if (slice == map.end()) {
                return false;
            } // if
        } // if

        shader->Enable();
        {
            auto pos = u22::math::Vector3F(dx, dy, 0.0f);
            // offset
            pos.x += slice->second.GetWidth() * 0.5f;
            pos.y += slice->second.GetHeight() * 0.5f;
            // flip
            pos.y *= -1.0f;
            this->TransferUniform(shader, slice->second, color, u22::math::utility::ConputeTransform(pos, u22::math::Vector3F(), u22::math::Vector3F(slice->second.GetWidth(), slice->second.GetHeight(), 1.0f)), camera);
        }
        this->Draw();
        shader->Disable();
        dx += slice->second.GetWidth();
    }
    return true;
}

bool u22::graphics::FontRenderer::Release(void) {
    _font.reset();
    _vao.Delete();;
    _shader.reset();
    _texture.reset();
    _slices_map.clear();
    return true;
}