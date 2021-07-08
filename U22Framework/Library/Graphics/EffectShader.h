#ifndef U22_GRAPHICS_EFFECT_SHADER_H
#define U22_GRAPHICS_EFFECT_SHADER_H


#include "../Common/Common.h"

#include "../Math/Vector2.h"
#include "../Math/Vector4.h"
#include "../Math/Matrix4x4.h"


namespace u22::graphics {
class EffectShader {
private:
    GLuint _vertex_id;
    GLuint _fragment_id;
    //! �V�F�[�_�n���h��
    GLuint _id;
    //! ���j�t�H�[���n���h��
    GLuint _uniform_handle;

    /// <summary>
    /// �R���p�C��
    /// </summary>
    /// <param name="path"></param>
    /// <param name="out"></param>
    /// <returns></returns>
    bool Compile(const char* path, GLuint& out);
    bool Check(const GLuint id, const GLenum type);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    EffectShader();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~EffectShader();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    GLuint GetID(void) const;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="vert_path">�p�X</param>
    /// <param name="frag_path">�p�X</param>
    /// <returns>����</returns>
    bool Load(const char* vert_path, const char* frag_path);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
    /// <summary>
    /// �]��
    /// </summary>
    /// <param name="name"></param>
    /// <param name="value"></param>
    void TransferUniform(const char* name, const float& value);
    /// <summary>
    /// �]��
    /// </summary>
    /// <param name="name"></param>
    /// <param name="vector2"></param>
    void TransferUniform(const char* name, const u22::math::Vector2F& vector2);
    /// <summary>
    /// �]��
    /// </summary>
    /// <param name="name"></param>
    /// <param name="vector4"></param>
    void TransferUniform(const char* name, const u22::math::Vector4F& vector4);
    /// <summary>
    /// �]��
    /// </summary>
    /// <param name="name"></param>
    /// <param name="matrix"></param>
    /// <param name="transpose"></param>
    void TransferUniform(const char* name, const glm::mat4& matrix, bool transpose = false);
    /// <summary>
    /// �ǉ�
    /// </summary>
    /// <param name=""></param>
    void Attach(void);
    /// <summary>
    /// �����N
    /// </summary>
    /// <param name=""></param>
    void Link(void);
    //bool GenerateUniformBuffer(const char* name, std::size_t size, void* data);
    //bool BindUniformBuffer(const char* name, std::size_t size, void* data);
    /// <summary>
    /// �L����
    /// </summary>
    /// <param name=""></param>
    void Enable(void);
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    void Disable(void);
};
}
#endif // !U22_GRAPHICS_EFFECT_SHADER_H