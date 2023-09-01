#ifndef GLFW_LEARN_TEXTURE_H
#define GLFW_LEARN_TEXTURE_H

#include <GL/glew.h>
#include "stb_image.h"

class Texture {
public:
    Texture();

    Texture(char *fileLocation);

    ~Texture();

    void loadTexture();

    void useTexture();

    void clearTexture();

private:
    GLuint m_textureId;
    int m_width, m_height, m_bitDepth;
    char *m_fileLocation;
};


#endif //GLFW_LEARN_TEXTURE_H
