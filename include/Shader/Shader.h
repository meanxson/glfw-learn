#ifndef GLFW_LEARN_SHADER_H
#define GLFW_LEARN_SHADER_H

#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <GL/glew.h>


class Shader {
public:
    Shader();

    ~Shader();

    void createFromString(const char *vertexCode, const char *fragmentCode);

    void createFromFile(const char *vertLocation, const char *fragmentLocation);

    std::string readFile(const char *filePath);

    [[nodiscard]] GLuint getProjectionLocation() const;

    [[nodiscard]] GLuint getModelLocation() const;

    [[nodiscard]] GLuint getViewLocation() const;

    [[nodiscard]] GLuint getAmbientIntensityLocation() const;

    [[nodiscard]] GLuint getAmbientColourLocation() const;

    [[nodiscard]] GLuint getDiffuseIntensityLocation() const;

    [[nodiscard]] GLuint getDirectionLocation() const;

    [[nodiscard]] GLuint getSpecularIntensityLocation() const;

    [[nodiscard]] GLuint getShininessLocation() const;

    [[nodiscard]] GLuint getEyePosition() const;


    void useShader() const;

    void clearShader();

private:
    GLuint m_shaderId, m_uniformProjection, m_uniformModel, m_uniformView, m_uniformAmbientIntensity,
            m_uniformAmbientColour, m_uniformDiffuseIntensity, m_uniformDirection, m_uniformEyePosition,
            m_uniformSpecularIntensity, m_uniformShininess;

    void compileShader(const char *vertexCode, const char *fragmentCode);

    void addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);
};


#endif //GLFW_LEARN_SHADER_H
