#include "CreateDescriptorSets.h"

#include <vulkan/vulkan.h>

#include <array>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "CreateDescriptorPool.h"
#include "CreateDescriptorSetLayout.h"
#include "CreateLogicalDevice.h"
#include "CreateTextureImage.h"
#include "CreateTextureSampler.h"
#include "CreateUniformBuffers.h"

namespace CreateDescriptorSets {

std::vector<VkDescriptorSet> descriptorSets;

void createDescriptorSets() {
    std::vector<VkDescriptorSetLayout> layouts(
        CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT,
        CreateDescriptorSetLayout::descriptorSetLayout);
    VkDescriptorSetAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocInfo.descriptorPool = CreateDescriptorPool::descriptorPool;
    allocInfo.descriptorSetCount =
        static_cast<uint32_t>(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);
    allocInfo.pSetLayouts = layouts.data();

    descriptorSets.resize(CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT);
    if (vkAllocateDescriptorSets(CreateLogicalDevice::device, &allocInfo,
                                 descriptorSets.data()) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate descriptor sets!");
    }

    for (size_t i = 0; i < CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT; i++) {
        VkDescriptorBufferInfo bufferInfo{};
        bufferInfo.buffer = CreateUniformBuffers::uniformBuffers[i];
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(CreateUniformBuffers::UniformBufferObject);

        // Debugging: Check buffer info
        std::cout << "Buffer info for frame " << i << ":" << std::endl;
        std::cout << "  Buffer: " << bufferInfo.buffer << std::endl;
        if (bufferInfo.buffer == VK_NULL_HANDLE) {
            throw std::runtime_error("Uniform buffer is VK_NULL_HANDLE.");
        }

        VkDescriptorImageInfo imageInfo{};
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        imageInfo.imageView = CreateTextureImage::textureImageView;
        imageInfo.sampler = CreateTextureSampler::textureSampler;

        // Debugging: Check image info
        std::cout << "Image info for frame " << i << ":" << std::endl;
        std::cout << "  Image View: " << imageInfo.imageView << std::endl;
        std::cout << "  Sampler: " << imageInfo.sampler << std::endl;
        if (imageInfo.imageView == VK_NULL_HANDLE) {
            throw std::runtime_error("Texture image view is VK_NULL_HANDLE.");
        }
        if (imageInfo.sampler == VK_NULL_HANDLE) {
            throw std::runtime_error("Texture sampler is VK_NULL_HANDLE.");
        }

        std::array<VkWriteDescriptorSet, 2> descriptorWrites{};

        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[i];
        descriptorWrites[0].dstBinding = 0;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pBufferInfo = &bufferInfo;

        descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[1].dstSet = descriptorSets[i];
        descriptorWrites[1].dstBinding = 1;
        descriptorWrites[1].dstArrayElement = 0;
        descriptorWrites[1].descriptorType =
            VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorWrites[1].descriptorCount = 1;
        descriptorWrites[1].pImageInfo = &imageInfo;

        // Debugging: Log descriptor writes
        std::cout << "Updating descriptor set for frame " << i << ":"
                  << std::endl;
        std::cout << "  Descriptor Set: " << descriptorSets[i] << std::endl;

        vkUpdateDescriptorSets(CreateLogicalDevice::device,
                               static_cast<uint32_t>(descriptorWrites.size()),
                               descriptorWrites.data(), 0, nullptr);

        std::cout << "Descriptor set updated for frame " << i << std::endl;
    }
}

void cleanup() {
    // Cleanup logic for CreateDescriptorSets
    std::cout << "CreateDescriptorSets cleaned up successfully." << std::endl;
}

}  // namespace CreateDescriptorSets
