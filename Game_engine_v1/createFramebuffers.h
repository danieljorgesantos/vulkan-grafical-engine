#ifndef CREATE_FRAMEBUFFERS_H
#define CREATE_FRAMEBUFFERS_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateFramebuffers {

// Vector to hold swap chain framebuffers
extern std::vector<VkFramebuffer> swapChainFramebuffers;

// Function to create framebuffers for the swap chain images
void createFramebuffers();

// Function to clean up resources associated with framebuffers
void cleanup();
}  // namespace CreateFramebuffers

#endif  // CREATE_FRAMEBUFFERS_H
