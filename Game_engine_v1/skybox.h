#ifndef SKYBOX_H
#define SKYBOX_H

#include <vulkan/vulkan.h>

#include <string>

namespace Skybox {

// Skybox Vulkan resources
extern VkImage skyboxImage;
extern VkDeviceMemory skyboxImageMemory;
extern VkImageView skyboxImageView;
extern VkSampler skyboxSampler;
extern VkPipeline skyboxPipeline;
extern VkPipelineLayout skyboxPipelineLayout;
extern VkDescriptorSetLayout descriptorSetLayout;

// Number of mipmap levels
extern uint32_t mipLevels;

// Functions to initialize and manage the skybox
void createDescriptorSetLayout();
VkSampleCountFlagBits getSamples();
void createSkyboxImage(const std::string& filepath);
void createSkyboxImageView();
void createSkyboxSampler();
void createSkyboxPipeline();

// Cleanup function for skybox resources
void cleanup();

}  // namespace Skybox

#endif  // SKYBOX_H
