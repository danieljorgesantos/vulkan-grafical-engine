#ifndef CREATE_DESCRIPTOR_POOL_H
#define CREATE_DESCRIPTOR_POOL_H

#include <vulkan/vulkan.h>

#include <array>

/*
 * The CreateDescriptorPool namespace provides functionalities
 * for creating and managing Vulkan descriptor pools.
 *
 * Key responsibilities:
 * - Initializing descriptor pool resources.
 * - Cleaning up descriptor pool resources.
 */

namespace CreateDescriptorPool {

// Vulkan descriptor pool object
extern VkDescriptorPool descriptorPool;

// Function to create the descriptor pool
void createDescriptorPool();

// Function to clean up descriptor pool resources
void cleanup();

}  // namespace CreateDescriptorPool

#endif  // CREATE_DESCRIPTOR_POOL_H
