#ifndef U22_AUDIO_AUDIO_H
#define U22_AUDIO_AUDIO_H


#include "../Common/Common.h"


namespace u22::audio {
class Audio {
private:
    //! �f�o�C�X
    ALCdevice* _device;
    //! �R���e�L�X�g
    ALCcontext* _context;
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