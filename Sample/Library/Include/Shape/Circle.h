#ifndef U22_SHAPE_CIRCLE_H
#define U22_SHAPE_CIRCLE_H


#include "../Math/Vector2.h"


namespace u22::shape {
class Circle {
public:
    union {
        struct {
            //! �ʒu
            float x;
            //! �ʒu
            float y;
        };
        struct {
            //! �ʒu
            u22::math::Vector2F position;
        };
    };
    //! ���a
    float radius;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Circle();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="x">x</param>
    /// <param name="y">y</param>
    /// <param name="r">���a</param>
    Circle(float x, float y, float r);
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="pos">�ʒu</param>
    /// <param name="r">���a</param>
    Circle(u22::math::Vector2F pos, float r);
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="translate"></param>
    /// <returns></returns>
    u22::shape::Circle operator+(const u22::math::Vector2F translate) const;
    /// <summary>
    /// �J��
    /// </summary>
    /// <param name="translate"></param>
    /// <returns></returns>
    u22::shape::Circle& operator+=(const u22::math::Vector2F translate);
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
};
}
#endif // !U22_SHAPE_CIRCLE_H