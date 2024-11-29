#include "CreateColorResources.h"

#include <vulkan/vulkan.h>

#include "CreateImageViews.h"
#include "CreateLogicalDevice.h"
#include "CreateSwapChain.h"
#include "PickPhysicalDevice.h"

/*
 * This file serves as the implementation file for the `CreateColorResources`
 * namespace. It defines the functions declared in the corresponding header
 * file.
 */

namespace CreateColorResources {

VkImage colorImage;
VkDeviceMemory colorImageMemory;
VkImageView colorImageView;

void createImageViews() {
    CreateImageViews::swapChainImageViews.resize(
        CreateSwapChain::swapChainImages.size());

    for (uint32_t i = 0; i < CreateSwapChain::swapChainImages.size(); i++) {
        CreateImageViews::swapChainImageViews[i] =
            CreateImageViews::createImageView(
                CreateSwapChain::swapChainImages[i],
                CreateSwapChain::swapChainImageFormat,
                VK_IMAGE_ASPECT_COLOR_BIT, 1);
    }
}

uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(PickPhysicalDevice::physicalDevice,
                                        &memProperties);

    for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
        if ((typeFilter & (1 << i)) &&
            (memProperties.memoryTypes[i].propertyFlags & properties) ==
                properties) {
            return i;
        }
    }

    throw std::runtime_error("failed to find suitable memory type!");
}

void createImage(uint32_t width, uint32_t height, uint32_t mipLevels,
                 VkSampleCountFlagBits numSamples, VkFormat format,
                 VkImageTiling tiling, VkImageUsageFlags usage,
                 VkMemoryPropertyFlags properties, VkImage& image,
                 VkDeviceMemory& imageMemory) {
    VkImageCreateInfo imageInfo{};
    imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageInfo.imageType = VK_IMAGE_TYPE_2D;
    imageInfo.extent.width = width;
    imageInfo.extent.height = height;
    imageInfo.extent.depth = 1;
    imageInfo.mipLevels = mipLevels;
    imageInfo.arrayLayers = 1;
    imageInfo.format = format;
    imageInfo.tiling = tiling;
    imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    imageInfo.usage = usage;
    imageInfo.samples = numSamples;
    imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateImage(CreateLogicalDevice::device, &imageInfo, nullptr,
                      &image) != VK_SUCCESS) {
        throw std::runtime_error("failed to create image!");
    }

    VkMemoryRequirements memRequirements;
    vkGetImageMemoryRequirements(CreateLogicalDevice::device, image,
                                 &memRequirements);

    VkMemoryAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex =
        findMemoryType(memRequirements.memoryTypeBits, properties);

    if (vkAllocateMemory(CreateLogicalDevice::device, &allocInfo, nullptr,
                         &imageMemory) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate image memory!");
    }

    vkBindImageMemory(CreateLogicalDevice::device, image, imageMemory, 0);
}

void createColorResources() {
    VkFormat colorFormat = CreateSwapChain::swapChainImageFormat;

    createImage(
        CreateSwapChain::swapChainExtent.width,
        CreateSwapChain::swapChainExtent.height, 1,
        PickPhysicalDevice::msaaSamples, colorFormat, VK_IMAGE_TILING_OPTIMAL,
        VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT |
            VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, colorImage, colorImageMemory);
    colorImageView = CreateImageViews::createImageView(
        colorImage, colorFormat, VK_IMAGE_ASPECT_COLOR_BIT, 1);
}

void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "createColorResources Cleaned up successfully." << std::endl;
}

}  // namespace CreateColorResources
