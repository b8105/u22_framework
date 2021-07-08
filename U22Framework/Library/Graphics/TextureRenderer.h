#ifndef U22_GRAPHICS_TEXTURE_RENDERER_H
#define U22_GRAPHICS_TEXTURE_RENDERER_H


#include <memory>

#include "../Math/Vector2.h"
#include "../Math/Matrix4x4.h"
#include "../Shape/Rectangle.h"
#include "VertexArray.h"
#include "EffectShader.h"
#include "Texture.h"
#include "Camera.h"


namespace u22::graphics {
class TextureRenderer {
private:
    //! ���_
    u22::graphics::VertexArray _vao;
    //! �V�F�[�_
    std::weak_ptr<u22::graphics::EffectShader> _shader;
    //! �e�N�X�`��
    std::shared_ptr<u22::graphics::Texture> _texture;
    /// <summary>
    /// �]��
    /// </summary>
    /// <param name="shader"></param>
    /// <param name="uniform_rectangle"></param>
    /// <param name="uniform_color"></param>
    /// <param name="model_transform"></param>
    /// <param name="camera"></param>
    void TransferUniform(const std::shared_ptr<u22::graphics::EffectShader>& shader, const u22::shape::Rectangle& uniform_rectangle, const u22::math::Vector4F& uniform_color, const u22::math::Matrix4x4F& model_transform, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    void Draw(void) const;
public:
    /// <summary>    
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetShader(const std::shared_ptr<u22::graphics::EffectShader>& ptr);
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
    /// �ǂݍ���
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool Load(const char* path);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool Render(const u22::math::Vector2F& position, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="position">�F</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool Render(const u22::math::Vector2F& position, const u22::math::Vector4F& color, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="rectangle">�\����`</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool Render(const u22::math::Vector2F& position, const u22::shape::Rectangle& rectangle, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="rectangle">�\����`</param>
    /// <param name="rectangle">�F</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool Render(const u22::math::Vector2F& position, const u22::shape::Rectangle& rectangle, const u22::math::Vector4F& color, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="rotate">���W�A��</param>
    /// <param name="camera">�J����</param>
    /// <param name="axis">��</param>
    /// <returns></returns>
    bool RenderRotate(const u22::math::Vector2F& position, float rotate, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="rotate">���W�A��</param>
    /// <param name="rectangle">�\����`</param>
    /// <param name="camera">�J����</param>
    /// <param name="axis">��</param>
    /// <returns></returns>
    bool RenderRotate(const u22::math::Vector2F& position, float rotate, const u22::shape::Rectangle& rectangle, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="scale">�g�嗦</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool RenderScale(const u22::math::Vector2F& position, float scale, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�X�N���[�����W</param>
    /// <param name="scale">�g�嗦</param>
    /// <param name="rectangle">�\����`</param>
    /// <param name="camera">�J����</param>
    /// <returns></returns>
    bool RenderScale(const u22::math::Vector2F& position, float scale, const u22::shape::Rectangle& rectangle, const u22::graphics::Camera& camera) const;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_GRAPHICS_TEXTURE_RENDERER_H