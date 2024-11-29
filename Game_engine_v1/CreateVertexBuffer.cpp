#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateLogicalDevice.h"
#include "CreateTextureImage.h"
#include "LoadModel.h"

/*
 * This file serves as the primary entry point for managing all vertex
 * buffer-related operations, including creation, handling, and cleanup of
 * Vulkan vertex buffers.
 *
 * Key responsibilities of this file:
 * - Setting up Vulkan vertex buffers for rendering.
 * - Managing vertex buffer memory and data.
 * - Providing a namespace (`CreateVertexBuffer`) to encapsulate all
 * vertex buffer-related functionalities.
 */

namespace CreateVertexBuffer {
VkBuffer vertexBuffer;
VkDeviceMemory vertexBufferMemory;

void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size) {
    VkCommandBuffer commandBuffer =
        CreateTextureImage::beginSingleTimeCommands();

    VkBufferCopy copyRegion{};
    copyRegion.size = size;
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);

    CreateTextureImage::endSingleTimeCommands(commandBuffer);
}

// Function to create Vulkan vertex buffers
void createVertexBuffer() {
    VkDeviceSize bufferSize =
        sizeof(LoadModel::vertices[0]) * LoadModel::vertices.size();

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    CreateTextureImage::createBuffer(bufferSize,
                                     VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                                     VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                                         VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                     stagingBuffer, stagingBufferMemory);

    void* data;
    vkMapMemory(CreateLogicalDevice::device, stagingBufferMemory, 0, bufferSize,
                0, &data);
    memcpy(data, LoadModel::vertices.data(), (size_t)bufferSize);
    vkUnmapMemory(CreateLogicalDevice::device, stagingBufferMemory);

    CreateTextureImage::createBuffer(
        bufferSize,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, vertexBuffer, vertexBufferMemory);

    copyBuffer(stagingBuffer, vertexBuffer, bufferSize);

    vkDestroyBuffer(CreateLogicalDevice::device, stagingBuffer, nullptr);
    vkFreeMemory(CreateLogicalDevice::device, stagingBufferMemory, nullptr);
}

// Function to clean up Vulkan vertex buffer resources
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "CreateVertexBuffer Cleaned up successfully." << std::endl;
}

}  // namespace CreateVertexBuffer
