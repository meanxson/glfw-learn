#define STB_IMAGE_IMPLEMENTATION

#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "include/Mesh/Mesh.h"
#include "include/Shader/Shader.h"
#include "include/Window/Window.h"
#include "include/Camera/Camera.h"
#include "include/Texture/Texture.h"
#include "include/Light/Light.h"

// Window dimensions
const float RADIANS = M_PI / 180.0f;

Window mainWindow;
std::vector<Mesh *> meshList;
std::vector<Shader> shaderList;
Camera camera;

GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;

Light mainLight;

Texture brickTexture;
Texture dirtTexture;

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
            //x             y         z          u       v
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, -1.0f, 1.0f, 0.5f, 0.0f,
            1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.5f, 1.0f
    };

    Mesh *triangle = new Mesh();
    triangle->createMesh(vertices, indices, 20, 12);
    meshList.push_back(triangle);

    Mesh *triangle2 = new Mesh();
    triangle2->createMesh(vertices, indices, 20, 12);
    meshList.push_back(triangle2);
}

void createShader() {
    auto *shader1 = new Shader();
    shader1->createFromFile(vShader, fShader);
    shaderList.push_back(*shader1);
}

int main() {
    mainWindow.initialize();

    createObjects();
    createShader();

    camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f),
                    glm::vec3(0.0f, 1.0f, 0.0f),
                    -90.0f, 0.0f, 5.0f, 0.5f);

    brickTexture = Texture(TEXTURE_PATH "brick.png");
    brickTexture.loadTexture();

    dirtTexture = Texture(TEXTURE_PATH "dirt.png");
    dirtTexture.loadTexture();

    mainLight = Light();

    GLuint uniformProjection, uniformModel, uniformView, uniformAmbientIntensity, uniformAmbientColour;

    glm::mat4 projection = glm::perspective(45.0f, (GLfloat) mainWindow.getBufferWidth() /
                                                   (GLfloat) mainWindow.getBufferHeight(), 0.1f, 100.0f);


    // Loop until window closed
    while (!mainWindow.getShouldClose()) {
        GLfloat now = glfwGetTime();
        deltaTime = now - lastTime;
        lastTime = now;

        // Get + Handle user input events
        glfwPollEvents();

        camera.keyControl(mainWindow.getsKeys(), deltaTime);
        camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderList[0].useShader();
        uniformModel = shaderList[0].getModelLocation();
        uniformProjection = shaderList[0].getProjectionLocation();
        uniformView = shaderList[0].getViewLocation();
        uniformAmbientColour = shaderList[0].getAmbientColourLocation();
        uniformAmbientIntensity = shaderList[0].getAmbientIntensityLocation();

        mainLight.useLight(uniformAmbientIntensity, uniformAmbientColour);

        glm::mat4 model(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
        brickTexture.useTexture();

        meshList[0]->renderMesh();

        model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(0.0f, 1.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        dirtTexture.useTexture();
        meshList[1]->renderMesh();


        glUseProgram(0);

        mainWindow.swapBuffers();
    }

    return 0;
}