#include "Input.h"


u22::input::Input::Input() :
    _window(),
    _previous_key_status(),
    _cuurent_key_status(),
    _mouse_x(),
    _mouse_y() {

    this->AddKey(KeyCode::Escape);
    this->AddKey(KeyCode::Space);
    this->AddKey(KeyCode::Up);
    this->AddKey(KeyCode::Down);
    this->AddKey(KeyCode::Right);
    this->AddKey(KeyCode::Left);
}

u22::input::Input::~Input() {
}

void u22::input::Input::SetWindow(const std::shared_ptr<u22::Window>& ptr) {
    this->_window = ptr;
}

float u22::input::Input::GetMouseX(void) const noexcept {
    return static_cast<float>(this->_mouse_x);
}

float u22::input::Input::GetMouseY(void) const noexcept {
    return static_cast<float>(this->_mouse_y);
}

bool u22::input::Input::IsPush(u22::input::KeyCode keycode) const noexcept {
    _ASSERT_EXPR(this->Contain(keycode, _previous_key_status), L"存在しないキーについて判定しようとしています");
    _ASSERT_EXPR(this->Contain(keycode, _cuurent_key_status), L"存在しないキーについて判定しようとしています");

    bool prev = _previous_key_status.at(keycode);
    bool now = _cuurent_key_status.at(keycode);
    return prev == false && now == true;
}

bool u22::input::Input::IsHold(u22::input::KeyCode keycode) const noexcept {
    _ASSERT_EXPR(this->Contain(keycode, _previous_key_status), L"存在しないキーについて判定しようとしています");
    _ASSERT_EXPR(this->Contain(keycode, _cuurent_key_status), L"存在しないキーについて判定しようとしています");

    bool prev = _previous_key_status.at(keycode);
    bool now = _cuurent_key_status.at(keycode);
    return prev == true && now == true;
}

bool u22::input::Input::IsPull(u22::input::KeyCode keycode) const noexcept {
    _ASSERT_EXPR(this->Contain(keycode, _previous_key_status), L"存在しないキーについて判定しようとしています");
    _ASSERT_EXPR(this->Contain(keycode, _cuurent_key_status), L"存在しないキーについて判定しようとしています");

    bool prev = _previous_key_status.at(keycode);
    bool now = _cuurent_key_status.at(keycode);
    return prev == true && now == false;
}
bool u22::input::Input::AddKey(u22::input::KeyCode keycode) {
    if (this->Contain(keycode, _previous_key_status) || this->Contain(keycode, _cuurent_key_status)) {
        return false;
    } // if

    _previous_key_status.emplace(keycode, 0);
    _cuurent_key_status.emplace(keycode, 0);
    return true;

}
void u22::input::Input::Refresh(void) {
    if (auto window = _window.lock()) {
        ::glfwGetCursorPos(window->GetHandle(), &_mouse_x, &_mouse_y);
        _mouse_x = std::clamp(static_cast<int>(_mouse_x), 0, window->GetWidth());
        _mouse_y = std::clamp(static_cast<int>(_mouse_y), 0, window->GetHeight());

        _previous_key_status = _cuurent_key_status;
        for (auto& state : _cuurent_key_status) {
            state.second = ::glfwGetKey(window->GetHandle(), input::ToRawCode(state.first));
        } // for
    } // if
}