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


#define g_pClock (u22::Framework::GetInfomation().clock)
#define g_pWindow (u22::Framework::GetInfomation().window)
#define g_pInput (u22::Framework::GetInfomation().input)
#define g_pGraphics (u22::Framework::GetInfomation().graphics)
#define g_pAidio (u22::Framework::GetInfomation().aidio)


using namespace u22;
using namespace u22::animation;
using namespace u22::utility;

using Vector2 = math::Vector2F;
using Vector3 = math::Vector3F;
using Vector4 = math::Vector4F;
using CTexture = graphics::TextureRenderer;
using CFont = graphics::FontRenderer;
using CCircle = u22::collision::CollisionableCircle;
using CRectangle = u22::collision::CollisionableRectangle;
//using SoundBuffer = audio::Buffer;