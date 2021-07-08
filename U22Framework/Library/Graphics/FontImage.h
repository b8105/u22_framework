#ifndef U22_GRAPHICS_FONT_IMAGE_H
#define U22_GRAPHICS_FONT_IMAGE_H


#include <string>

#include "../Common/Common.h"


namespace u22::graphics {
class FontImage {
public:
    //! �I�t�Z�b�g
    int offset_x;
    //! �I�t�Z�b�g
    int	offset_y;
    //! �T�C�Y
    int	width;
    //! �T�C�Y
    int	height;
    //! �f�[�^
    uint8_t* pixels;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    FontImage();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~FontImage();
};
}
#endif // !U22_GRAPHICS_FONT_IMAGE_H