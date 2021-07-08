#ifndef U22_GRAPHICS_FONT_H
#define U22_GRAPHICS_FONT_H


#include <memory>
#include <string>

#include "../Common/Common.h"

#include "FontImage.h"


namespace u22::graphics {
class Font {
private:
    //! �p�X
    std::string _name;
    //! �t�H���g
    FT_Face _face;
    //! �T�C�Y
    FT_UInt _size;
    //! �X���b�g
    FT_GlyphSlot _slot;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Font();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Font();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    uint32_t GetSize(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name="path"></param>
    /// <param name=""></param>
    /// <returns></returns>
    bool Generate(const char* path, std::uint32_t size);
    /// <summary>
    /// �쐬
    /// </summary>
    /// <param name="text"></param>
    /// <returns></returns>
    std::shared_ptr<u22::graphics::FontImage> CreateFontImage(FT_ULong text) const;    
};
}
#endif // !U22_GRAPHICS_FONT_H