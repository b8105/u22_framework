#ifndef U22_FRAMEWORK_FRAMEWORK_H
#define U22_FRAMEWORK_FRAMEWORK_H


#include <memory>

#include "../Common/Common.h"

#include "../Clock/Clock.h"
#include "Window/Window.h"
#include "../Input/Input.h"
#include "../Graphics/Graphics.h"
#include "../Audio/Audio.h"
#include "IApplicaion.h"


namespace u22 {
struct ApplicationInfo {
    //! �ʒu
    int window_position_x ;
    //! �ʒu
    int window_position_y ;
    //! �T�C�Y
    int window_width ;
    //! �T�C�Y
    int window_height;
    //! �t���X�N���[��
    bool full_screen_mode;
};
struct FrameworkInfo {
public:
    //! �N���b�N
    std::shared_ptr<u22::clock::Clock> clock;
    //! �E�C���h�E
    std::shared_ptr<u22::Window> window;
    //! �C���v�b�g
    std::shared_ptr<u22::input::Input> input;
    //! �O���t�B�b�N�X
    std::shared_ptr<u22::graphics::Graphics> graphics;
    //! �I�[�f�B�I
    std::shared_ptr<u22::audio::Audio> audio;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FrameworkInfo() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FrameworkInfo() = default;

    std::shared_ptr<u22::Window> GetWindow(void) const {
        return this->window;
    }
};
class Framework {
private:
    //! �\�����
    static u22::FrameworkInfo _infomation;
    //! �N���b�N
    std::shared_ptr<u22::clock::Clock> _clock;
    //! �E�C���h�E
    std::shared_ptr<u22::Window> _window;
    //! �C���v�b�g
    std::shared_ptr<u22::input::Input> _input;
    //! �O���t�B�b�N�X
    std::shared_ptr<u22::graphics::Graphics> _graphics;
    //! �I�[�f�B�I
    std::shared_ptr<u22::audio::Audio> _audio;
    //! �A�v���P�[�V����
    std::shared_ptr<u22::IApplicaion> _applicaion;
public:
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static u22::FrameworkInfo* GetInfomation(void);
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Framework();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Framework();
    /// <summary>
    /// �Z�b�g�A�b�v
    /// </summary>
    /// <param name="ptr"></param>
    /// <param name="info"></param>
    /// <returns></returns>
    bool Setup(const std::shared_ptr<u22::IApplicaion>& ptr, u22::ApplicationInfo* info);
    /// <summary>
    /// ���s
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    int Run(void);
    /// <summary>
    /// �N���[���i�b�v
    /// </summary>
    /// <param name=""></param>
    /// <returns>����</returns>
    bool Cleanup(void);
};
}
#endif // !U22_FRAMEWORK_FRAMEWORK_H