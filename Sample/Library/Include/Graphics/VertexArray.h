#ifndef U22_GRAPHICS_VERTEX_ARRAY_H
#define U22_GRAPHICS_VERTEX_ARRAY_H


#include <vector>

#include "../Common/Common.h"

#include "Vertex.h"
#include "Buffer.h"


namespace u22::graphics {
class VertexArray {
private:
    //! �n���h��
    GLuint _id;
    //! �g�|���W�[
    GLenum _topology;
    //! �o�[�e�b�N�X
    u22::graphics::Buffer _vertex;
    //! �C���f�b�N�X
    u22::graphics::Buffer _index;
    //! �C���f�b�N�X�T�C�Y
    std::uint32_t _indices_size;

    template <typename Vertex>
    void EnablePosition(int slot) {
        ::glEnableVertexAttribArray(slot);
        ::glVertexAttribPointer(slot, sizeof(Vertex::position) / sizeof(float), GL_FLOAT,
                                GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(offsetof(Vertex, Vertex::position)));
    }
    template <typename Vertex>
    void EnableColor(int slot) {
        ::glEnableVertexAttribArray(slot);
        ::glVertexAttribPointer(slot, sizeof(Vertex::color) / sizeof(float), GL_FLOAT,
                                GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(offsetof(Vertex, Vertex::color)));
    }
    template <typename Vertex>
    void EnableTexcoord(int slot) {
        ::glEnableVertexAttribArray(slot);
        ::glVertexAttribPointer(slot, sizeof(Vertex::texcoord) / sizeof(float), GL_FLOAT,
                                GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(offsetof(Vertex, Vertex::texcoord)));
    }
public:
    /// <summary>
    /// �R���X�g���N�^
    /// </summary>
    VertexArray();
    /// <summary>
    /// �f�X�g���N�^
    /// </summary>
    ~VertexArray();
    /// <summary>
    /// ����
    /// </summary>
    /// <typeparam name="Vertex">�^</typeparam>
    /// <param name="vertices">�o�[�e�b�N�X</param>
    /// <param name="indices">�C���f�b�N�X</param>
    /// <returns>����</returns>
    template<typename Vertex>
    bool Generate(const std::vector<Vertex>& vertices, const std::vector<std::uint32_t>& indices) {
    }
    template<>
    bool Generate<u22::graphics::ColorVertex>(const std::vector<u22::graphics::ColorVertex>& vertices, const std::vector<std::uint32_t>& indices) {
        using Vertex = u22::graphics::ColorVertex;
        _indices_size = indices.size();

        ::glGenVertexArrays(1, &_id);
        this->Bind();
        if (!_vertex.Generate(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(),
                              vertices.data(), GL_STREAM_DRAW)) {
            return false;
        } // if
        if (!_index.Generate(GL_ELEMENT_ARRAY_BUFFER, sizeof(std::uint32_t) * indices.size(),
                             indices.data(), GL_STATIC_DRAW)) {
            return false;
        } // if

        int pos = 0; int color = 1;
        this->EnablePosition<Vertex>(pos);
        this->EnableColor<Vertex>(color);

        this->UnBind();
        _vertex.UnBind();
        _index.UnBind();
        return true;
    }
    template<>
    bool Generate<u22::graphics::SpriteVertex>(const std::vector<u22::graphics::SpriteVertex>& vertices, const std::vector<std::uint32_t>& indices) {
        using Vertex = u22::graphics::SpriteVertex;
        _indices_size = indices.size();

        ::glGenVertexArrays(1, &_id);
        this->Bind();
        if (!_vertex.Generate(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(),
                              vertices.data(), GL_STREAM_DRAW)) {
            return false;
        } // if
        if (!_index.Generate(GL_ELEMENT_ARRAY_BUFFER, sizeof(std::uint32_t) * indices.size(),
                             indices.data(), GL_STATIC_DRAW)) {
            return false;
        } // if

        int pos = 0; int texcoord = 1;
        this->EnablePosition<Vertex>(pos);
        this->EnableTexcoord<Vertex>(texcoord);

        this->UnBind();
        _vertex.UnBind();
        _index.UnBind();
        return true;
    }

    /// <summary>
    /// �폜
    /// </summary>
    /// <param name=""></param>
    void Delete(void);
    /// <summary>
    /// �g�p
    /// </summary>
    /// <param name=""></param>
    void Bind(void) const;
    /// <summary>
    /// ����
    /// </summary>
    /// <param name=""></param>
    void UnBind(void) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    void DrawElements(void) const;
    /// <summary>
    /// �`��
    /// </summary>
    /// <param name=""></param>
    void DrawElementsInstanced(uint32_t count) const;
    /// <summary>
    /// �g�|���W�[��LINES�ɂ���
    /// </summary>
    /// <param name=""></param>
    void ToLines(void);
    /// <summary>
    /// �g�|���W�[��LINE_STRIP�ɂ���
    /// </summary>
    /// <param name=""></param>
    void ToLineStrip(void);
    /// <summary>
    /// �g�|���W�[��TRIANGLES�ɂ���
    /// </summary>
    /// <param name=""></param>
    void ToTriangles(void);
    /// <summary>
    /// �g�|���W�[��TRIANGLE_STRIP�ɂ���
    /// </summary>
    /// <param name=""></param>
    void ToTriangleStrip(void);
    /// <summary>
    /// �X�V
    /// </summary>
    /// <param name="offset">�I�t�Z�b�g</param>
    /// <param name="size">�T�C�Y</param>
    /// <param name="data">�f�[�^</param>
    void UpdateVertexBuffer(GLintptr offset, GLsizeiptr size, const void* data) const;
};
}
#endif // !U22_GRAPHICS_VERTEX_ARRAY_H