#ifndef CREATE_SWAP_CHAIN_H
#define CREATE_SWAP_CHAIN_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateSwapChain {

// Vulkan swap chain handles and properties
extern std::vector<VkImage> swapChainImages;
extern VkFormat swapChainImageFormat;
extern VkExtent2D swapChainExtent;
extern VkSwapchainKHR swapChain;

// Function to choose the best swap chain extent based on capabilities
VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

// Function to choose the best swap chain present mode
VkPresentModeKHR chooseSwapPresentMode(
    const std::vector<VkPresentModeKHR>& availablePresentModes);

// Function to choose the best swap chain surface format
VkSurfaceFormatKHR chooseSwapSurfaceFormat(
    const std::vector<VkSurfaceFormatKHR>& availableFormats);

// Function to create the Vulkan swap chain
void createSwapChain();

// Function to clean up resources related to the swap chain
void cleanup();

}  // namespace CreateSwapChain

#endif  // CREATE_SWAP_CHAIN_H
