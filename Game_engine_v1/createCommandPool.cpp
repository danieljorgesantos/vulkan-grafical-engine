#include "CreateCommandPool.h"

#include "CreateLogicalDevice.h"
#include "PickPhysicalDevice.h"

/*
 * This file serves as the implementation file for the `CreateCommandPool`
 * namespace. It defines the functions declared in the corresponding header
 * file.
 */

namespace CreateCommandPool {

VkCommandPool commandPool;

void createCommandPool() {
    PickPhysicalDevice::QueueFamilyIndices queueFamilyIndices =
        PickPhysicalDevice::findQueueFamilies(
            PickPhysicalDevice::physicalDevice);

    VkCommandPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

    if (vkCreateCommandPool(CreateLogicalDevice::device, &poolInfo, nullptr,
                            &commandPool) != VK_SUCCESS) {
        throw std::runtime_error("failed to create graphics command pool!");
    }
}

void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "createCommandPool Cleaned up successfully." << std::endl;
}

}  // namespace CreateCommandPool
