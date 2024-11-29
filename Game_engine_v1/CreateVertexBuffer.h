#ifndef CREATE_VERTEX_BUFFER_H
#define CREATE_VERTEX_BUFFER_H

#include <vulkan/vulkan.h>

namespace CreateVertexBuffer {

// Vulkan vertex buffer objects
extern VkBuffer vertexBuffer;
extern VkDeviceMemory vertexBufferMemory;

// Function to copy data between Vulkan buffers
void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

// Function to create Vulkan vertex buffers
void createVertexBuffer();

// Function to clean up Vulkan vertex buffer resources
void cleanup();
}  // namespace CreateVertexBuffer

#endif  // CREATE_VERTEX_BUFFER_H
