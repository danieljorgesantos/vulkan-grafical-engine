#ifndef CREATEIMAGEVIEWS_H
#define CREATEIMAGEVIEWS_H

#include <vulkan/vulkan.h>

#include <vector>

/*
 * Header file for the CreateImageViews namespace.
 * This namespace provides utilities to handle Vulkan image view creation and
 * management. Image views are essential for enabling Vulkan to interpret images
 * for rendering and shaders.
 */

namespace CreateImageViews {

// Vector to store image views corresponding to the swap chain images
extern std::vector<VkImageView> swapChainImageViews;

/**
 * Creates a Vulkan image view.
 *
 * @param image The Vulkan image for which the image view is created.
 * @param format The format of the image.
 * @param aspectFlags The aspect mask to specify which aspect of the image is
 * used (e.g., color).
 * @param mipLevels The number of mipmap levels.
 * @return A handle to the created VkImageView.
 * @throws std::runtime_error if image view creation fails.
 */
VkImageView createImageView(VkImage image, VkFormat format,
                            VkImageAspectFlags aspectFlags, uint32_t mipLevels);

/**
 * Creates image views for all swap chain images.
 *
 * @throws std::runtime_error if any image view creation fails.
 */
void createImageViews();

/**
 * Cleans up Vulkan image views associated with the swap chain.
 *
 * @note This function should be called during cleanup to free allocated
 * resources.
 */
void cleanup();

}  // namespace CreateImageViews

#endif  // CREATEIMAGEVIEWS_H
