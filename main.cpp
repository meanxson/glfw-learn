#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "include/Mesh/Mesh.h"
#include "include/Shader/Shader.h"
#include "include/Window/Window.h"
#include "include/Camera/Camera.h"

// Window dimensions
const float RADIANS = M_PI / 180.0f;

Window mainWindow("Test Window");
std::vector<Mesh *> meshList;
std::vector<Shader> shaderList;
Camera camera;

bool direction = true;
float triOffset = 0.0f;
float triMaxOffset = 0.7f;
float triIncrement = 0.01f;
float currentAngle = 0.0f;
float rotateSpeed = 0.3f;

bool sizeDirection = true;
float currentSize = 0.4f;
float maxSize = 0.8f;
float minSize = 0.1f;

// Vertex Shader code
static const char *vShader = SHADER_PATH "shader.vert";
// Fragment Shader
static const char *fShader = SHADER_PATH "shader.frag";

void createObjects() {
    unsigned int indices[] = {
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 1, 2
    };

    GLfloat vertices[] = {
            -1.0f, -1.0f, 0.0f,
            0.0f, -1.0f, 1.0f,
            1.0f, -1.0f, 0.0f,
            0.0f, 1.0f, 0.0f
    };

    Mesh *triangle = new Mesh();
    triangle->createMesh(vertices, indices, 12, 12);
    meshList.push_back(triangle);

    Mesh *triangle2 = new Mesh();
    triangle2->createMesh(vertices, indices, 12, 12);
    meshList.push_back(triangle2);
}

void addShader(GLuint theProgram, const char *shaderCode, GLenum shaderType) {
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

void createShader() {
    Shader *shader1 = new Shader();
    shader1->createFromFile(vShader, fShader);
    shaderList.push_back(*shader1);
}

int main() {
    mainWindow.initialize();

    createObjects();
    createShader();

    camera = Camera(
            glm::vec3(0.0f, 0.0f, 0.0f),
            glm::vec3(0.0f, 1.0f, 0.0f),
            0.0f, 0.0f, 5.0f, 1.0f);

    GLuint uniformProjection = 0, uniformModel = 0, uniformView = 0;

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat) mainWindow.getBufferWidth() /
                                                   (GLfloat) mainWindow.getBufferHeight(), 0.1f, 100.0f);


    // Loop until window closed
    while (!mainWindow.getShouldClose()) {
        // Get + Handle user input events
        glfwPollEvents();

        camera.keyControl(mainWindow.getsKeys());

        if (direction) {
            triOffset += triIncrement;
        } else {
            triOffset -= triIncrement;
        }

        if (abs(triOffset) >= triMaxOffset) {
            direction = !direction;
        }

        currentAngle += rotateSpeed;

        if (currentAngle >= 360) {
            currentAngle -= 360;
        }

        if (sizeDirection) {
            currentSize += 0.001f;
        } else {
            currentSize -= 0.001f;
        }

        if (currentSize >= maxSize || currentSize <= minSize) {
            sizeDirection = !sizeDirection;
        }

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0].useShader();
        uniformModel = shaderList[0].getModelLocation();
        uniformProjection = shaderList[0].getProjectionLocation();
        uniformView = shaderList[0].getViewLocation();

        glm::mat4 model(1.0f);

        model = glm::translate(model, glm::vec3(triOffset, 0.0f, -2.5f));
        model = glm::rotate(model, currentAngle * RADIANS, glm::vec3(0.0f, currentAngle, 1.0f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));

        meshList[0]->renderMesh();

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(-triOffset, 1.0f, -2.5f));
        model = glm::rotate(model, currentAngle * RADIANS, glm::vec3(0.0f, currentAngle, 1.0f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

        meshList[1]->renderMesh();


        glUseProgram(0);

        mainWindow.swapBuffers();
    }

    return 0;
}