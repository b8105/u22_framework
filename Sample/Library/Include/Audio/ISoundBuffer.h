#ifndef U22_AUDIO_ISOUND_BUFFER_H
#define U22_AUDIO_ISOUND_BUFFER_H


#include "../Common/Common.h"


namespace u22::audio {
class ISoundBuffer {
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    ISoundBuffer() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~ISoundBuffer() = default;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="volume"></param>
    virtual void SetVolume(float volume) = 0;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="pitch"></param>
    virtual void SetPitch(float pitch) = 0;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="loop"></param>
    virtual void SetLoop(bool loop) = 0;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsPlay(void) const = 0;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsPause(void) const = 0;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsEnd(void) const = 0;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path">�p�X</param>
    /// <returns></returns>
    virtual bool Load(const char* path) = 0;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) = 0;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) = 0;
    /// <summary>
    /// �Đ�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Play(void) = 0;
    /// <summary>
    /// ���f
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Pause(void) = 0;
    /// <summary>
    /// ��~
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Stop(void) const = 0;
    /// <summary>
    /// �����߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Rewind(void) = 0;
};
}
#endif // !U22_AUDIO_ISOUND_BUFFER_H