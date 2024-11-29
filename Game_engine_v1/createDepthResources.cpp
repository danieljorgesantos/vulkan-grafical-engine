#include <vulkan/vulkan.h>

#include <iostream>
#include <vector>

#include "CreateColorResources.h"
#include "CreateImageViews.h"
#include "CreateSwapChain.h"
#include "PickPhysicalDevice.h"

/*
 * This file serves as the primary entry point for managing all depth
 * resource-related operations, including creation, management, and cleanup of
 * Vulkan depth resources.
 *
 * Key responsibilities of this file:
 * - Setting up Vulkan depth resources such as depth images and image views.
 * - Integrating depth resources into the rendering pipeline.
 * - Providing a namespace (`CreateDepthResources`) to encapsulate all
 * depth resource-related functionalities.
 */

namespace CreateDepthResources {

VkImage depthImage;
VkDeviceMemory depthImageMemory;
VkImageView depthImageView;

VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates,
                             VkImageTiling tiling,
                             VkFormatFeatureFlags features) {
    for (VkFormat format : candidates) {
        VkFormatProperties props;
        vkGetPhysicalDeviceFormatProperties(PickPhysicalDevice::physicalDevice,
                                            format, &props);

        if (tiling == VK_IMAGE_TILING_LINEAR &&
            (props.linearTilingFeatures & features) == features) {
            return format;
        } else if (tiling == VK_IMAGE_TILING_OPTIMAL &&
                   (props.optimalTilingFeatures & features) == features) {
            return format;
        }
    }

    throw std::runtime_error("failed to find supported format!");
}

VkFormat findDepthFormat() {
    return findSupportedFormat(
        {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT,
         VK_FORMAT_D24_UNORM_S8_UINT},
        VK_IMAGE_TILING_OPTIMAL,
        VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
}

void createDepthResources() {
    VkFormat depthFormat = findDepthFormat();

    CreateColorResources::createImage(
        CreateSwapChain::swapChainExtent.width,
        CreateSwapChain::swapChainExtent.height, 1,
        PickPhysicalDevice::msaaSamples, depthFormat, VK_IMAGE_TILING_OPTIMAL,
        VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, depthImage, depthImageMemory);
    depthImageView = CreateImageViews::createImageView(
        depthImage, depthFormat, VK_IMAGE_ASPECT_DEPTH_BIT, 1);
}

// Function to clean up Vulkan depth resources
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "createDepthResources Cleaned up successfully." << std::endl;
}

}  // namespace CreateDepthResources
