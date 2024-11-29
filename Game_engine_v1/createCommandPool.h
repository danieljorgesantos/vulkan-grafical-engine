#ifndef CREATE_COMMAND_POOL_H
#define CREATE_COMMAND_POOL_H

#include <vulkan/vulkan.h>

#include <iostream>

/*
 * This file serves as the header file for the `CreateCommandPool` namespace.
 * It provides function declarations for creating and managing Vulkan command
 * pools.
 *
 * Key responsibilities:
 * - Encapsulating Vulkan command pool creation logic.
 * - Offering cleanup functionality for command pool resources.
 */

namespace CreateCommandPool {

// Vulkan command pool used for command buffer allocation
extern VkCommandPool commandPool;

// Function to create the Vulkan command pool
void createCommandPool();

// Function to clean up the Vulkan command pool
void cleanup();

}  // namespace CreateCommandPool

#endif  // CREATE
