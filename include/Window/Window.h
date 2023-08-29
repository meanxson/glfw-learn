#ifndef GLFW_LEARN_WINDOW_H
#define GLFW_LEARN_WINDOW_H

#include <cstdio>
#include <GL/glew.h>
#include <GLfw/glfw3.h>

class Window {
public:
    Window();
    Window(GLuint width, GLuint height, char *windowName);
    ~Window();


    int initialize();

    GLfloat getBufferWidth() { return m_bufferWidth; }

    GLfloat getBufferHeight() { return m_bufferHeight; }

    bool getShouldClose() { return glfwWindowShouldClose(m_mainWindow); }

    bool *getsKeys() { return m_keys; }

    GLfloat getXChange();
    GLfloat getYChange();

    void swapBuffers() { glfwSwapBuffers(m_mainWindow); }

private:
    GLFWwindow *m_mainWindow{};
    GLint m_width, m_height;
    GLint m_bufferWidth{}, m_bufferHeight{};

    bool m_keys[1024];

    GLfloat m_lastX;
    GLfloat m_lastY;
    GLfloat m_xChange;
    GLfloat m_yChange;

    bool m_isMouseFirstMoved;


    void createCallbacks();

    static void handleKeys(GLFWwindow *window, int key, int code, int action, int mode);

    static void handleMouse(GLFWwindow *window, double xPosition, double yPosition);
};


#endif //GLFW_LEARN_WINDOW_H
