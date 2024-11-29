#include <iostream>
#include <string>
#include <vector>

#include "Vulkan.h"
#include "Window.h"

/*
 * This file serves as the primary entry point for managing all graphics-related
 * operations, including rendering and window management using Vulkan and other
 * graphics APIs. It provides the initialization logic and serves as the
 * foundation for handling graphical elements within the application.
 *
 * Key responsibilities of this file:
 * - Initializing the Vulkan rendering system and setting up the graphics
 * pipeline.
 * - Managing rendering contexts and integrating with the windowing system.
 * - Providing a namespace (`Graphics`) to encapsulate all graphics-related
 * functionalities.
 */

namespace Graphics {

void initWindow() {
    // Call the Window::initialize function
    Window::initialize();
}

// Function to initialize rendering systems
void initVulkan() {
    // Call the Window::initialize function
    Vulkan::initialize();
}

void initialize() {
    initWindow();
    initVulkan();
}

void cleanup() {
    // Cleanup logic for graphics
    std::cout << " cleanup() Graphics systems cleaned up successfully."
              << std::endl;
}

}  // namespace Graphics
