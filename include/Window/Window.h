#ifndef GLFW_LEARN_WINDOW_H
#define GLFW_LEARN_WINDOW_H

#include <cstdio>
#include <GL/glew.h>
#include <GLfw/glfw3.h>

class Window {
public:
    Window();

    Window(char *windowName);

    Window(GLuint width, GLuint height, char *windowName);

    ~Window();


    int initialize();

    GLfloat getBufferWidth() { return m_bufferWidth; }

    GLfloat getBufferHeight() { return m_bufferHeight; }

    bool getShouldClose() { return glfwWindowShouldClose(m_mainWindow); }

    void swapBuffers() {glfwSwapBuffers(m_mainWindow);}

private:
    GLFWwindow *m_mainWindow{};
    GLint m_width, m_height;
    GLint m_bufferWidth{}, m_bufferHeight{};
    char *m_windowTitle{};
};


#endif //GLFW_LEARN_WINDOW_H
