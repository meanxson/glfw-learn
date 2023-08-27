//
// Created by Mike on 28.08.2023.
//

#ifndef GLFW_LEARN_CAMERA_H
#define GLFW_LEARN_CAMERA_H

#include <GL/glew.h>`
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera();
    Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,
           GLfloat startMoveSpeed, GLfloat mouseSensitivity);
    ~Camera();

    void keyControl(const bool* keys);
    glm::mat4 calculateViewMatrix();

private:
    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;

    GLfloat m_yaw;
    GLfloat m_pitch;

    GLfloat m_movementSpeed;
    GLfloat m_mouseSensitivity;

    void update();
};


#endif //GLFW_LEARN_CAMERA_H
