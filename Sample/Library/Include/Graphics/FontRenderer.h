#ifndef U22_GRAPHICS_FONT_RENDERER_H
#define U22_GRAPHICS_FONT_RENDERER_H


#include <memory>
#include <string>
#include <map>

#include "../Common/Common.h"

#include "../Math/Vector2.h"
#include "../Math/Vector4.h"
#include "../Shape/Rectangle.h"
#include "FontImage.h"
#include "Font.h"
#include "VertexArray.h"
#include "EffectShader.h"
#include "Texture.h"
#include "Camera.h"


namespace u22::graphics {
class FontRenderer {
private:
    //! �t�H���g
    std::shared_ptr<u22::graphics::Font> _font;
    //! ���_
    u22::graphics::VertexArray _vao;
    //! �V�F�[�_
    std::weak_ptr<u22::graphics::EffectShader> _shader;
    //! �e�N�X�`��
    std::shared_ptr<u22::graphics::Texture> _texture;
    //! �e�N�X�`��
    std::size_t _texture_size;
    //! �I�t�Z�b�g
    int _dest_offset_x;
    //! �I�t�Z�b�g
    int	_dest_offset_y;
    //! �]��
    int	_margin;
    //! �؂蔲���}�b�v
    std::map<std::string, u22::shape::Rectangle> _slices_map;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    bool IsCodeValid(const char s) const;
    /// <summary>
    /// �o�^
    /// </summary>
    /// <param name="str"></param>
    /// <returns></returns>
    bool RegisterCharacter(const char* str);
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
    /// �R���X�g���N�^
    /// </summary>
    FontRenderer();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FontRenderer();
    /// <summary>    
    /// �Z�b�^�[
    /// </summary>
    /// <param name="ptr"></param>
    void SetShader(const std::shared_ptr<u22::graphics::EffectShader>& ptr);
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path">�p�X</param>
    /// <param name="size">�T�C�Y</param>
    /// <returns></returns>
    bool Load(const char* path, uint32_t size = 16);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position">�E�C���h�E���W</param>
    /// <param name="color">�F���K��</param>
    /// <param name="text">������</param>
    /// <param name="text">�J����</param>
    /// <returns></returns>
    bool Render(const u22::math::Vector2F& position, const u22::math::Vector4F& color, const std::string& text, const u22::graphics::Camera& camera);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_GRAPHICS_FONT_RENDERER_H