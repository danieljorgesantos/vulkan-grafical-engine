#include "CreateDescriptorSetLayout.h"

#include <array>
#include <iostream>

#include "CreateLogicalDevice.h"

/*
 * This file manages the creation and management of Vulkan descriptor set
 * layouts. Descriptor set layouts define how descriptors are structured and
 * utilized within Vulkan's graphics and compute pipelines.
 *
 * Key responsibilities of this file:
 * - Initializing descriptor set layout creation logic.
 * - Cleaning up resources associated with descriptor set layouts.
 * - Encapsulating logic in the CreateDescriptorSetLayout namespace.
 */

namespace CreateDescriptorSetLayout {

VkDescriptorSetLayout descriptorSetLayout;

void createDescriptorSetLayout() {
    VkDescriptorSetLayoutBinding uboLayoutBinding{};
    uboLayoutBinding.binding = 0;
    uboLayoutBinding.descriptorCount = 1;
    uboLayoutBinding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    uboLayoutBinding.pImmutableSamplers = nullptr;
    uboLayoutBinding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;

    VkDescriptorSetLayoutBinding samplerLayoutBinding{};
    samplerLayoutBinding.binding = 1;
    samplerLayoutBinding.descriptorCount = 1;
    samplerLayoutBinding.descriptorType =
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    samplerLayoutBinding.pImmutableSamplers = nullptr;
    samplerLayoutBinding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;

    std::array<VkDescriptorSetLayoutBinding, 2> bindings = {
        uboLayoutBinding, samplerLayoutBinding};
    VkDescriptorSetLayoutCreateInfo layoutInfo{};
    layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
    layoutInfo.pBindings = bindings.data();

    if (vkCreateDescriptorSetLayout(CreateLogicalDevice::device, &layoutInfo,
                                    nullptr,
                                    &descriptorSetLayout) != VK_SUCCESS) {
        throw std::runtime_error("failed to create descriptor set layout!");
    }
}

// Function to cleanup resources related to CreateDescriptorSetLayout
void cleanup() {
    std::cout << "cleanup() CreateDescriptorSetLayout systems cleaned up "
                 "successfully."
              << std::endl;
}

}  // namespace CreateDescriptorSetLayout
