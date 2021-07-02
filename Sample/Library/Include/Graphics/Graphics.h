#ifndef U22_GRAPHICS_GRAPHICS_H
#define U22_GRAPHICS_GRAPHICS_H


#include "../Framework/Window/Window.h"

#include <memory>
#include <unordered_map>

#include "../Math/Vector4.h"
#include "GraphicsDefine.h"
#include "Camera.h"
#include "EffectShader.h"


namespace u22::graphics {
class Graphics {
private:
    //! ������
    bool _initialized;
    //! �V�F�[�_
    std::unordered_map<u22::graphics::EffectShaderType, std::shared_ptr<u22::graphics::EffectShader>> _shader_map;
     //! �t�H���g
    FT_Library _font;
    /// <summary>
    /// �Z�b�g�A�b�v
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Setup(void);
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool LoadShader(void);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool ReleaseShader(void);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Graphics();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Graphics();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    FT_Library GetFontPtr(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name="type"></param>
    /// <returns></returns>
    std::shared_ptr<u22::graphics::EffectShader> GetEffectShader(u22::graphics::EffectShaderType type) const;
    /// <summary>
    /// �N���A
    /// </summary>
    /// <param name="color">�F</param>
    /// <param name="depth">�[�x</param>
    /// <param name="stencil">�X�e���V��</param>
    void ClearTarget(const u22::math::Vector4F& color, float depth, float stencil);
    /// <summary>
    /// �`��J�n
    /// </summary>
    /// <param name=""></param>
    void RenderStart(void);
    /// <summary>
    /// ������
    /// </summary>
    /// <param name="window"></param>
    /// <returns></returns>
    bool Initialize(const std::shared_ptr<u22::Window>& window);
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Release(void);
};
}
#endif // !U22_GRAPHICS_GRAPHICS_H