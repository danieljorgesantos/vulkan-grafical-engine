#include "CreateSyncObjects.h"

#include <iostream>
#include <vector>

#include "CreateLogicalDevice.h"
#include "CreateUniformBuffers.h"

namespace CreateSyncObjects {

std::vector<VkSemaphore> imageAvailableSemaphores;
std::vector<VkSemaphore> renderFinishedSemaphores;
std::vector<VkFence> inFlightFences;

void createSyncObjects() {
    imageAvailableSemaphores.resize(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);
    renderFinishedSemaphores.resize(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);
    inFlightFences.resize(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(CreateLogicalDevice::device, &semaphoreInfo,
                              nullptr,
                              &imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(CreateLogicalDevice::device, &semaphoreInfo,
                              nullptr,
                              &renderFinishedSemaphores[i]) != VK_SUCCESS ||
            vkCreateFence(CreateLogicalDevice::device, &fenceInfo, nullptr,
                          &inFlightFences[i]) != VK_SUCCESS) {
            throw std::runtime_error(
                "failed to create synchronization objects for a frame!");
        }
    }
}

void cleanup() {
    // Cleanup logic for CreateSyncObjects
    std::cout << "CreateSyncObjects cleaned up successfully." << std::endl;
}

}  // namespace CreateSyncObjects
