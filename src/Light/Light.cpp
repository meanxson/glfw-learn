//
// Created by meanx on 25.09.2023.
//

#include "../../include/Light/Light.h"

Light::Light() : m_colour(glm::vec3(1.0f, 1.0f, 1.0f)), m_ambientIntensity(1.0f) {

}

Light::Light(GLfloat red, GLfloat green, GLfloat blue, GLfloat intensity) : m_colour(glm::vec3(red, green, blue)),
                                                                            m_ambientIntensity(intensity) {

}

Light::~Light() {

}

void Light::useLight(GLfloat ambientIntensityLocation, GLfloat ambientColourLocation) {
    glUniform3f(ambientColourLocation, m_colour.x, m_colour.y, m_colour.z);
    glUniform1f(ambientIntensityLocation, m_ambientIntensity);
}
