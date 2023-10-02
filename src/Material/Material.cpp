//
// Created by meanx on 02.10.2023.
//

#include "../../include/Material/Material.h"

Material::Material() : m_shininess(0), m_specularIntensity(0) {

}

Material::Material(GLfloat intensity, GLfloat shine) : m_specularIntensity(intensity), m_shininess(shine) {

}

Material::~Material() {

}

void Material::useMaterial(GLuint specularIntensityLocation, GLuint shininessLocation) {
    glUniform1f(specularIntensityLocation, m_specularIntensity);
    glUniform1f(shininessLocation, m_shininess);
}
