#ifndef U22_ANIMATION_SPRITE_ANIMATION_CREATE_H
#define U22_ANIMATION_SPRITE_ANIMATION_CREATE_H


#include <vector>
#include <string>


namespace u22::animation {
struct SpriteAnimationCreatePattern {
    //! �t���[���E�F�C�g
    float wait = 0.0f;
    //! �p�^�[���ԍ�
    int no = 0;
    //! �p�^�[���i
    int step = 0;
};

class SpriteAnimationCreate {
private:
public:
    //!<�A�j���[�V������
    std::string name;
    //! X�I�t�Z�b�g�ʒu
    float offset_x;
    //! Y�I�t�Z�b�g�ʒu
    float offset_y;
    //! ��
    float width;
    //! ����
    float height;
    //! ���[�v�t���O
    bool loop;
    //!<�p�^�[��
    std::vector<SpriteAnimationCreatePattern> pattern;
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    //SpriteAnimationCreate();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    /// <param name="str"></param>
    /// <param name="x"></param>
    /// <param name="y"></param>
    /// <param name="w"></param>
    /// <param name="h"></param>
    /// <param name="l"></param>
    /// <param name="p"></param>
    //SpriteAnimationCreate(const char* str, float x, float y, float w, float h, bool l, std::vector<SpriteAnimationCreatePattern>& p);
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    //~SpriteAnimationCreate();
};
}
#endif // !U22_ANIMATION_SPRITE_ANIMATION_CREATE_H