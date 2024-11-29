#ifndef CAMERA_H
#define CAMERA_H

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Camera {

class Camera {
   public:
    Camera(glm::vec3 startPosition, glm::vec3 up, float startYaw,
           float startPitch);
    Camera();

    glm::mat4 getViewMatrix() const;
    void processKeyboard(GLFWwindow* window, float deltaTime);
    void processMouseMovement(float xOffset, float yOffset,
                              GLboolean constrainPitch = true);

   private:
    void updateCameraVectors();

    glm::vec3 position;
    glm::vec3 front;
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    float yaw;
    float pitch;

    float movementSpeed;
    float mouseSensitivity;
};

extern Camera camera;
void initialize();

}  // namespace Camera

#endif  // CAMERA_H
