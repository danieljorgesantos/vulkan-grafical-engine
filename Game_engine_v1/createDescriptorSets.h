#ifndef CREATE_DESCRIPTOR_SETS_H
#define CREATE_DESCRIPTOR_SETS_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateDescriptorSets {

// A vector to store the Vulkan descriptor sets
extern std::vector<VkDescriptorSet> descriptorSets;

// Creates descriptor sets and writes the necessary information to them
void createDescriptorSets();

// Cleans up resources related to descriptor sets
void cleanup();

}  // namespace CreateDescriptorSets

#endif  // CREATE_DESCRIPTOR_SETS_H
