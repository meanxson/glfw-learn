#include <cstdio>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef GLchar string[1024];
// Window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

GLuint VAO, VBO, shader;

// Vertex Shader
static const char *vShader = "                                                                          \n"
                             "#version 330                                                              \n"
                             "layout (location = 0) in vec3 pos;                                        \n"
                             "void main()                                                               \n"
                             "{                                                                         \n"
                             "  gl_Position = vec4(0.4 * pos.x, 0.4 *  pos.y, pos.z, 1.0);              \n"
                             "}                                                                         \n";

// Fragment Shader
static const char *fShader = "                                                                          \n"
                             "#version 330                                                              \n"
                             "out vec4 colour;                                                          \n"
                             "void main()                                                               \n"
                             "{                                                                         \n"
                             "  colour = vec4(1.0, 0, 0, 1.0);                                          \n"
                             "}                                                                         \n";

void addShader(GLuint program, const char *shaderCode, GLenum shaderType) {
    GLuint localShader = glCreateShader(shaderType);
    const GLchar *code[1];
    code[0] = shaderCode;

    GLint codeLength[1];
    codeLength[0] = strlen(shaderCode);
    glShaderSource(localShader, 1, code, codeLength);
    glCompileShader(localShader);

    GLint result;
    GLchar eLog[1024];

    glGetShaderiv(localShader, GL_COMPILE_STATUS, &result);

    if (!result) {
        glGetProgramInfoLog(localShader, sizeof(eLog), nullptr, eLog);
        printf("Error compiling the shader '%d': '%s'\n", shaderType, eLog);
        return;
    }

    glAttachShader(program, localShader);
}

void compileShader() {
    shader = glCreateProgram();

    if (!shader) {
        printf("Error with creating shader program!\n");
        return;
    }

    addShader(shader, vShader, GL_VERTEX_SHADER);
    addShader(shader, fShader, GL_FRAGMENT_SHADER);

    GLint result;
    GLchar eLog[1024];

    glLinkProgram(shader);
    glGetProgramiv(shader, GL_LINK_STATUS, &result);

    if (!result) {
        glGetProgramInfoLog(shader, sizeof(eLog), nullptr, eLog);
        printf("Error linking program: '%s'\n", eLog);
        return;
    }

    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
    if (!result) {
        glGetProgramInfoLog(shader, sizeof(eLog), nullptr, eLog);
        printf("Error validating program: '%s'\n", eLog);
        return;
    }
}

void createTriangle() {
    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f,
            1.0, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int main() {
    // Initialise GLFW
    if (!glfwInit()) {
        printf("GLFW initialisation failed!");
        glfwTerminate();
        return 1;
    }

    // Setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core Profile = No Backwards Compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // Allow Forward
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create the window
    GLFWwindow *mainWindow;
    mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", nullptr, nullptr);
    if (!mainWindow) {
        printf("GLFW window creation failed!");
        glfwTerminate();
        return 1;
    }

    // Get Buffer Size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // Set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    // Allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        printf("GLEW initialisation failed!");
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // Setup Viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    createTriangle();
    compileShader();

    // Loop until window closed
    while (!glfwWindowShouldClose(mainWindow)) {
        // Get + Handle user input events
        glfwPollEvents();

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(0);

        glUseProgram(0);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}