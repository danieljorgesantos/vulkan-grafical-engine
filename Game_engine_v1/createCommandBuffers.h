#ifndef CREATE_COMMAND_BUFFERS_H
#define CREATE_COMMAND_BUFFERS_H

#include <vulkan/vulkan.h>

#include <vector>

/*
 * The CreateCommandBuffers namespace provides functionalities
 * for creating and managing Vulkan command buffers.
 *
 * Key responsibilities:
 * - Allocating command buffers for rendering operations.
 * - Cleaning up command buffer resources.
 */

namespace CreateCommandBuffers {

// Vulkan command buffer collection
extern std::vector<VkCommandBuffer> commandBuffers;

// Function to create command buffers
void createCommandBuffers();

// Function to clean up command buffer resources
void cleanup();

}  // namespace CreateCommandBuffers

#endif  // CREATE_COMMAND_BUFFERS_H
