/**
 * @file U22.h
 * @brief �e�@�\�̈ꊇ�C���N���[�h
 *        �g���₷���悤�ɃG�C���A�X�錾����
 * @author name
 * @date 2021/07/09
 */


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


/** @def
 * �t���[�����[�N���̃|�C���^�擾
 */
#define g_pFramework (u22::Framework::GetInfomation())
/** @def
 * �t���[�����[�N�������Ԃ̃|�C���^�擾
 */
#define g_pClock (u22::Framework::GetInfomation()->clock)
/** @def
 * �t���[�����[�N�����E�C���h�E�̃|�C���^�擾
 */
#define g_pWindow (u22::Framework::GetInfomation()->window)
/** @def
 * �t���[�����[�N�������͂̃|�C���^�擾
 */
#define g_pInput (u22::Framework::GetInfomation()->input)
/** @def
 * �t���[�����[�N�����O���t�B�b�N�X�̃|�C���^�擾
 */
#define g_pGraphics (u22::Framework::GetInfomation()->graphics)
/** @def
 * �t���[�����[�N�����I�[�f�B�I�̃|�C���^�擾
 */
#define g_pAidio (u22::Framework::GetInfomation()->aidio)

using namespace u22::utility;
using namespace u22::animation;

//!
//! ���͎��Ɉ����Ƃ��Ďg��
//!
using Keycode = u22::input::KeyCode;
//!
//! ���͎��Ɉ����Ƃ��Ďg��
//!
using MouseButton = u22::input::MouseButton;
//!
//! �v�f2�̃x�N�g��
//!
using Vector2 = u22::math::Vector2F;
//!
//! �v�f3�̃x�N�g��
//!
using Vector3 = u22::math::Vector3F;
//!
//! �v�f4�̃x�N�g��
//!
using Vector4 = u22::math::Vector4F;
//!
//! �Q�[���J����
//!
using CCamera = u22::graphics::Camera;
//!
//! �e�N�X�`���N���X�A�`��@�\������
//!
using CTexture = u22::graphics::TextureRenderer;
//!
//! �t�H���g�N���X�A�`��@�\������
//!
using CFont = u22::graphics::FontRenderer;
//!
//! �X�v���C�g�p�̃A�j���[�V����
//!
using CSpriteAnimationController = u22::animation::SpriteAnimationController;
//!
//! SE�p�̃T�E���h
//!
using CSoundBuffer = u22::audio::SoundBuffer;
//!
//! BGM�p�̃T�E���h
//!
using CSoundStreamBuffer = u22::audio::SoundStreamBuffer;
//!
//! �~�N���X�A�Փˋ@�\������
//!
using CCircle = u22::collision::CollisionableCircle;
//!
//! ��`�N���X�A�Փˋ@�\������
//!
using CRectangle = u22::collision::CollisionableRectangle;