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
#include "include/Material/Material.h"

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

Material shinyMaterial;
Material dullMaterial;

// Vertex Shader code
static const char *vShader = SHADER_PATH "shader.vert";
// Fragment Shader
static const char *fShader = SHADER_PATH "shader.frag";

void calcAverageNormals(unsigned int *indices, unsigned int indiceCount, GLfloat *vertices,
                        unsigned int verticeCount, unsigned int vLength, unsigned int normalOffset) {
    for (int i = 0; i < indiceCount; i += 3) {
        unsigned int in0 = indices[i] * vLength;
        unsigned int in1 = indices[i + 1] * vLength;
        unsigned int in2 = indices[i + 2] * vLength;
        glm::vec3 v1((vertices[in1]) - vertices[in0], vertices[in1 + 1] - vertices[in0 + 1],
                     vertices[in1 + 2] - vertices[in0 + 2]);

        glm::vec3 v2((vertices[in2]) - vertices[in0], vertices[in2 + 1] - vertices[in0 + 1],
                     vertices[in2 + 2] - vertices[in0 + 2]);

        glm::vec3 normal = glm::cross(v1, v2);
        normal = glm::normalize(normal);

        in0 += normalOffset;
        in1 += normalOffset;
        in2 += normalOffset;

        vertices[in0] += normal.x;
        vertices[in0 + 1] += normal.y;
        vertices[in0 + 2] += normal.z;

        vertices[in1] += normal.x;
        vertices[in1 + 1] += normal.y;
        vertices[in1 + 2] += normal.z;

        vertices[in2] += normal.x;
        vertices[in2 + 1] += normal.y;
        vertices[in2 + 2] += normal.z;
    }

    for (size_t i = 0; i < verticeCount / vLength; ++i) {
        unsigned int nOffset = i * vLength + normalOffset;
        glm::vec3 vec(vertices[nOffset], vertices[nOffset + 1], vertices[nOffset + 2]);
        vec = glm::normalize(vec);

        vertices[nOffset] = vec.x;
        vertices[normalOffset + 1] = vec.y;
        vertices[nOffset + 2] = vec.z;
    }
}

void createObjects() {
    unsigned int indices[] = {
            0, 3, 1,
            1, 3, 2,
            2, 3, 0,
            0, 1, 2
    };

    GLfloat vertices[] = {
            //x             y         z          u       v          nx         ny        nz
            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, -1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f,
            1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f
    };

    calcAverageNormals(indices, 12, vertices, 32, 8, 5);

    Mesh *triangle = new Mesh();
    triangle->createMesh(vertices, indices, 32, 12);
    meshList.push_back(triangle);

    Mesh *triangle2 = new Mesh();
    triangle2->createMesh(vertices, indices, 32, 12);
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
                    -90.0f, 0.0f, 3.0f, 0.2f);

    brickTexture = Texture(TEXTURE_PATH "brick.png");
    brickTexture.loadTexture();

    dirtTexture = Texture(TEXTURE_PATH "dirt.png");
    dirtTexture.loadTexture();

    shinyMaterial = Material(1.0f, 32);
    dullMaterial = Material(0.3f, 4);

    mainLight = Light(1.0f, 1.0f, 1.0f, 0.2f, glm::vec3(2.0f, -1.0f, -2.0f), 1.0f);

    GLuint uniformProjection, uniformModel, uniformView, uniformAmbientIntensity, uniformAmbientColour, uniformDirection,
            uniformDiffuseIntensity, uniformEyePosition, uniformSpecularIntensity, uniformShininess;

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
        uniformDirection = shaderList[0].getDirectionLocation();
        uniformDiffuseIntensity = shaderList[0].getDiffuseIntensityLocation();
        uniformEyePosition = shaderList[0].getEyePosition();
        uniformSpecularIntensity = shaderList[0].getSpecularIntensityLocation();
        uniformShininess = shaderList[0].getShininessLocation();

        mainLight.useLight(uniformAmbientIntensity, uniformAmbientColour, uniformDiffuseIntensity, uniformDirection);


        glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
        glUniform3f(uniformEyePosition, camera.getCameraPosition().x, camera.getCameraPosition().y,
                    camera.getCameraPosition().z);

        glm::mat4 model(1.0f);


        model = glm::translate(model, glm::vec3(0.0f, 0.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        brickTexture.useTexture();
        shinyMaterial.useMaterial(uniformSpecularIntensity, uniformShininess);
        meshList[0]->renderMesh();

        model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(0.0f, 1.0f, -2.5f));
        model = glm::scale(model, glm::vec3(0.4f, 0.4f, 1.0f));
        glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
        dirtTexture.useTexture();
        dullMaterial.useMaterial(uniformSpecularIntensity, uniformShininess);
        meshList[1]->renderMesh();


        glUseProgram(0);

        mainWindow.swapBuffers();
    }

    return 0;
}