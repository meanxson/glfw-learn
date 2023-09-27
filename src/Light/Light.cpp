//
// Created by meanx on 25.09.2023.
//

#include "../../include/Light/Light.h"

Light::Light() : m_colour(glm::vec3(1.0f, 1.0f, 1.0f)), m_ambientIntensity(1.0f),
                 m_direction(glm::vec3(0.0f, -1.0f, 0.0f)), m_diffuseIntensity(0.0f) {

}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity, glm::vec3 dir, GLfloat diffIntensity)
        : m_colour(glm::vec3(red, green, blue)),
          m_ambientIntensity(intensity), m_direction(dir), m_diffuseIntensity(diffIntensity) {

}

Light::~Light() {

}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation, GLfloat diffuseIntensity,
                     GLfloat directionLocation) {
    glUniform3f(ambientColourLocation, m_colour.x, m_colour.y, m_colour.z);
    glUniform1f(ambientIntensityLocation, m_ambientIntensity);

    glUniform3f(directionLocation, m_direction.x, m_direction.y, m_direction.z);
    glUniform1f(diffuseIntensity, m_diffuseIntensity);

}
