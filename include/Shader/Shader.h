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

    void useShader() const;

    void clearShader();

private:
    GLuint m_shaderId, m_uniformProjection, m_uniformModel;

    void compileShader(const char *vertexCode, const char *fragmentCode);

    void addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType);
};


#endif //GLFW_LEARN_SHADER_H
