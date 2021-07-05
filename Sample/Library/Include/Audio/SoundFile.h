#ifndef U22_AUDIO_SOUND_FILE_H
#define U22_AUDIO_SOUND_FILE_H


#include <vector>

#include "../Common/Common.h"


namespace u22::audio {
class SoundFile {
private:
    //! �f�[�^
    SNDFILE* _file;
    //! ���
    SF_INFO _info;
    //! �f�[�^
    std::vector<int> _data;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    SoundFile();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~SoundFile();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ALenum GetFormat(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    const void* GetData(void) const;
    /// <summary>::
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ALsizei GetSize(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ALsizei GetFrequency(void) const;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool Load(const char* path);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_AUDIO_SOUND_FILE_H