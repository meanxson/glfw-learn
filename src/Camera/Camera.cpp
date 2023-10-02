//
// Created by Mike on 28.08.2023.
//

#include "../../include/Camera/Camera.h"

Camera::Camera(glm::vec3 startPosition, glm::vec3 startUp, GLfloat startYaw, GLfloat startPitch,
               GLfloat startMoveSpeed, GLfloat mouseSensitivity) : m_position(startPosition),
                                                                   m_worldUp(startUp), m_yaw(startYaw),
                                                                   m_pitch(startPitch),
                                                                   m_front(glm::vec3(0.0f, 0.0f, -1.0f)),
                                                                   m_movementSpeed(startMoveSpeed),
                                                                   m_mouseSensitivity(mouseSensitivity) {
    update();
}

void Camera::keyControl(const bool *keys, GLfloat deltaTime) {
    GLfloat velocity = m_movementSpeed * deltaTime;

    if (keys[GLFW_KEY_W]) {
        m_position += m_front * velocity;
    }

    if (keys[GLFW_KEY_S]) {
        m_position -= m_front * velocity;
    }

    if (keys[GLFW_KEY_A]) {
        m_position -= m_right * velocity;
    }

    if (keys[GLFW_KEY_D]) {
        m_position += m_right * velocity;
    }
}

void Camera::mouseControl(GLfloat xChange, GLfloat yChange) {
    xChange *= m_mouseSensitivity;
    yChange *= m_mouseSensitivity;

    m_yaw += xChange;
    m_pitch += yChange;


    if (m_pitch > 89.0f) {
        m_pitch = 89.0f;
    }

    if (m_pitch < -89.0f) {
        m_pitch = -89.0f;
    }

    update();
}

glm::vec3 Camera::getCameraPosition() {
    return m_position;
}

glm::mat4 Camera::calculateViewMatrix() {
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::update() {
    m_front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front.y = sin(glm::radians(m_pitch));
    m_front.z = sin(glm::radians(m_yaw) * cos(glm::radians(m_pitch)));
    m_front = glm::normalize(m_front);

    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up = glm::normalize(glm::cross(m_right, m_front));
}
