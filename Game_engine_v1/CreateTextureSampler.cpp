#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateLogicalDevice.h"
#include "PickPhysicalDevice.h"

/*
 * This file serves as the primary entry point for managing all texture
 * sampler-related operations, including creation, handling, and cleanup of
 * Vulkan texture samplers.
 *
 * Key responsibilities of this file:
 * - Setting up Vulkan texture samplers for sampled images.
 * - Managing Vulkan sampler resources.
 * - Providing a namespace (`CreateTextureSampler`) to encapsulate all
 * texture sampler-related functionalities.
 */

namespace CreateTextureSampler {

VkSampler textureSampler;

// Function to create Vulkan texture samplers
void createTextureSampler() {
    VkPhysicalDeviceProperties properties{};
    vkGetPhysicalDeviceProperties(PickPhysicalDevice::physicalDevice,
                                  &properties);

    VkSamplerCreateInfo samplerInfo{};
    samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    samplerInfo.magFilter = VK_FILTER_LINEAR;
    samplerInfo.minFilter = VK_FILTER_LINEAR;
    samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.anisotropyEnable = VK_TRUE;
    samplerInfo.maxAnisotropy = properties.limits.maxSamplerAnisotropy;
    samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
    samplerInfo.unnormalizedCoordinates = VK_FALSE;
    samplerInfo.compareEnable = VK_FALSE;
    samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
    samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
    samplerInfo.minLod = 0.0f;
    samplerInfo.maxLod = VK_LOD_CLAMP_NONE;
    samplerInfo.mipLodBias = 0.0f;

    if (vkCreateSampler(CreateLogicalDevice::device, &samplerInfo, nullptr,
                        &textureSampler) != VK_SUCCESS) {
        throw std::runtime_error("failed to create texture sampler!");
    }
}

// Function to clean up Vulkan texture sampler resources
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "CreateTextureSampler Cleaned up successfully." << std::endl;
}

}  // namespace CreateTextureSampler
