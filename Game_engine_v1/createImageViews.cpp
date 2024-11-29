#include "CreateImageViews.h"

#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>

#include "CreateLogicalDevice.h"
#include "CreateSwapChain.h"

/*
 * This file is dedicated to handling the creation and management of image views
 * within the Vulkan rendering pipeline. Image views are crucial for enabling
 * Vulkan to interpret image resources for rendering and shader access.
 *
 * Key responsibilities of this file:
 * - Providing utilities for creating and managing Vulkan image views.
 * - Ensuring compatibility with the Vulkan graphics pipeline.
 * - Maintaining modularity by encapsulating functionalities in a dedicated
 * namespace (`CreateImageViews`).
 */

namespace CreateImageViews {

std::vector<VkImageView> swapChainImageViews;

VkImageView createImageView(VkImage image, VkFormat format,
                            VkImageAspectFlags aspectFlags,
                            uint32_t mipLevels) {
    VkImageViewCreateInfo viewInfo{};
    viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    viewInfo.image = image;
    viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    viewInfo.format = format;
    viewInfo.subresourceRange.aspectMask = aspectFlags;
    viewInfo.subresourceRange.baseMipLevel = 0;
    viewInfo.subresourceRange.levelCount = mipLevels;
    viewInfo.subresourceRange.baseArrayLayer = 0;
    viewInfo.subresourceRange.layerCount = 1;

    VkImageView imageView;
    if (vkCreateImageView(CreateLogicalDevice::device, &viewInfo, nullptr,
                          &imageView) != VK_SUCCESS) {
        throw std::runtime_error("failed to create image view!");
    }

    return imageView;
}

void createImageViews() {
    swapChainImageViews.resize(CreateSwapChain::swapChainImages.size());

    for (uint32_t i = 0; i < CreateSwapChain::swapChainImages.size(); i++) {
        swapChainImageViews[i] =
            createImageView(CreateSwapChain::swapChainImages[i],
                            CreateSwapChain::swapChainImageFormat,
                            VK_IMAGE_ASPECT_COLOR_BIT, 1);
    }
}

// Function to cleanup resources related to CreateImageViews
void cleanup() {
    std::cout << "cleanup() CreateImageViews systems cleaned up successfully."
              << std::endl;
}

}  // namespace CreateImageViews
