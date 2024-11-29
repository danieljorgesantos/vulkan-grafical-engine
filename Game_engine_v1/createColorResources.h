#ifndef CREATE_COLOR_RESOURCES_H
#define CREATE_COLOR_RESOURCES_H

#include <vulkan/vulkan.h>

#include <iostream>

/*
 * This file serves as the header file for the `CreateColorResources` namespace.
 * It provides function declarations for creating and managing Vulkan color
 * resources, including color image views and memory management.
 *
 * Key responsibilities:
 * - Encapsulating Vulkan color resource creation logic.
 * - Offering utility functions for image creation and memory type selection.
 * - Managing cleanup of allocated resources.
 */

namespace CreateColorResources {

// Vulkan handles for color resources
extern VkImage colorImage;
extern VkDeviceMemory colorImageMemory;
extern VkImageView colorImageView;

// Function to create image views for swapchain images
void createImageViews();

// Utility function to find a suitable memory type
uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

// Function to create a Vulkan image
void createImage(uint32_t width, uint32_t height, uint32_t mipLevels,
                 VkSampleCountFlagBits numSamples, VkFormat format,
                 VkImageTiling tiling, VkImageUsageFlags usage,
                 VkMemoryPropertyFlags properties, VkImage& image,
                 VkDeviceMemory& imageMemory);

// Function to create color resources
void createColorResources();

// Function to clean up color resources
void cleanup();

}  // namespace CreateColorResources

#endif  // CREATE_COLOR_RESOURCES_H
