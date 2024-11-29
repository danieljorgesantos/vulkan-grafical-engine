#ifndef DRAW_FRAME_H
#define DRAW_FRAME_H

#include <vulkan/vulkan.h>

#include <chrono>
#include <iostream>

#include "glm_includes.h"

/*
 * The DrawFrame namespace manages the Vulkan rendering loop, recording command
 * buffers, updating uniform buffers, and synchronizing rendering operations.
 *
 * Key responsibilities:
 * - Recording Vulkan command buffers.
 * - Managing frame synchronization and updating uniform buffers.
 * - Handling swap chain recreation and cleanup.
 */

namespace DrawFrame {

// Tracks the current frame index in the swap chain
extern uint32_t currentFrame;

// Records commands into the command buffer for rendering
void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

// Cleans up swap chain resources
void cleanupSwapChain();

// Recreates the swap chain and dependent resources
void recreateSwapChain();

// Updates the uniform buffer with transformation matrices and other data
void updateUniformBuffer(uint32_t currentImage);

// Executes the rendering process for a single frame
void drawFrame();

// Cleans up resources used in the DrawFrame namespace
void cleanup();

}  // namespace DrawFrame

#endif  // DRAW_FRAME_H
