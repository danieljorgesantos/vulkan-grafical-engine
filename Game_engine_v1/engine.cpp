#include "Engine.h"

#include <chrono>
#include <iostream>

#include "Camera.h"
#include "CreateLogicalDevice.h"
#include "DrawFrame.h"
#include "Graphics.h"
#include "window.h"

namespace Engine {

void initialize() {
    Graphics::initialize();
    Camera::initialize();
    // Audio::initialize();
    // Physics::initialize();
    mainLoop();
    cleanup();
}

void mainLoop() {
    while (!glfwWindowShouldClose(Window::window)) {
        glfwPollEvents();

        // Calculate delta time for consistent movement speed
        static auto previousTime = std::chrono::high_resolution_clock::now();
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime =
            std::chrono::duration<float, std::chrono::seconds::period>(
                currentTime - previousTime)
                .count();
        previousTime = currentTime;

        // Process keyboard input
        Camera::camera.processKeyboard(Window::window, deltaTime);

        DrawFrame::drawFrame();
    }

    vkDeviceWaitIdle(CreateLogicalDevice::device);
}

void cleanup() {
    // put something here for cleanup of the graphics
    std::cout << "cleanup() Rendering systems initialized successfully."
              << std::endl;

    // cleanup graphics
    // cleanup audio
    // cleanup physics
    // cleanup other things
}

}  // namespace Engine
