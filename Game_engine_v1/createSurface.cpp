#include "CreateSurface.h"

#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateInstance.h"
#include "window.h"

/*
 * This file serves as the primary entry point for managing Vulkan surface
 * creation. It integrates with the Vulkan instance and windowing system to
 * create surfaces for rendering. The file provides the foundation for handling
 * Vulkan surface-related functionalities within the application.
 *
 * Key responsibilities of this file:
 * - Managing the creation of Vulkan surfaces.
 * - Encapsulating Vulkan surface-related logic in the `CreateSurface`
 * namespace.
 * - Providing initialization and cleanup functions for surface management.
 */

namespace CreateSurface {

VkSurfaceKHR surface;

// Function to initialize the CreateSurface system
void initializeCreateSurface() {
    // create the vulkan surface in glfw
    createSurface();
}

void createSurface() {
    if (glfwCreateWindowSurface(CreateInstance::instance, Window::window,
                                nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("failed to create window surface!");
    }
}

// Function to cleanup the CreateSurface system
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "createSurface cleaned up successfully." << std::endl;
}

}  // namespace CreateSurface
