#ifndef GLFW_LEARN_DIRECTIONALLIGHT_H
#define GLFW_LEARN_DIRECTIONALLIGHT_H

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight();

    ~DirectionalLight() = delete;

    DirectionalLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity, glm::vec3 dir, GLfloat diffIntensity);

    void useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, GLfloat diffuseIntensity,
                  GLfloat directionLocation);
};


#endif //GLFW_LEARN_DIRECTIONALLIGHT_H
