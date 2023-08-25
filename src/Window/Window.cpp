#include "../../include/Window/Window.h"


Window::Window() {
    m_width = 800;
    m_height = 600;
}


Window::Window(char *windowName) {
    m_width = 800;
    m_height = 600;
    m_windowTitle = windowName;
}

Window::Window(GLuint width, GLuint height, char *windowName) : m_width(width), m_height(height),
                                                                m_windowTitle(windowName) {

}

Window::~Window() {
    glfwDestroyWindow(m_mainWindow);
    glfwTerminate();
}

int Window::initialize() {
    if (!glfwInit()) {
        printf("GLFW initialisation failed!");
        glfwTerminate();
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

     m_mainWindow = glfwCreateWindow(m_width, m_height, m_windowTitle, NULL, NULL);
    if (!m_mainWindow) {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }
    glfwGetFramebufferSize(m_mainWindow, &m_bufferWidth, &m_bufferHeight);

    glfwMakeContextCurrent(m_mainWindow);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(m_mainWindow);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, m_bufferWidth, m_bufferHeight);
    return 0;
}

