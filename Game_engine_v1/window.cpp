#include "Window.h"

#include <iostream>

#include "Camera.h"

namespace Window {

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow* window = nullptr;
WindowContext context;

static void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
    if (context.firstMouse) {
        context.lastMouseX = xpos;
        context.lastMouseY = ypos;
        context.firstMouse = false;
    }

    float xOffset = xpos - context.lastMouseX;
    float yOffset =
        context.lastMouseY - ypos;  // Reversed: y-coordinates go bottom to top

    context.lastMouseX = xpos;
    context.lastMouseY = ypos;

    Camera::camera.processMouseMovement(xOffset, yOffset);
}

static void framebufferResizeCallback(GLFWwindow* window, int width,
                                      int height) {
    context.framebufferResized = true;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action,
                 int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void initialize() {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW!");
    }

    // Retrieve the primary monitor and its video mode
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* videoMode = glfwGetVideoMode(primaryMonitor);
    if (!primaryMonitor || !videoMode) {
        glfwTerminate();
        throw std::runtime_error(
            "Failed to get primary monitor or video mode!");
    }

    // Set Vulkan-specific window hints
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a fullscreen window on the primary monitor
    window = glfwCreateWindow(videoMode->width, videoMode->height, "Vulkan",
                              primaryMonitor, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window!");
    }

    // Store the window context
    glfwSetWindowUserPointer(window, &context);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPosCallback(window, mouseCallback);
    glfwSetKeyCallback(window, keyCallback);

    context.firstMouse = true;  // Initialize first mouse state
    Camera::initialize();       // Initialize the camera
}

void cleanup() {
    if (window) {
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}

}  // namespace Window
