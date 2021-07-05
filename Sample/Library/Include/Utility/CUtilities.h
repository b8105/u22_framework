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
    /// <summary>
    /// �����_���l
    /// </summary>
    /// <param name="min">�ŏ��l</param>
    /// <param name="max">�ő�l</param>
    /// <returns></returns>
    static int GenerateRandom(int min, int max);
    /// <summary>
    /// �����_���l
    /// </summary>
    /// <param name="min">�ŏ��l</param>
    /// <param name="max">�ő�l</param>
    /// <returns></returns>
    static float GenerateRandomF(float min, float max);
};
}
#endif // !U22_UTILITY_CUTILITIES_H