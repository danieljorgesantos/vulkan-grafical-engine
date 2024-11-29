#ifndef CREATE_TEXTURE_IMAGE_H
#define CREATE_TEXTURE_IMAGE_H

#include <vulkan/vulkan.h>

#include <string>

namespace CreateTextureImage {

// Vulkan texture image properties
extern uint32_t mipLevels;
extern VkImage textureImage;
extern VkDeviceMemory textureImageMemory;
extern VkImageView textureImageView;

// File paths for models and textures
extern const std::string MODEL_PATH;
extern const std::string TEXTURE_PATH;

// Function to find suitable memory type for Vulkan resources
uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

// Function to create Vulkan buffer and allocate memory
void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                  VkMemoryPropertyFlags properties, VkBuffer& buffer,
                  VkDeviceMemory& bufferMemory);

// Begins a one-time Vulkan command buffer for submission
VkCommandBuffer beginSingleTimeCommands();

// Ends and submits a one-time Vulkan command buffer
void endSingleTimeCommands(VkCommandBuffer commandBuffer);

// Transitions the layout of a Vulkan image
void transitionImageLayout(VkImage image, VkFormat format,
                           VkImageLayout oldLayout, VkImageLayout newLayout,
                           uint32_t mipLevels);

// Copies buffer data to a Vulkan image
void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                       uint32_t height);

// Generates mipmaps for a Vulkan image
void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
                     int32_t texHeight, uint32_t mipLevels);

// Creates a Vulkan texture image from a file
void createTextureImage();

// Cleans up Vulkan texture image resources
void cleanup();

}  // namespace CreateTextureImage

#endif  // CREATE_TEXTURE_IMAGE_H
