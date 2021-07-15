#ifndef U22_FRAMEWORK_IAPPLICAION_H
#define U22_FRAMEWORK_IAPPLICAION_H


namespace u22 {
class IApplicaion {
protected:
    /// <summary>
    /// �ݒ�
    /// </summary>
    /// <param name="name"></param>
    bool SetCurrentPath(const char* name = "Resource");
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    IApplicaion();
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    virtual ~IApplicaion();
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Initialize(void) = 0;
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Update(void) = 0;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Render(void) = 0;
    /// <summary>
    /// ���
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    virtual bool Release(void) = 0;
};
}
#endif // !U22_FRAMEWORK_IAPPLICAION_H