#ifndef CREATEDESCRIPTORSETLAYOUT_H
#define CREATEDESCRIPTORSETLAYOUT_H

#include <vulkan/vulkan.h>

#include <array>
#include <stdexcept>

/*
 * Header file for the CreateDescriptorSetLayout namespace.
 * This namespace manages Vulkan descriptor set layouts, defining how
 * descriptors are structured and utilized within the graphics and compute
 * pipelines.
 */

namespace CreateDescriptorSetLayout {

// Vulkan descriptor set layout object
extern VkDescriptorSetLayout descriptorSetLayout;

/**
 * Creates the Vulkan descriptor set layout.
 * Sets up layout bindings and creates the Vulkan object.
 *
 * @throws std::runtime_error if the descriptor set layout creation fails.
 */
void createDescriptorSetLayout();

/**
 * Cleans up resources related to descriptor set layouts.
 * Should be called before shutting down the Vulkan application.
 */
void cleanup();

}  // namespace CreateDescriptorSetLayout

#endif  // CREATEDESCRIPTORSETLAYOUT_H
