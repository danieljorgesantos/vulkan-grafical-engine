#ifndef CREATE_INDEX_BUFFER_H
#define CREATE_INDEX_BUFFER_H

#include <vulkan/vulkan.h>

/*
 * The CreateIndexBuffer namespace provides functionalities
 * related to creating and managing Vulkan index buffers.
 *
 * Key responsibilities:
 * - Creating and managing Vulkan index buffers.
 * - Interfacing with other components like texture images and vertex buffers.
 */

namespace CreateIndexBuffer {

// Vulkan buffer and memory for index data
extern VkBuffer indexBuffer;
extern VkDeviceMemory indexBufferMemory;

// Function to create the index buffer
void createIndexBuffer();

// Function to clean up index buffer resources
void cleanup();

}  // namespace CreateIndexBuffer

#endif  // CREATE_INDEX_BUFFER_H
