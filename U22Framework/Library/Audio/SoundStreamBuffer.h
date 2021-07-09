#ifndef U22_AUDIO_SOUND_STREAM_BUFFER_H
#define U22_AUDIO_SOUND_STREAM_BUFFER_H


#include <array>
#include <vector>

#include "ISoundBuffer.h"

#include "../Common/Common.h"

#include "AudioBuffer.h"
#include "SoundFile.h"


namespace u22::audio {
class SoundStreamBuffer : public u22::audio::ISoundBuffer {
private:
    //! �{�C�X
    ALuint _source;
    //! �o�b�t�@
    std::array<ALuint,2> _buffers;
    //! �f�[�^
    SNDFILE* _file;
    //! ���
    SF_INFO _info;
    //! �f�[�^
    std::vector<int> _stream_buffers[2];
    //! �Đ��ʒu
    sf_count_t _position;
    //! ����
    int _current;
    //! ��
    int _next;
    //! �I��
    bool _eof;
    //! �I���t���O
    bool _end;
    //! �t�H�[�}�b�g
    ALenum _format;
    //! �T�C�Y
    ALuint _buffer_size;
    //! int short�̔�
    std::uint32_t _byte_size_coefficient;
    //! ���[�v
    bool _loop;

    /// <summary>
    /// ���[�v����
    /// </summary>
    /// <param name=""></param>
    void Loop(void);
    /// <summary>
    /// ��������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ALuint WhiteNextData(ALuint buffer);
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="pitch"></param>
    virtual void SetPitch(float pitch) override;
    /// <summary>
    /// �����߂�
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Rewind(void) override;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SoundStreamBuffer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~SoundStreamBuffer();
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
#endif // !U22_AUDIO_SOUND_STREAM_BUFFER_H