#ifndef U22_GRAPHICS_CAMERA_H
#define U22_GRAPHICS_CAMERA_H


#include "../Common/Common.h"
#include "../Math/Vector3.h"
#include "../Math/Matrix4x4.h"
#include "../Math/MathDefine.h"


namespace u22::graphics {
class Camera {
private:
    //! ���W�A��
    float _fovy;
    //! ��
    float _aspect;
    //! 臒l
    float _near;
    //! 臒l
    float _far;
    //! �ʒu
    u22::math::Vector3F _position;
    //! �Ώ�
    u22::math::Vector3F _target;
    //! ����
    u22::math::Vector3F _up;
    //! �r���[
    glm::mat4 _view_matrix;
    //! �ˉe
    glm::mat4 _projection_matrix;
    //! �r���[�ˉe
    glm::mat4 _view_projection;
    
    //! �r���[�ˉe
    u22::math::Matrix4x4F _mock;
    
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void UpdateOrtho(void);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void UpdatePerspective(void);
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    Camera();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~Camera();
    /// <summary>
    /// �Z�b�^�[
    /// </summary>
    /// <param name="pos"></param>
    void SetPosition(u22::math::Vector3F pos);
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    u22::math::Vector3F  GetPosition(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�r���[</returns>
    glm::mat4 GetViewMatrix(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�v���W�F�N�V����</returns>
    glm::mat4 GetProjectionMatrix(void) const;
    /// <summary>
    /// �Q�b�^�[
    /// </summary>
    /// <param name=""></param>
    /// <returns>�r���[�v���W�F�N�V����</returns>
    glm::mat4 GetViewProjectionMatrix(void) const;
    /// <summary>
    /// ������
    /// </summary>
    /// <param name=""></param>
    /// <returns></returns>
    bool Initalize2DCamera(void);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name=""></param>
    void Update(void);
    /// <summary>
    /// 
    /// </summary>
    /// <param name="width"></param>
    /// <param name="height"></param>
    void Create2D(int width, int height);
};
}
#endif // !U22_GRAPHICS_CAMERA_H