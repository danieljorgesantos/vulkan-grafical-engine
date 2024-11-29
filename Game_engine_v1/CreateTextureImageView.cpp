#include <vulkan/vulkan.h>

#include <iostream>

#include "CreateImageViews.h"
#include "CreateTextureImage.h"

/*
 * This file serves as the primary entry point for managing all texture image
 * view-related operations, including creation, handling, and cleanup of Vulkan
 * texture image views.
 *
 * Key responsibilities of this file:
 * - Setting up Vulkan image views for texture resources.
 * - Managing Vulkan image view memory.
 * - Providing a namespace (`CreateTextureImageView`) to encapsulate all
 * texture image view-related functionalities.
 */

namespace CreateTextureImageView {

VkImageView textureImageView;

// Function to create Vulkan texture image views
void createTextureImageView() {
    std::cout << "Creating texture image view..." << std::endl;

    textureImageView = CreateImageViews::createImageView(
        CreateTextureImage::textureImage, VK_FORMAT_R8G8B8A8_SRGB,
        VK_IMAGE_ASPECT_COLOR_BIT, CreateTextureImage::mipLevels);

    if (textureImageView == VK_NULL_HANDLE) {
        throw std::runtime_error(
            "Failed to create texture image view. Handle is VK_NULL_HANDLE.");
    }

    // Sync the textureImageView back to CreateTextureImage
    CreateTextureImage::textureImageView = textureImageView;

    std::cout << "Texture image view created successfully: " << textureImageView
              << std::endl;
}

// Function to clean up Vulkan texture image view resources
void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "CreateTextureImageView Cleaned up successfully." << std::endl;
}

}  // namespace CreateTextureImageView
