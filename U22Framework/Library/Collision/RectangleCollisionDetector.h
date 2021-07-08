#ifndef U22_COLLISION_RECTANGLE_COLLISION_DETECTOR_H
#define U22_COLLISION_RECTANGLE_COLLISION_DETECTOR_H


#include <cmath>

#include "../Shape/Circle.h"
#include "../Shape/Rectangle.h"


namespace u22::collision {
class RectangleCollisionDetector {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    RectangleCollisionDetector();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    ~RectangleCollisionDetector();
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="a">��`</param>
    /// <param name="b">��`</param>
    /// <returns>�Փ�</returns>
    bool CollisionRectangle(const u22::shape::Rectangle& a, const u22::shape::Rectangle& b) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="a">��`</param>
    /// <param name="b">�~</param>
    /// <returns>�Փ�</returns>
    bool CollisionCircle(const u22::shape::Rectangle& rect, const u22::shape::Circle& circle) const;
};
}
#endif // !U22_COLLISION_RECTANGLE_COLLISION_DETECTOR_H