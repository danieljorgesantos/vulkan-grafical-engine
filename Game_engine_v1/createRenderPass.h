#ifndef CREATERENDERPASS_H
#define CREATERENDERPASS_H

#include <vulkan/vulkan.h>

#include <stdexcept>
#include <vector>

/*
 * Header file for the CreateRenderPass namespace.
 * This namespace is responsible for the creation and management of Vulkan
 * render passes. Render passes define the structure and operations for the
 * Vulkan graphics pipeline.
 */

namespace CreateRenderPass {

// Vulkan render pass object
extern VkRenderPass renderPass;

/**
 * Finds the most suitable Vulkan format from a list of candidates.
 *
 * @param candidates A list of VkFormat candidates to evaluate.
 * @param tiling The tiling mode of the image (linear or optimal).
 * @param features Required features for the format.
 * @return The most suitable VkFormat.
 * @throws std::runtime_error if no supported format is found.
 */
VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates,
                             VkImageTiling tiling,
                             VkFormatFeatureFlags features);

/**
 * Finds a suitable depth format for depth attachments.
 *
 * @return A VkFormat suitable for depth attachments.
 * @throws std::runtime_error if no supported format is found.
 */
VkFormat findDepthFormat();

/**
 * Creates the Vulkan render pass.
 * Sets up attachments, subpasses, and dependencies for the graphics pipeline.
 *
 * @throws std::runtime_error if the render pass creation fails.
 */
void createRenderPass();

/**
 * Cleans up resources related to the Vulkan render pass.
 * Should be called before shutting down the Vulkan application.
 */
void cleanup();

}  // namespace CreateRenderPass

#endif  // CREATERENDERPASS_H
