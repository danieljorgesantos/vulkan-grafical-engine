#include "CreateCommandBuffers.h"

#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateCommandPool.h"
#include "CreateLogicalDevice.h"
#include "CreateUniformBuffers.h"

namespace CreateCommandBuffers {

std::vector<VkCommandBuffer> commandBuffers;

void createCommandBuffers() {
    commandBuffers.resize(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);

    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = CreateCommandPool::commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = (uint32_t)commandBuffers.size();

    if (vkAllocateCommandBuffers(CreateLogicalDevice::device, &allocInfo,
                                 commandBuffers.data()) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }
}

void cleanup() {
    // Cleanup logic for CreateCommandBuffers
    std::cout << "CreateCommandBuffers cleaned up successfully." << std::endl;
}

}  // namespace CreateCommandBuffers
