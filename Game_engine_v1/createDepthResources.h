#ifndef CREATE_DEPTH_RESOURCES_H
#define CREATE_DEPTH_RESOURCES_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateDepthResources {

// Vulkan objects related to depth resources
extern VkImage depthImage;
extern VkDeviceMemory depthImageMemory;
extern VkImageView depthImageView;

// Finds a supported format for Vulkan depth resources
VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates,
                             VkImageTiling tiling,
                             VkFormatFeatureFlags features);

// Finds an appropriate depth format for Vulkan
VkFormat findDepthFormat();

// Creates Vulkan depth resources (image, memory, and view)
void createDepthResources();

// Cleans up Vulkan depth resources
void cleanup();
}  // namespace CreateDepthResources

#endif  // CREATE_DEPTH_RESOURCES_H
