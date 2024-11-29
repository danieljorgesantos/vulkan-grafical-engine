#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <string>
#include <vector>

#include "Vulkan.h"
#include "Window.h"

/*
 * This header file declares the `Graphics` namespace, which encapsulates
 * all graphics-related operations, including rendering and window management
 * using Vulkan and other graphics APIs.
 *
 * Key functionalities:
 * - Initializing and managing the Vulkan rendering system.
 * - Managing window integration with Vulkan.
 * - Cleaning up graphics-related resources.
 */

namespace Graphics {

// Initializes the windowing system.
void initWindow();

// Initializes the Vulkan rendering system.
void initVulkan();

// Initializes the graphics subsystem, combining window and Vulkan setup.
void initialize();

// Cleans up the graphics subsystem and releases resources.
void cleanup();

}  // namespace Graphics

#endif  // GRAPHICS_H
