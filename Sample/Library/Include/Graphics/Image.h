#ifndef U22_FRAMEWORK_IMAGE_H
#define U22_FRAMEWORK_IMAGE_H


#include "../Common/Common.h"


namespace u22::graphics {
class Image {
private:
    //! �f�[�^
    unsigned char* _pixels;
    //! �T�C�Y
    int _width;
    //! �T�C�Y
    int _height;
    //! �t�H�[�}�b�g
    int _internal_format;
    //! �t�H�[�}�b�g
    int _format;
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Image();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Image();
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�f�[�^</returns>
    unsigned char* GetPixel(void) const;
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
    /// <returns>�t�H�[�}�b�g</returns>
    int GetInternalFormat(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�t�H�[�}�b�g</returns>
    int GetFormat(void) const;
    /// <summary>
    /// �ǂݍ���
    /// </summary>
    /// <param name="path"></param>
    /// <returns></returns>
    bool Load(const char* path);
};
}
#endif // !U22_FRAMEWORK_IMAGE_H