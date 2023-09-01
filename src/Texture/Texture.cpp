#include "../../include/Texture/Texture.h"

Texture::Texture() : m_fileLocation(""), m_textureId(0), m_bitDepth(0), m_width(0), m_height(0) {

}

Texture::Texture(char *fileLocation) : m_fileLocation(fileLocation), m_textureId(0), m_bitDepth(0), m_width(0),
                                       m_height(0) {

}

Texture::~Texture() {
    clearTexture();
}

void Texture::loadTexture() {
    unsigned char *textureData = stbi_load(m_fileLocation,
                                           &m_width, &m_height, &m_bitDepth, 0);

    if (!textureData) {
        printf("Failed to find %s\n", m_fileLocation);
    }

    glGenTextures(1, &m_textureId);
    glBindTexture(GL_TEXTURE_2D, m_textureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);

    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(textureData);
}

void Texture::useTexture() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_textureId);
}

void Texture::clearTexture() {
    glDeleteTextures(1, &m_textureId);
    m_textureId = 0;
    m_width = 0;
    m_height = 0;
    m_bitDepth = 0;
    m_fileLocation = "";
}
