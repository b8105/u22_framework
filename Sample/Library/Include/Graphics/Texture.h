#ifndef U22_GRAPHICS_TEXTURE_H
#define U22_GRAPHICS_TEXTURE_H


#include "../Common/Common.h"

#include <string>

#include "../Math/Vector2.h"


namespace u22::graphics {
class Texture {
private:
    //! �n���h��
    GLuint _id;
    //! ���O
    std::string _name;
    //! �T�C�Y
    u22::math::Vector2I _size;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Texture();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Texture();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    GLuint GetID(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    int GetWidth(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    int GetHeight(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�T�C�Y</returns>
    u22::math::Vector2I GetSize(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Generate(void);
    /// <summary>
    /// �ݒ�
    /// </summary>
    /// <param name="width">�T�C�Y</param>
    /// <param name="height">�T�C�Y</param>
    /// <returns></returns>
    bool TextureMapping(int width, int height);
    /// <summary>
    /// ��������
    /// </summary>
    /// <param name="offset_x">�I�t�Z�b�g</param>
    /// <param name="offset_y">�I�t�Z�b�g</param>
    /// <param name="width">�T�C�Y</param>
    /// <param name="height">�T�C�Y</param>
    /// <param name="pixels">�f�[�^</param>
    /// <returns></returns>
    bool SubImageUpdate(GLint offset_x, GLint offset_y, GLint width, GLint height, const void* pixels);
    /// <summary>
    /// �g�p
    /// </summary>
    /// <param name="index"></param>
    void Bind(uint32_t index = 0) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    void UnBind(void) const;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path">�p�X</param>
    /// <returns>����</returns>
    bool Load(const char* path);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_GRAPHICS_TEXTURE_H