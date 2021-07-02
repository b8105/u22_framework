#ifndef U22_UTILITY_GRAPHICS_UTILITIES_H
#define U22_UTILITY_GRAPHICS_UTILITIES_H


#include "../Graphics/FontRenderer.h"
#include "../Graphics/CircleRenderer.h"
#include "../Graphics/RectangleRenderer.h"


namespace u22::utility {
class GraphicsUtilities {
private:
    //! ����
    static u22::graphics::FontRenderer _font;
    //! �~
    static u22::graphics::CircleRenderer _circle;
    //! ��`
    static u22::graphics::RectangleRenderer _rectangle;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GraphicsUtilities() = default;
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~GraphicsUtilities() = default;
    /// <summary>
    /// �Z�b�g�A�b�v
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static bool Setup(void);
    /// <summary>
    /// �N���[���i�b�v
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    static bool Cleanup(void);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="position"></param>
    /// <param name="color"></param>
    /// <param name="text"></param>
    /// <param name="camera"></param>
    /// <returns></returns>
    static bool RenderString(const u22::math::Vector2F& position, const u22::math::Vector4F& color, const std::string& text, const u22::graphics::Camera& camera);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="circle"></param>
    /// <param name="color"></param>
    /// <param name="camera"></param>
    /// <returns></returns>
    static bool RenderLineCircle(const u22::shape::Circle& circle, const u22::math::Vector4F& color, const u22::graphics::Camera& camera);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="rectangle"></param>
    /// <param name="color"></param>
    /// <param name="camera"></param>
    /// <returns></returns>
    static bool RenderLineRectangle(const u22::shape::Rectangle& rectangle, const u22::math::Vector4F& color, const u22::graphics::Camera& camera);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="circle"></param>
    /// <param name="color"></param>
    /// <param name="camera"></param>
    /// <returns></returns>
    static bool RenderFillCircle(const u22::shape::Circle& circle, const u22::math::Vector4F& color, const u22::graphics::Camera& camera);
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name="rectangle"></param>
    /// <param name="color"></param>
    /// <param name="camera"></param>
    /// <returns></returns>
    static bool RenderFillRectangle(const u22::shape::Rectangle& rectangle, const u22::math::Vector4F& color, const u22::graphics::Camera& camera);
};
}
#endif // !U22_UTILITY_GRAPHICS_UTILITIES_H