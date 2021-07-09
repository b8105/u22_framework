#ifndef U22_AUDIO_SOUND_BUFFER_H
#define U22_AUDIO_SOUND_BUFFER_H


#include "ISoundBuffer.h"

#include "../Common/Common.h"

#include "SoundFile.h"
#include "AudioBuffer.h"


namespace u22::audio {
class SoundBuffer : public u22::audio::ISoundBuffer {
private:
    //! �n���h��
    ALuint _id;
    //! �X�s�[�J�[
    ALuint _source;
    //! �t�@�C��
    u22::audio::SoundFile _file;
    //! ���[�v
    bool _loop;
    //! �I���t���O
    bool _end;
    /// <summary>
    /// �����߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Rewind(void) override;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="pitch"></param>
    virtual void SetPitch(float pitch) override;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SoundBuffer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~SoundBuffer();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="volume"></param>
    virtual void SetVolume(float volume) override;
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="loop"></param>
    virtual void SetLoop(bool loop) override;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsPlay(void) const override;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsPause(void) const override;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool IsEnd(void) const override;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path">�p�X</param>
    /// <returns></returns>
    virtual bool Load(const char* path) override;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) override;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) override;
    /// <summary>
    /// �Đ�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Play(void) override;
    /// <summary>
    /// ���f
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Pause(void) override;
    /// <summary>
    /// ��~
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Stop(void) const override;
};
}
#endif // !U22_AUDIO_SOUND_BUFFER_H