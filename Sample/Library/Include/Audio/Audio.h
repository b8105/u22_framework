#ifndef U22_AUDIO_AUDIO_H
#define U22_AUDIO_AUDIO_H


namespace u22::audio {
class Audio {
private:
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Audio();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Audio();
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initialize(void);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_AUDIO_AUDIO_H