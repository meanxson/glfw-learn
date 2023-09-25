//
// Created by meanx on 25.09.2023.
//

#ifndef GLFW_LEARN_LIGHT_H
#define GLFW_LEARN_LIGHT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light {
public:
    Light();

    Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity);

    ~Light();

    void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation);

private:
    glm::vec3 m_colour;
    GLfloat m_ambientIntensity;
};


#endif //GLFW_LEARN_LIGHT_H
