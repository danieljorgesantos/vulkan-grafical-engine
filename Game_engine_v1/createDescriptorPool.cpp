#include "CreateDescriptorPool.h"

#include <vulkan/vulkan.h>

#include <array>
#include <iostream>
#include <stdexcept>

#include "CreateLogicalDevice.h"
#include "CreateUniformBuffers.h"

namespace CreateDescriptorPool {

VkDescriptorPool descriptorPool;

void createDescriptorPool() {
    std::array<VkDescriptorPoolSize, 2> poolSizes{};
    poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    poolSizes[0].descriptorCount =
        static_cast<uint32_t>(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);
    poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    poolSizes[1].descriptorCount =
        static_cast<uint32_t>(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);

    VkDescriptorPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
    poolInfo.pPoolSizes = poolSizes.data();
    poolInfo.maxSets =
        static_cast<uint32_t>(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);

    if (vkCreateDescriptorPool(CreateLogicalDevice::device, &poolInfo, nullptr,
                               &descriptorPool) != VK_SUCCESS) {
        throw std::runtime_error("failed to create descriptor pool!");
    }
}

void cleanup() {
    // Cleanup logic for CreateDescriptorPool
    std::cout << "CreateDescriptorPool cleaned up successfully." << std::endl;
}

}  // namespace CreateDescriptorPool
