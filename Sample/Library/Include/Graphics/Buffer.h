#ifndef U22_GRAPHICS_BUFFER_H
#define U22_GRAPHICS_BUFFER_H


#include "../Common/Common.h"


namespace u22::graphics {
class Buffer {
private:
    //! �n���h��
    GLuint _id;
    //! �^�C�v
    GLenum _type;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Buffer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Buffer();
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="type">���</param>
    /// <param name="size">�T�C�Y</param>
    /// <param name="data">�f�[�^</param>
    /// <param name="usage">�g����</param>
    /// <returns>����</returns>
    bool Generate(GLenum type, GLsizeiptr size, const void* data, GLenum usage);
    /// <summary>
    /// �T�u�Z�b�g���X�V
    /// </summary>
    /// <param name="offset">�I�t�Z�b�g</param>
    /// <param name="size">�T�C�Y</param>
    /// <param name="data">�f�[�^</param>
    void SubsetUpdate(GLintptr offset, GLsizeiptr size, const void* data) const;
    /// <summary>
    /// �폜
    /// </summary>
    /// <param name=""></param>
    void Delete(void);
    /// <summary>
    /// �g�p
    /// </summary>
    /// <param name=""></param>
    void Bind(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    void UnBind(void) const;
};
}
#endif // !U22_GRAPHICS_BUFFER_H