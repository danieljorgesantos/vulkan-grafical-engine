#ifndef CREATE_TEXTURE_IMAGE_VIEW_H
#define CREATE_TEXTURE_IMAGE_VIEW_H

#include <vulkan/vulkan.h>

namespace CreateTextureImageView {

// Vulkan texture image view object
extern VkImageView textureImageView;

// Function to create Vulkan texture image views
void createTextureImageView();

// Function to clean up Vulkan texture image view resources
void cleanup();
}  // namespace CreateTextureImageView

#endif  // CREATE_TEXTURE_IMAGE_VIEW_H
