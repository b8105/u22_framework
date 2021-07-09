#include "GameApplicaion.h"


namespace general {
CCamera camera;
int test_no = -1;
int test_count = 2;
Vector2 mouse_position = Vector2();
CCircle mouse_circle = CCircle();
Vector2 size = Vector2(192.0f, 64.0f);
int margin = 8;
std::string name = "SampleNo=";
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
}


void Input(void) {
    general::mouse_position.x = g_pInput->GetMouseX();
    general::mouse_position.y = g_pInput->GetMouseY();
    general::mouse_circle = CCircle(general::mouse_position, 10.0f);

    if (g_pInput->IsPush(Keycode::Key0)) {
        general::test_no = 0;
    } // if
    else if (g_pInput->IsPush(Keycode::Key1)) {
        general::test_no = 1;
    } // else if
    else if (g_pInput->IsPush(Keycode::Key2)) {
        general::test_no = 1;
    } // else if
}
bool InitializeSpriteSample(void) {
    using namespace sprite_sample;

    _position = Vector3(100.0f, 100.0f, 0.0f);

    if (!_texture.Load("../Resource/texture/player.png")) {
        if (!_texture.Load("Resource/texture/player.png")) {
            return false;
        } // if
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

    if (!_se.Load("../Resource/se/se_enter.wav")) {
        _se.Load("Resource/se/se_enter.wav");
    } // 
    _se.SetVolume(1.0f);
    
    if (!_bgm.Load("../Resource/bgm/shiningstar.ogg")) {
        _bgm.Load("Resource/bgm/shiningstar.ogg");
    } // if
    _bgm.SetLoop(true);
    return true;
}

bool UpdateSpriteSample(void) {
    using namespace sprite_sample;


    // テクスチャの色変更
    float c = 0.1f;
    if (g_pInput->IsHold(Keycode::R)) {
        if (g_pInput->IsHold(Keycode::Space)) {
            _color_rgba.r += c;
        } // if
        else {
            _color_rgba.r -= c;
        } // else 
        _color_rgba.r = std::clamp(_color_rgba.r, 0.0f, 1.0f);
    } // if
    if (g_pInput->IsHold(Keycode::G)) {
        if (g_pInput->IsHold(Keycode::Space)) {
            _color_rgba.g += c;
        } // if
        else {
            _color_rgba.g -= c;
        } // else 
        _color_rgba.g = std::clamp(_color_rgba.g, 0.0f, 1.0f);
    } // if
    if (g_pInput->IsHold(Keycode::B)) {
        if (g_pInput->IsHold(Keycode::Space)) {
            _color_rgba.b += c;
        } // if
        else {
            _color_rgba.b -= c;
        } // else 
        _color_rgba.b = std::clamp(_color_rgba.b, 0.0f, 1.0f);
    } // if
    if (g_pInput->IsHold(Keycode::A)) {
        if (g_pInput->IsHold(Keycode::Space)) {
            _color_rgba.a += c;
        } // if
        else {
            _color_rgba.a -= c;
        } // else 
        _color_rgba.a = std::clamp(_color_rgba.a, 0.0f, 1.0f);
    } // if


    if (g_pInput->IsPush(u22::input::KeyCode::Left)) {
        _position.x -= 10.0f;
        _motion.ChangeMotion(5);
    } // if
    else if (g_pInput->IsPush(u22::input::KeyCode::Right)) {
        _position.x += 10.0f;
        _motion.ChangeMotion("ジャンプ開始");
    } // else if
    if (g_pInput->IsPush(u22::input::KeyCode::Up)) {
        _position.y--;
        _motion.ChangeMotion(4);
    } // if
    else if (g_pInput->IsHold(u22::input::KeyCode::Down)) {
        _position.y += 20.0f;
        _motion.ChangeMotion(1);
    } // else if
    if (_motion.IsEndMotion()) {
        if (_motion.GetMotionNo() == 2) {
            _motion.ChangeMotion(3);
        } // if
    } // if


    _motion.AddTimer(g_pClock->GetFrameSecond());

    return true;
}

bool UpdateSoundSample(void) {
    using namespace sound_sample;

    if (g_pInput->IsPush(u22::input::KeyCode::Left)) {
        _se.Play();
    } // if
    else if (g_pInput->IsPush(u22::input::KeyCode::Right)) {
        _bgm.SetVolume(0.1f);
    } // else if
    if (g_pInput->IsPush(u22::input::KeyCode::Up)) {
        _bgm.Play();
    } // if

    _bgm.Update();
    return true;
}

bool RenderSpriteSample(void) {
    using namespace general;
    using namespace sprite_sample;


    auto circle = u22::shape::Circle(300.0f, 300.0f, 64.0f);
    ::GraphicsUtilities::RenderLineCircle(circle, color::rgba::kRed, camera);

    CRectangle rect = _motion.GetSourceRectangle();
    ::GraphicsUtilities::RenderFillRectangle(rect, color::rgba::kRed, camera);

    _texture.Render(_position, rect, _color_rgba, camera);
    rect.SetBounds(_position, rect.GetSize());

    auto color = Vector4(0.0f, 0.0f, 0.0f, 0.5f);
    if (rect.CollisionCircle(circle)) {
        color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    } // if
    ::GraphicsUtilities::RenderFillCircle(circle, color, camera);
    ::GraphicsUtilities::RenderLineRectangle(rect, color::rgba::kRed, camera);
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
    return true;
}

bool u22::GameApplication::Render(void) {
    g_pGraphics->RenderStart();
    g_pGraphics->ClearTarget(color::rgba::kBlue, 1.0f, 1.0f);

    std::string text = "";
    text += "FPS = ";
    text += std::string(std::to_string(::CUtilities::GetFPS()));
    text += "\n";
    text += general::name;
    text += std::string(std::to_string(general::test_no));
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
            //RenderSoundSample();
            break;
        default:
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