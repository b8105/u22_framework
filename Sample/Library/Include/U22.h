#include "Framework/FrameworkInclude.h"
#include "Math/MathInclude.h"
#include "Shape/ShapeInclude.h"
#include "Collision/CollisionInclude.h"
#include "Clock/Clock.h"
#include "Input/InputInclude.h"
#include "Graphics/GraphicsInclude.h"
#include "Audio/AudioInclude.h"
#include "Animation/AnimationInclude.h"
#include "Utility/UtilityInclude.h"


#define g_pFramework (u22::Framework::GetInfomation())
#define g_pClock (u22::Framework::GetInfomation()->clock)
#define g_pWindow (u22::Framework::GetInfomation()->window)
#define g_pInput (u22::Framework::GetInfomation()->input)
#define g_pGraphics (u22::Framework::GetInfomation()->graphics)
#define g_pAidio (u22::Framework::GetInfomation()->aidio)


using namespace u22::utility;
using namespace u22::animation;

using Keycode = u22::input::KeyCode;
using MouseButton = u22::input::MouseButton;
using Vector2 = u22::math::Vector2F;
using Vector3 = u22::math::Vector3F;
using Vector4 = u22::math::Vector4F;
using CCamera = u22::graphics::Camera;
using CTexture = u22::graphics::TextureRenderer;
using CFont = u22::graphics::FontRenderer;
using CSpriteAnimationController = u22::animation::SpriteAnimationController;
using CSoundBuffer = u22::audio::SoundBuffer;
using CSoundStreamBuffer = u22::audio::SoundStreamBuffer;
using CCircle = u22::collision::CollisionableCircle;
using CRectangle = u22::collision::CollisionableRectangle;