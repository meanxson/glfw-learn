#include "../../include/Shader/Shader.h"

Shader::Shader() {
    m_shaderId = 0;
    m_uniformModel = 0;
    m_uniformProjection = 0;
    m_uniformView = 0;
}

Shader::~Shader() {
    clearShader();
}

void Shader::createFromString(const char *vertexCode, const char *fragmentCode) {
    compileShader(vertexCode, fragmentCode);
}

void Shader::createFromFile(const char *vertLocation, const char *fragmentLocation) {
    std::string vertexStr = readFile(vertLocation);
    std::string fragmentStr = readFile(fragmentLocation);

    const char *vertexCode = vertexStr.c_str();
    const char *fragmentCode = fragmentStr.c_str();

    compileShader(vertexCode, fragmentCode);
}

std::string Shader::readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if (!fileStream.is_open()) {
        printf("Failed to read %s! file doesn't exist.\n", filePath);
        return "";
    }

    std::string line;
    while (!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}


GLuint Shader::getProjectionLocation() const {
    return m_uniformProjection;
}

GLuint Shader::getModelLocation() const {
    return m_uniformModel;
}

GLuint Shader::getViewLocation() const {
    return m_uniformView;
}

GLuint Shader::getAmbientIntensityLocation() const {
    return m_uniformAmbientIntensity;
}

GLuint Shader::getAmbientColourLocation() const {
    return m_uniformAmbientColour;
}

GLuint Shader::getDiffuseIntensityLocation() const {
    return m_uniformDiffuseIntensity;
}

GLuint Shader::getDirectionLocation() const {
    return m_uniformDirection;
}

GLuint Shader::getSpecularIntensityLocation() const {
    return m_uniformSpecularIntensity;
}

GLuint Shader::getShininessLocation() const {
    return m_uniformShininess;
}

GLuint Shader::getEyePosition() const {
    return m_uniformEyePosition;
}

void Shader::useShader() const {
    glUseProgram(m_shaderId);
}

void Shader::clearShader() {
    if (m_shaderId != 0) {
        glDeleteProgram(m_shaderId);
        m_shaderId = 0;
    }
}

void Shader::compileShader(const char *vertexCode, const char *fragmentCode) {
    m_shaderId = glCreateProgram();

    if (!m_shaderId) {
        printf("Failed to create shader\n");
        return;
    }

    addShader(m_shaderId, vertexCode, GL_VERTEX_SHADER);
    addShader(m_shaderId, fragmentCode, GL_FRAGMENT_SHADER);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    glLinkProgram(m_shaderId);
    glGetProgramiv(m_shaderId, GL_LINK_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(m_shaderId, sizeof(eLog), NULL, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }

    glValidateProgram(m_shaderId);
    glGetProgramiv(m_shaderId, GL_VALIDATE_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(m_shaderId, sizeof(eLog), NULL, eLog);
        printf("Error validating program: '%s'\n", eLog);
        return;
    }

    m_uniformModel = glGetUniformLocation(m_shaderId, "model");
    m_uniformProjection = glGetUniformLocation(m_shaderId, "projection");
    m_uniformView = glGetUniformLocation(m_shaderId, "view");
    m_uniformAmbientColour = glGetUniformLocation(m_shaderId, "directionalLight.colour");
    m_uniformAmbientIntensity = glGetUniformLocation(m_shaderId, "directionalLight.ambientIntensity");
    m_uniformDirection = glGetUniformLocation(m_shaderId, "directionalLight.direction");
    m_uniformDiffuseIntensity = glGetUniformLocation(m_shaderId, "directionalLight.diffuseIntensity");
    m_uniformSpecularIntensity = glGetUniformLocation(m_shaderId, "material.specularIntensity");
    m_uniformShininess = glGetUniformLocation(m_shaderId, "material.shininess");
    m_uniformEyePosition = glGetUniformLocation(m_shaderId, "eyePosition");
}

void Shader::addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType) {
    GLuint theShader = glCreateShader(shaderType);

    const GLchar *theCode[1];
    theCode[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);

    glShaderSource(theShader, 1, theCode, codeLength);
    glCompileShader(theShader);

    GLint result = 0;
    GLchar eLog[1024] = {0};

    glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
    if (!result) {
        glGetShaderInfoLog(theShader, 1024, NULL, eLog);
        fprintf(stderr, "Error compiling the %d shader: '%s'\n", shaderType, eLog);
        return;
    }

    glAttachShader(theProgram, theShader);
}

