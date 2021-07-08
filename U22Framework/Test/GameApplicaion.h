#ifndef U22_TEST_GAME_APPLICATION_H
#define U22_TEST_GAME_APPLICATION_H


#include "../Library/U22.h"


namespace u22 {
class GameApplication : public u22::IApplicaion {
private:
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    GameApplication();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    virtual ~GameApplication();
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) override;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) override;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) override;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) override;
};
}
#endif // !U22_TEST_GAME_APPLICATION_H