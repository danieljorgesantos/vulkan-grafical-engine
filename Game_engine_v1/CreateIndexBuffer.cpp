#include "CreateIndexBuffer.h"

#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateLogicalDevice.h"
#include "CreateTextureImage.h"
#include "CreateVertexBuffer.h"
#include "LoadModel.h"

namespace CreateIndexBuffer {

VkBuffer indexBuffer;
VkDeviceMemory indexBufferMemory;

void createIndexBuffer() {
    VkDeviceSize bufferSize =
        sizeof(LoadModel::indices[0]) * LoadModel::indices.size();

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
    memcpy(data, LoadModel::indices.data(), (size_t)bufferSize);
    vkUnmapMemory(CreateLogicalDevice::device, stagingBufferMemory);

    CreateTextureImage::createBuffer(
        bufferSize,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, indexBuffer, indexBufferMemory);

    CreateVertexBuffer::copyBuffer(stagingBuffer, indexBuffer, bufferSize);

    vkDestroyBuffer(CreateLogicalDevice::device, stagingBuffer, nullptr);
    vkFreeMemory(CreateLogicalDevice::device, stagingBufferMemory, nullptr);
}
void cleanup() {
    // Cleanup logic for CreateIndexBuffer
    std::cout << "CreateIndexBuffer cleaned up successfully." << std::endl;
}

}  // namespace CreateIndexBuffer
