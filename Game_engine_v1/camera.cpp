#include "Camera.h"

#include "glm_includes.h"

namespace Camera {

// Global Camera instance
Camera camera;  // Declare the instance without parameters

// Default constructor
Camera::Camera()
    : position(glm::vec3(0.0f, 0.0f, 3.0f)),
      front(glm::vec3(0.0f, 0.0f, -1.0f)),
      up(glm::vec3(0.0f, 1.0f, 0.0f)),
      right(glm::vec3(1.0f, 0.0f, 0.0f)),
      worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
      yaw(-90.0f),
      pitch(0.0f),
      movementSpeed(2.5f),
      mouseSensitivity(0.1f) {
    updateCameraVectors();
}

// Constructor with parameters
Camera::Camera(glm::vec3 startPosition, glm::vec3 up, float startYaw,
               float startPitch)
    : position(startPosition),
      front(glm::vec3(0.0f, 0.0f, -1.0f)),
      up(up),
      worldUp(up),
      yaw(startYaw),
      pitch(startPitch),
      movementSpeed(2.5f),
      mouseSensitivity(0.1f) {
    updateCameraVectors();
}

void initialize() {
    camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f),  // Start position
                    glm::vec3(0.0f, 1.0f, 0.0f),  // Up vector
                    -90.0f,                       // Initial yaw
                    0.0f);                        // Initial pitch
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}

void Camera::processKeyboard(GLFWwindow* window, float deltaTime) {
    float velocity = movementSpeed * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        position += front * velocity;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        position -= front * velocity;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        position -= right * velocity;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        position += right * velocity;
}

void Camera::processMouseMovement(float xOffset, float yOffset,
                                  GLboolean constrainPitch) {
    xOffset *= mouseSensitivity;
    yOffset *= mouseSensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (constrainPitch) {
        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);

    right = glm::normalize(glm::cross(front, worldUp));
    up = glm::normalize(glm::cross(right, front));
}

}  // namespace Camera
