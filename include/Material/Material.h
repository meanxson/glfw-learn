//
// Created by meanx on 02.10.2023.
//

#ifndef GLFW_LEARN_MATERIAL_H
#define GLFW_LEARN_MATERIAL_H

#include <GL/glew.h>

class Material {
public:
    Material();

    Material(GLfloat intensity, GLfloat shine);

    ~Material();

    void useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

private:
    GLfloat m_specularIntensity;
    GLfloat m_shininess;
};


#endif //GLFW_LEARN_MATERIAL_H
