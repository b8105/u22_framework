#ifndef U22_AUDIO_AUDIO_BUFFER_H
#define U22_AUDIO_AUDIO_BUFFER_H


#include "../Common/Common.h"

#include "SoundFile.h"


namespace u22::audio {
class AudioBuffer {
private:
    //! �n���h��
    ALuint _id;
    //! �X�s�[�J�[
    ALuint _source;
    //! �t�@�C��
    u22::audio::SoundFile _file;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    AudioBuffer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~AudioBuffer();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ALuint GetID(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool IsEnable(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Generate(void);
    /// <summary>
    /// �폜
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    bool Delete(void);
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path">�p�X</param>
    /// <returns></returns>
    //bool Load(const char* path);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    //bool Release(void);
    /// <summary>
    /// �Đ�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    //bool Play(void) const;
};
}
#endif // !U22_AUDIO_AUDIO_BUFFER_H