#ifndef U22_COLLISION_CIRCLE_COLLISION_DETECTOR_H
#define U22_COLLISION_CIRCLE_COLLISION_DETECTOR_H


#include <cmath>

#include "../Shape/Circle.h"
#include "../Shape/Rectangle.h"


namespace u22::collision {
class CircleCollisionDetector {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CircleCollisionDetector();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    ~CircleCollisionDetector();
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="a">�~</param>
    /// <param name="b">�~</param>
    /// <returns>�Փ�</returns>
    bool CollisionCircle(const u22::shape::Circle& a, const u22::shape::Circle& b) const;
};
}
#endif // !U22_COLLISION_CIRCLE_COLLISION_DETECTOR_H