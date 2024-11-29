#include "createUniformBuffers.h"

#include <iostream>
#include <vector>

#include "CreateLogicalDevice.h"
#include "CreateTextureImage.h"

namespace CreateUniformBuffers {

const int MAX_FRAMES_IN_FLIGHT = 2;

// Definition of Vulkan uniform buffer objects
std::vector<VkBuffer> uniformBuffers;
std::vector<VkDeviceMemory> uniformBuffersMemory;
std::vector<void*> uniformBuffersMapped;

void createUniformBuffers() {
    VkDeviceSize bufferSize = sizeof(UniformBufferObject);

    uniformBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    uniformBuffersMemory.resize(MAX_FRAMES_IN_FLIGHT);
    uniformBuffersMapped.resize(MAX_FRAMES_IN_FLIGHT);

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        CreateTextureImage::createBuffer(
            bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
                VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
            uniformBuffers[i], uniformBuffersMemory[i]);

        vkMapMemory(CreateLogicalDevice::device, uniformBuffersMemory[i], 0,
                    bufferSize, 0, &uniformBuffersMapped[i]);
    }
}

void cleanup() {
    // Cleanup logic for Vulkan uniform buffers
    std::cout << "Cleaning up uniform buffers..." << std::endl;

    // Example cleanup logic (replace with actual Vulkan cleanup):
    uniformBuffers.clear();
    uniformBuffersMemory.clear();
    uniformBuffersMapped.clear();

    std::cout << "Uniform buffers cleaned up successfully." << std::endl;
}

}  // namespace CreateUniformBuffers
