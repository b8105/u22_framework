#ifndef U22_UTILITY_CUTILITIES_H
#define U22_UTILITY_CUTILITIES_H


namespace u22::utility {
class CUtilities {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    CUtilities() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~CUtilities() = default;
    /// <summary>
    /// �t���[��������̎���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static float GetFrameSecond(void);
    /// <summary>
    /// FPS
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static float GetFPS(void);
};
}
#endif // !U22_UTILITY_CUTILITIES_H