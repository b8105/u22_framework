//#ifndef U22_GRAPHICS_ISHAPE_RENDERER_H
//#define U22_GRAPHICS_ISHAPE_RENDERER_H
//
//
//namespace u22::graphics {
//enum class ShapeRendererType {
//    LineCircle,
//    FillCircle,
//    LineRectangle,
//    FillRectangle,
//};
//class IShapeRenderer {
//private:
//public:
//    /// <summary>
//    /// �R���X�g���N�^
//    /// </summary>
//    IShapeRenderer() = default;
//    /// <summary>
//    /// �f�X�g���N�^
//    /// </summary>
//    virtual ~IShapeRenderer() = default;
//    /// <summary>
//    /// ������
//    /// </summary>
//    /// <param name=""></param>
//    /// <returns></returns>
//    virtual bool Initialize(void) = 0;
//    /// <summary>
//    /// �`��
//    /// </summary>
//    /// <typeparam name="Shape"></typeparam>
//    /// <param name="shape"></param>
//    /// <param name="color"></param>
//    /// <param name="camera"></param>
//    /// <returns></returns>
//    template<typename Shape>
//    bool Render(const Shape& shape, const u22::math::Vector4F& color, const u22::graphics::Camera& camera) const {
//        return true;
//    }
//};
//}
//#endif // !U22_GRAPHICS_ISHAPE_RENDERER_H