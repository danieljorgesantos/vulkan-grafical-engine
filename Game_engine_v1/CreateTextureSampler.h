#ifndef CREATE_TEXTURE_SAMPLER_H
#define CREATE_TEXTURE_SAMPLER_H

#include <vulkan/vulkan.h>

namespace CreateTextureSampler {

// Vulkan texture sampler object
extern VkSampler textureSampler;

// Function to create Vulkan texture samplers
void createTextureSampler();

// Function to clean up Vulkan texture sampler resources
void cleanup();
}  // namespace CreateTextureSampler

#endif  // CREATE_TEXTURE_SAMPLER_H
