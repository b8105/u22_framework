#ifndef U22_FRAMEWORK_INPUT_INPUT_H
#define U22_FRAMEWORK_INPUT_INPUT_H


#include <memory>
#include <unordered_map>
#include <algorithm>

#include "../Framework/Window/Window.h"
#include "Keycode.h"


namespace u22::input {
class Input {
private:
    //! �E�C���h�E
    std::weak_ptr<u22::Window> _window;
    //! �L�[
    std::unordered_map<u22::input::KeyCode, bool> _previous_key_status;
    //! �L�[
    std::unordered_map<u22::input::KeyCode, bool> _cuurent_key_status;
    //! ���W
    double _mouse_x;
    //! ���W
    double _mouse_y;

    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Key"></typeparam>
    /// <typeparam name="Value"></typeparam>
    /// <param name="key"></param>
    /// <param name="map"></param>
    /// <returns>����</returns>
    template<typename Key, typename Value>
    bool Contain(Key key, const std::unordered_map<Key, Value>& map) const {
        auto it = map.find(key);
        if (it != map.end()) {
            return true;
        } // if
        return false;
    }
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Input();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Input();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetWindow(const std::shared_ptr<u22::Window>& ptr);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    float GetMouseX(void) const noexcept;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    float GetMouseY(void) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsPush(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsHold(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool IsPull(u22::input::KeyCode keycode) const noexcept;
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name="keycode"></param>
    /// <returns></returns>
    bool AddKey(u22::input::KeyCode keycode);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void Refresh(void);
};
}
#endif // !U22_FRAMEWORK_INPUT_INPUT_H