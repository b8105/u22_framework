#include "GameApplicaion.h"

#include <functional>


namespace general {
CCamera camera;
int test_no = -1;
int test_count = 2;
Vector2 mouse_position = Vector2();
CCircle mouse_circle = CCircle();
Vector2 size = Vector2(192.0f, 64.0f);
int margin = 8;
std::string click_message = "Click";
bool on_button = false;
}

namespace sprite_sample {
//! 0.0f ~ 1.0f の値が入る
//! テクスチャの画像の色に掛ける値
Vector4 _color_rgba = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
//! 座標
Vector3 _position;
//! テクスチャ
CTexture _texture;
//! アニメーション
CSpriteAnimationController _motion;
}
namespace sound_sample {
CSoundStreamBuffer _bgm;
CSoundBuffer _se;
float volume = 0.0f;
}


void Input(void) {
    general::mouse_position.x = g_pInput->GetMouseX();
    general::mouse_position.y = g_pInput->GetMouseY();
    general::mouse_circle = CCircle(general::mouse_position, 10.0f);

    if (g_pInput->IsPush(Keycode::Key0)) {
        general::test_no = 0;
        sound_sample::_bgm.Pause();
    } // if
    else if (g_pInput->IsPush(Keycode::Key1)) {
        general::test_no = 1;
    } // else if
}

bool InitializeSpriteSample(void) {
    using namespace sprite_sample;

    _position = Vector3(100.0f, 300.0f, 0.0f);

    if (!_texture.Load("texture/player.png")) {
        return false;
    } // if

    SpriteAnimationCreate anim[] = {
    //待機
    {
        "待機",
        0,0,
        60,64,
        TRUE, {{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0},{5,6,0},{5,7,0}}
    },
    //移動
    {
        "移動",
        0,70,
        60,64,
        TRUE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0},{5,4,0},{5,5,0}}
    },
    //ジャンプ
    {
        "ジャンプ開始",
        0,140,
        60,64,
        FALSE,{{5,0,0},{5,1,0},{5,2,0},{5,3,0}}
    },
    {
        "ジャンプ終了",
        240,140,
        60,64,
        FALSE,{{2,0,0},{2,1,0}}
    },
    //攻撃
    {
        "攻撃",
        0,350,
        90,64,
        FALSE,{{2,0,0},{2,1,0},{2,2,0},{2,3,0},{2,4,0},{2,5,0},{2,6,0}}
    },
    //ダメージ
    {
        "ダメージ",
        480,0,
        60,64,
        FALSE,{{20,0,0}}
    },
    };
    _motion.Create(anim, 6);
    return true;
}

bool InitializeSoundSample(void) {
    using namespace sound_sample;

    _se.Load("se/se_enter.wav");
    _bgm.Load("bgm/shiningstar.ogg");

    _bgm.SetVolume(volume);
    _se.SetVolume(volume);
    _bgm.SetLoop(true);
    return true;
}

bool UpdateSpriteSample(void) {
    using namespace sprite_sample;


    // テクスチャの色変更
    float c = 0.1f;
    if (g_pInput->IsHold(Keycode::Space)) {
        c *= -1.0f;
    } // if

    if (g_pInput->IsHold(Keycode::R)) {
        _color_rgba.r += c;
        _color_rgba.r = std::clamp(_color_rgba.r, 0.0f, 1.0f);
    } // if
    else if (g_pInput->IsHold(Keycode::G)) {
        _color_rgba.g += c;
        _color_rgba.g = std::clamp(_color_rgba.g, 0.0f, 1.0f);
    } // else if
    else if (g_pInput->IsHold(Keycode::B)) {
        _color_rgba.b += c;
        _color_rgba.b = std::clamp(_color_rgba.b, 0.0f, 1.0f);
    } // else if
    else if (g_pInput->IsHold(Keycode::A)) {
        _color_rgba.a += c;
        _color_rgba.a = std::clamp(_color_rgba.a, 0.0f, 1.0f);
    } // else if


    if (g_pInput->IsHold(u22::input::KeyCode::Left)) {
        _position.x--;
        if (_motion.GetMotionNo() != 1) {
            _motion.ChangeMotion("移動");
        } // if
    } // if
    else if (g_pInput->IsHold(u22::input::KeyCode::Right)) {
        _position.x++;
        if (_motion.GetMotionNo() != 1) {
            _motion.ChangeMotion("移動");
        } // if
    } // else if
    if (g_pInput->IsPush(u22::input::KeyCode::Up)) {
        _position.y--;
        _motion.ChangeMotion("ジャンプ開始");
    } // if
    else if (g_pInput->IsPush(u22::input::KeyCode::Down)) {
        _position.y++;
        _motion.ChangeMotion("攻撃");
    } // else if
    if (_motion.IsEndMotion()) {
        if (_motion.GetMotionNo() == 2) {
            _motion.ChangeMotion(3);
        } // if
        else if (_motion.GetMotionNo() == 3) {
            _motion.ChangeMotion(0);
        } // else if
    } // if


    _motion.AddTimer(g_pClock->GetFrameSecond());
    return true;
}

bool UpdateSoundSample(void) {
    using namespace sound_sample;

    float value = 0.005f;
    if (g_pInput->IsHold(u22::input::KeyCode::Up)) {
        volume += value;
        volume = std::clamp(volume, 0.0f, 1.0f);

        _bgm.SetVolume(volume);
        _se.SetVolume(volume);
    } // if
    if (g_pInput->IsHold(u22::input::KeyCode::Down)) {
        volume -= value;
        volume = std::clamp(volume, 0.0f, 1.0f);

        _bgm.SetVolume(volume);
        _se.SetVolume(volume);
    } // if


    if (g_pInput->IsPush(u22::input::KeyCode::B)) {
        if (!_bgm.IsPlay()) {
            _bgm.Play();
        } // if        
    } // if
    if (g_pInput->IsPush(u22::input::KeyCode::S)) {
        if (!_se.IsPlay()) {
            _se.Play();
        } // if
    } // if

    _se.Update();
    return true;
}

bool RenderSpriteSample(void) {
    using namespace general;
    using namespace sprite_sample;

    auto circle = u22::shape::Circle(300.0f, 300.0f, 64.0f);
    ::GraphicsUtilities::RenderLineCircle(circle, color::rgba::kRed, camera);

    CRectangle rect = _motion.GetSourceRectangle();
    _texture.Render(_position, rect, _color_rgba, camera);
    rect.SetBounds(_position, rect.GetSize());

    auto color = Vector4(0.0f, 0.0f, 0.0f, 0.5f);
    if (rect.CollisionCircle(circle)) {
        color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    } // if
    ::GraphicsUtilities::RenderFillCircle(circle, color, camera);
    ::GraphicsUtilities::RenderLineRectangle(rect, color::rgba::kRed, camera);

    auto pos = _position;
    pos.x = 300.0f;
    pos.y += 100.0f;
    ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, "十字キーでモーション変更できます", camera);
    return true;

}
bool RenderSoundSample(void) {
    auto pos = Vector2(300.0f, 300.0f);
    std::string str = "音量(0.0f~~1.0f):";
    str += std::to_string(sound_sample::volume);
    ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, str, general::camera);

    pos.y += 64.0f;
    ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, "BキーでBGM再生", general::camera);
    pos.y += 64.0f;
    ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, "SーでSE再生", general::camera);
    pos.y += 64.0f;
    ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, "上下キーで音量変更", general::camera);
    return true;
}

bool ReleaseSpriteSample(void) {
    using namespace sprite_sample;
    _texture.Release();
    return true;
}

bool ReleaseSoundSample(void) {
    using namespace sound_sample;
    _se.Release();
    _bgm.Release();
    return true;
}

u22::GameApplication::GameApplication() {
}

u22::GameApplication::~GameApplication() {
}

bool u22::GameApplication::Initialize(void) {
    using namespace general;
    camera.Initalize2DCamera();

    InitializeSpriteSample();
    InitializeSoundSample();
    return true;
}

bool u22::GameApplication::Update(void) {
    if (g_pInput->IsHold(u22::input::KeyCode::Escape)) {
        ::PostQuitMessage(0);
    } // if

    Input();
    bool click = g_pInput->IsPush(MouseButton::Left) || g_pInput->IsPush(MouseButton::Right);
    switch (general::test_no) {
        case 0:
            UpdateSpriteSample();
            break;
        case 1:
            UpdateSoundSample();
            break;
        default:
            break;
    } // switch

    auto pos = Vector2(100.0f, 100.0f);
    auto rect = CRectangle();
    general::on_button = false;
    for (int i = 0; i < general::test_count; i++) {
        rect.SetBounds(pos, general::size);
        ::GraphicsUtilities::RenderFillRectangle(rect, color::rgba::kWhite, general::camera);

        if (rect.CollisionCircle(general::mouse_circle)) {
            if (i == general::test_no) {
                general::on_button = false;
            } // if
            else {
                general::on_button = true;
            } // else


            if (click) {
                switch (i) {
                    case 0:
                        general::test_no = 0;
                        sound_sample::_bgm.Pause();
                        break;
                    case 1:
                        general::test_no = 1;
                        break;
                    default:
                        break;
                } // switch
            } // if
        } // if

        pos.x += general::size.x + general::margin;
    } // for


    if (!sound_sample::_bgm.IsPause()) {
        sound_sample::_bgm.Update();
    } // if
    return true;
}

bool u22::GameApplication::Render(void) {
    g_pGraphics->RenderStart();
    g_pGraphics->ClearTarget(color::rgba::kBlue, 1.0f, 1.0f);

    std::string text = "";
    text += "FPS = ";
    text += std::string(std::to_string(::CUtilities::GetFPS()));
    text += "\n";

    switch (general::test_no) {
        case 0:
            text += "SpriteSample";
            break;
        case 1:
            text += "SoundSample";
            break;
        default:
            text += "None";
            break;
    } // switch

    ::GraphicsUtilities::RenderString(u22::math::vec2::kZero, color::rgba::kWhite, text, general::camera);

    auto pos = Vector2(100.0f, 100.0f);
    auto rect = CRectangle();
    for (int i = 0; i < general::test_count; i++) {
        rect.SetBounds(pos, general::size);
        ::GraphicsUtilities::RenderFillRectangle(rect, color::rgba::kWhite, general::camera);

        auto color = i == general::test_no ? color::rgba::kRed : color::rgba::kBlack;

        switch (i) {
            case 0:
                ::GraphicsUtilities::RenderString(pos, color, "SpriteSample", general::camera);
                break;
            case 1:
                ::GraphicsUtilities::RenderString(pos, color, "SoundSample", general::camera);
                break;
            default:
                break;
        } // switch

        pos.x += general::size.x + general::margin;
    } // for



    switch (general::test_no) {
        case 0:
            RenderSpriteSample();
            break;
        case 1:
            RenderSoundSample();
            break;
        default:
            auto pos = Vector2(300.0f, 300.0f);
            auto str = "数字キー０，１を押す、または";
            ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, str, general::camera);
            pos.y += 64.0f;
            str = "白い四角をクリックでサンプルを表示します";
            ::GraphicsUtilities::RenderString(pos, color::rgba::kGreen, str, general::camera);
            break;
    } // switch

    if (general::on_button) {
        ::GraphicsUtilities::RenderString(general::mouse_position, color::rgba::kGreen,
                                          general::click_message, general::camera);
    } // if
    ::GraphicsUtilities::RenderFillCircle(general::mouse_circle, color::rgba::kRed, general::camera);

    return true;
}

bool u22::GameApplication::Release(void) {
    ReleaseSpriteSample();
    ReleaseSoundSample();
    return true;
}