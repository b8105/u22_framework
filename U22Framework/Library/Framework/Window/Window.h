#ifndef U22_FRAMEWORK_WINDOW_WINDOW_H
#define U22_FRAMEWORK_WINDOW_WINDOW_H


#include "../../Common/Common.h"

#include <string>


namespace u22 {
class Window {
private:
    //! �E�C���h�E
    ::GLFWwindow* _handle;
    //! �^�C�g��
    std::string _title;
    //! �T�C�Y
    int _width;
    //! �T�C�Y
    int _height;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Window();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Window();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetHandle(::GLFWwindow* ptr);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    ::GLFWwindow* GetHandle(void);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetWidth(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    int GetHeight(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool ShouldClose(void);
    /// <summary>
    /// �쐬
    /// </summary>
    /// <param name="�^�C�g��"></param>
    /// <param name="width"></param>
    /// <param name="height"></param>
    /// <param name="pos_x"></param>
    /// <param name="pos_y"></param>
    /// <param name="full_screen"></param>
    /// <returns></returns>
    bool Create(const char* title, int width, int height, int pos_x, int pos_y, bool full_screen);
    /// <summary>
    /// �폜
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Destroy(void);
    /// <summary>
    /// �t���b�v
    /// </summary>
    void Present(void) const;
    /// <summary>
    /// �C�x���g�|�[�����O
    /// </summary>
    /// <param name=""></param>
    void PollEvents(void) const;
};
}
#endif // U22_FRAMEWORK_WINDOW_WINDOW_H