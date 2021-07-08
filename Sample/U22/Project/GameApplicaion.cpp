#include "GameApplicaion.h"


//! 0.0f ~ 1.0f の値が入る
//! テクスチャの画像の色に掛ける値
Vector4 _color_rgba = Vector4(1.0f, 1.0f, 1.0f, 1.0f);

Vector3 _position;
CCamera _camera;
CTexture _texture;
CSpriteAnimationController _motion;
CSoundStreamBuffer _bgm;
CSoundBuffer _se;



void InpuTest(void) {
    if (g_pInput->IsPush(MouseButton::Left)) {
        puts("g_pInput->IsPush(Keycode::MouseLeft)");
    } // if
    if (g_pInput->IsHold(MouseButton::Right)) {
        puts("g_pInput->IsHold(Keycode::MouseRight)");
    } // else if

    if (g_pInput->IsPush(Keycode::A)) {
        puts("g_pInput->IsPush(Keycode::A)");
    } // if
    else if (g_pInput->IsHold(Keycode::A)) {
        //puts("g_pInput->IsHold(Keycode::A)");
    } // else if
    else if (g_pInput->IsPull(Keycode::A)) {
        puts("g_pInput->IsPull(Keycode::A)");
    } // else if

}

u22::GameApplication::GameApplication() {
}

u22::GameApplication::~GameApplication() {
}

bool u22::GameApplication::Initialize(void) {
    SetCurrentPath();
    _camera.Initalize2DCamera();
    _position = Vector3(100.0f, 100.0f, 0.0f);

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

    //_sound.Load("se/se_enter.wav");
    //_sound.Load("bgm/shiningstar.ogg");
    //_sound.Load("bgm/harapeko_march.wav");
    //_bgm.Load("bgm/harapeko_march.wav");
    
    _se.Load("se/se_enter.wav");
    _se.SetVolume(1.0f);
    _bgm.Load("bgm/shiningstar.ogg");
    _bgm.SetLoop(true);
    return true;
}

bool u22::GameApplication::Update(void) {
    // マウスインプットテスト
    InpuTest();

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


    // ウインドウサイズ取得
    int width = g_pFramework->GetWindow()->GetWidth();
    int height  = g_pFramework->GetWindow()->GetHeight();

    if (g_pInput->IsHold(u22::input::KeyCode::Escape)) {
        ::PostQuitMessage(0);
    } // if

    if (g_pInput->IsPush(u22::input::KeyCode::Left)) {
        _position.x -= 10.0f;
        _motion.ChangeMotion(5);
        _se.Play();
    } // if
    else if (g_pInput->IsPush(u22::input::KeyCode::Right)) {
        _position.x += 10.0f;
        _motion.ChangeMotion("ジャンプ開始");
        _bgm.SetVolume(0.1f);
    } // else if
    if (g_pInput->IsPush(u22::input::KeyCode::Up)) {
        _position.y--;
        _motion.ChangeMotion(4);
        _bgm.Play();
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
    if (_bgm.IsEnd()) {
    } // if
    _motion.AddTimer(g_pClock->GetFrameSecond());

    _bgm.Update();
    return true;
}

bool u22::GameApplication::Render(void) {
    g_pGraphics->RenderStart();
    g_pGraphics->ClearTarget(color::rgba::kBlue, 1.0f, 1.0f);

    auto circle = u22::shape::Circle(300.0f, 300.0f, 64.0f);
    ::GraphicsUtilities::RenderLineCircle(circle, color::rgba::kRed, _camera);

    CRectangle rect = _motion.GetSourceRectangle();
    ::GraphicsUtilities::RenderFillRectangle(rect, color::rgba::kRed, _camera);
    
    _texture.Render(_position, rect, _color_rgba, _camera);
    //_texture.Render(_position, rect, color::rgba::kRed, _camera);
    //_texture.Render(_position, rect, color::rgba::kGreen, _camera);
    //_texture.Render(_position, rect, color::rgba::kBlue, _camera);
    //_texture.Render(_position, rect, color::rgba::kBlack, _camera);
    //_texture.Render(_position, rect, color::rgba::kBlue, _camera);
    //_texture.Render(_position, rect, _color_rgba, _camera);
    //_texture.Render(_position, rect, _color_rgba, _camera);
    //_texture.Render(_position, rect, _color_rgba, _camera);
    
    
    rect.SetBounds(_position, rect.GetSize());

    auto color = Vector4(0.0f, 0.0f, 0.0f, 0.5f);
    if (rect.CollisionCircle(circle)) {
        color = Vector4(0.0f, 0.0f, 0.0f, 1.0f);
    } // if
    ::GraphicsUtilities::RenderFillCircle(circle, color, _camera);
    ::GraphicsUtilities::RenderLineRectangle(rect, color::rgba::kRed, _camera);

    std::string text = "";
    text += "FPS = ";
    text += std::string(std::to_string(::CUtilities::GetFPS()));

    ::GraphicsUtilities::RenderString(math::vec3::kZero, color::rgba::kWhite, text, _camera);
    ::GraphicsUtilities::RenderString(u22::math::Vector3F(500.0f, 200.0f, 0.0f), color::rgba::kRed, text, _camera);
    return true;
}

bool u22::GameApplication::Release(void) {
    _texture.Release();
    _se.Release();
    _bgm.Release();
    return true;
}