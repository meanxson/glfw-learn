#include "../../include/Window/Window.h"


Window::Window() {
    m_width = 800;
    m_height = 600;

    m_xChange = 0;
    m_yChange = 0;

    for (bool &key: m_keys) {
        key = false;
    }
}

Window::Window(GLuint width, GLuint height, char *windowName) : m_width(width), m_height(height) {

    m_xChange = 0;
    m_yChange = 0;

    for (bool &key: m_keys) {
        key = false;
    }
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

    m_mainWindow = glfwCreateWindow(m_width, m_height, "Test Window", nullptr, nullptr);
    if (!m_mainWindow) {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }
    glfwGetFramebufferSize(m_mainWindow, &m_bufferWidth, &m_bufferHeight);

    glfwMakeContextCurrent(m_mainWindow);

    createCallbacks();
    glfwSetInputMode(m_mainWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(m_mainWindow);
        glfwTerminate();
        return 1;
    }

    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, m_bufferWidth, m_bufferHeight);

    glfwSetWindowUserPointer(m_mainWindow, this);

    return 0;
}

void Window::createCallbacks() {
    glfwSetKeyCallback(m_mainWindow, handleKeys);
    glfwSetCursorPosCallback(m_mainWindow, handleMouse);

}

void Window::handleKeys(GLFWwindow *window, int key, int code, int action, int mode) {

    auto *thisWindow = static_cast<Window *>(glfwGetWindowUserPointer(window));

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key >= 0 && key < 1024) {
        if (action == GLFW_PRESS) {
            thisWindow->m_keys[key] = true;
        } else if (action == GLFW_RELEASE) {
            thisWindow->m_keys[key] = false;
        }
    }
}


void Window::handleMouse(GLFWwindow *window, double xPosition, double yPosition) {
    auto *thisWindow = static_cast<Window *>(glfwGetWindowUserPointer(window));

    if (thisWindow->m_isMouseFirstMoved) {
        thisWindow->m_lastX = xPosition;
        thisWindow->m_lastY = yPosition;
        thisWindow->m_isMouseFirstMoved = false;
    }

    thisWindow->m_xChange = xPosition - thisWindow->m_lastX;
    thisWindow->m_yChange = thisWindow->m_lastY - yPosition;

    thisWindow->m_lastX = xPosition;
    thisWindow->m_lastY = yPosition;
}

GLfloat Window::getXChange() {
    GLfloat change = m_xChange;
    m_xChange = 0.0f;
    return change;
}

GLfloat Window::getYChange() {
    GLfloat change = m_yChange;
    m_yChange = 0.0f;
    return change;
}

