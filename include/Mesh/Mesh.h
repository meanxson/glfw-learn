#ifndef GLFW_LEARN_MESH_H
#define GLFW_LEARN_MESH_H

#include <GL/glew.h>


class Mesh {
public:
    Mesh();

    ~Mesh();

    void
    createMesh(GLfloat *vertices, unsigned int *indices, unsigned int numberOfVertices, unsigned int numberOfIndices);

    void renderMesh() const;

    void clearMesh();

private:
    GLuint m_VAO, m_VBO, m_IBO;
    GLsizei m_indexCount;
};


#endif //GLFW_LEARN_MESH_H
