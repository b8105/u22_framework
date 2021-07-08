#ifndef U22_SHAPE_RECTANGLE_H
#define U22_SHAPE_RECTANGLE_H


#include "../Math/Vector2.h"


namespace u22::shape {
class Rectangle {
public:
    //! ��
    float left;
    //! ��
    float top;
    //! �E
    float right;
    //! ��
    float bottom;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Rectangle();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="l">��</param>
    /// <param name="t">��</param>
    /// <param name="r">�E</param>
    /// <param name="b">��</param>
    Rectangle(float l, float t, float r, float b);
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="lt">����</param>
    /// <param name="rb">�E��</param>
    Rectangle(u22::math::Vector2F lt, u22::math::Vector2F rb);
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="translate"></param>
    /// <returns></returns>
    Rectangle operator+(const u22::math::Vector2F translate);    
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="translate"></param>
    /// <returns></returns>
    Rectangle& operator+=(const u22::math::Vector2F translate);    
    /// <summary>
    /// �ݒ�
    /// </summary>
    /// <param name="pos_x">�ʒu</param>
    /// <param name="pos_y">�ʒu</param>
    /// <param name="width">�T�C�Y</param>
    /// <param name="height">�T�C�Y</param>
    void SetBounds(float pos_x, float pos_y, float width, float height);
    /// <summary>
    /// �ݒ�
    /// </summary>
    /// <param name="pos">�ʒu</param>
    /// <param name="size">�T�C�Y</param>
    void SetBounds(const u22::math::Vector2F& pos, const u22::math::Vector2F& size);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    float GetWidth(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    float GetHeight(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    u22::math::Vector2F GetSize(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    u22::math::Vector2F GetLeftTop(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�E��</returns>
    u22::math::Vector2F GetRightBottom(void) const;
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="x"></param>
    /// <param name="y"></param>
    void Translate(float x, float y);    
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="vector"></param>
    void Translate(const u22::math::Vector2F vector);    
    /// <summary>
    /// �g��
    /// </summary>
    /// <param name="value"></param>
    void Expansion(float value);
};
}
#endif // !U22_SHAPE_RECTANGLE_H