/**
* @file SpriteAnimationController.h
* @brief 2D�̃A�j���[�V����
* @details �������`�͕`�掞�Ɏg�p����
*/


#ifndef U22_ANIMATION_SPRITE_MOTION_CONTROLLER_H
#define U22_ANIMATION_SPRITE_MOTION_CONTROLLER_H


#include <string>
#include <vector>
#include <unordered_map>

#include "../Shape/Rectangle.h"
#include "SpriteAnimationCreate.h"


namespace u22::animation {
/// <summary>
/// �A�j���[�V�����Ǘ��N���X
/// </summary>
class SpriteAnimationController {
private:
    //!
	//! ����
    //!
	float _ideal_frame_time;
	//!
	//! �I��
	//!
	bool _motion_end;
	//! ����
	float _time;
	//!
	//! �ԍ�
	//!
	uint32_t _current_motion_no;
	//!
	//! �ԍ�
	//!
	uint32_t _current_pattern_no;
	//!
	//! �\����`
	//!
	u22::shape::Rectangle _source_rectangle;
	//!
	//! ����
	//!
	u22::animation::SpriteAnimationCreate* _current_aniamtion;
	//!
	//! �A�j���[�V�����f�[�^
	//!
	std::unordered_map<int, u22::animation::SpriteAnimationCreate> _animations;
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SpriteAnimationController();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SpriteAnimationController();
	/// <summary>
	/// �Z�b�^�[
	/// </summary>
	/// <param name="loop">�t���O</param>
	void SetMotionLoop(bool loop);
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns>���݂̃��[�V�����ԍ�</returns>
	int GetMotionNo(void) const;
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns>���[�V�����̎�ނ̐�</returns>
	std::uint32_t GetMotionCount(void) const;
	/// <summary>
	/// �Q�b�^�[
	/// </summary>
	/// <param name=""></param>
	/// <returns>�`���`</returns>
	u22::shape::Rectangle GetSourceRectangle(void) const;
	/// <summary>
	/// ����
	/// </summary>
	/// <param name=""></param>
	/// <returns>�I��</returns>
	bool IsEndMotion(void) const;
	/// <summary>
	/// �X�V
	/// </summary>
	/// <param name="time">����</param>
	/// <returns>����</returns>
	bool AddTimer(float time);
	/// <summary>
	/// �ύX
	/// </summary>
	/// <param name="no"���[�V�����ԍ�></param>
	/// <returns>����</returns>
	bool ChangeMotion(int no);
	/// <summary>
	/// �ύX
	/// </summary>
	/// <param name="name">���[�V������</param>
	/// <returns>����</returns>
	bool ChangeMotion(const std::string& name);
	/// <summary>
	/// �쐬
	/// </summary>
	/// <param name="data">�������</param>
	/// <param name="size">�v�f��</param>
	/// <returns></returns>
	bool Create(u22::animation::SpriteAnimationCreate* data, int size);
	/// <summary>
	/// �쐬
	/// </summary>
	/// <param name="data">�������</param>
	/// <param name="size">�v�f��</param>
	/// <returns></returns>
	bool Create(const std::vector<u22::animation::SpriteAnimationCreate>& data, int size);
	/// <summary>
	/// ���
	/// </summary>
	/// <param name=""></param>
	/// <returns>����</returns>
	bool Release(void);
};
}
#endif // !U22_ANIMATION_SPRITE_MOTION_CONTROLLER_H