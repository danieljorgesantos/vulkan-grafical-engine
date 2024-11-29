#include "CreateSwapChain.h"

#include <vulkan/vulkan.h>

#include <vector>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "CreateLogicalDevice.h"
#include "CreateSurface.h"
#include "PickPhysicalDevice.h"
#include "window.h"

namespace CreateSwapChain {

std::vector<VkImage> swapChainImages;
VkFormat swapChainImageFormat;
VkExtent2D swapChainExtent;
VkSwapchainKHR swapChain;

VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities) {
    if (capabilities.currentExtent.width !=
        std::numeric_limits<uint32_t>::max()) {
        return capabilities.currentExtent;
    } else {
        int width, height;
        glfwGetFramebufferSize(Window::window, &width, &height);

        VkExtent2D actualExtent = {static_cast<uint32_t>(width),
                                   static_cast<uint32_t>(height)};

        actualExtent.width =
            std::clamp(actualExtent.width, capabilities.minImageExtent.width,
                       capabilities.maxImageExtent.width);
        actualExtent.height =
            std::clamp(actualExtent.height, capabilities.minImageExtent.height,
                       capabilities.maxImageExtent.height);

        return actualExtent;
    }
}

VkPresentModeKHR chooseSwapPresentMode(
    const std::vector<VkPresentModeKHR>& availablePresentModes) {
    for (const auto& availablePresentMode : availablePresentModes) {
        if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR) {
            return availablePresentMode;
        }
    }

    return VK_PRESENT_MODE_FIFO_KHR;
}

VkSurfaceFormatKHR chooseSwapSurfaceFormat(
    const std::vector<VkSurfaceFormatKHR>& availableFormats) {
    for (const auto& availableFormat : availableFormats) {
        if (availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB &&
            availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
            return availableFormat;
        }
    }

    return availableFormats[0];
}

void createSwapChain() {
    // Query and retrieve the details of the swap chain support for the selected
    // physical device.
    // The function `querySwapChainSupport` is called, which gathers information
    // about the swap chain capabilities, formats, and presentation modes
    // supported by the `physicalDevice`. These details are stored in a
    // `SwapChainSupportDetails` structure for later use in configuring and
    // creating the swap chain.
    PickPhysicalDevice::SwapChainSupportDetails swapChainSupport =
        PickPhysicalDevice::querySwapChainSupport(
            PickPhysicalDevice::physicalDevice);

    // Choose the best surface format (color format and color space) from the
    // available formats supported by the swap chain. This typically involves
    // selecting an optimal combination (e.g., VK_FORMAT_B8G8R8A8_SRGB with
    // VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) for rendering.
    VkSurfaceFormatKHR surfaceFormat =
        chooseSwapSurfaceFormat(swapChainSupport.formats);

    // Select the presentation mode for the swap chain. The presentation mode
    // determines how images are queued for display. For example,
    // VK_PRESENT_MODE_FIFO_KHR is guaranteed to be supported, but others like
    // VK_PRESENT_MODE_MAILBOX_KHR might offer lower latency if available.
    VkPresentModeKHR presentMode =
        chooseSwapPresentMode(swapChainSupport.presentModes);

    // Determine the resolution of the swap chain images by selecting an extent
    // (width and height) that matches the capabilities of the surface. This
    // typically aligns with the resolution of the window or display where
    // rendering is presented.
    VkExtent2D extent = chooseSwapExtent(swapChainSupport.capabilities);

    uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;
    if (swapChainSupport.capabilities.maxImageCount > 0 &&
        imageCount > swapChainSupport.capabilities.maxImageCount) {
        imageCount = swapChainSupport.capabilities.maxImageCount;
    }

    VkSwapchainCreateInfoKHR createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    createInfo.surface = CreateSurface::surface;

    createInfo.minImageCount = imageCount;
    createInfo.imageFormat = surfaceFormat.format;
    createInfo.imageColorSpace = surfaceFormat.colorSpace;
    createInfo.imageExtent = extent;
    createInfo.imageArrayLayers = 1;
    createInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

    PickPhysicalDevice::QueueFamilyIndices indices =
        PickPhysicalDevice::findQueueFamilies(
            PickPhysicalDevice::physicalDevice);
    uint32_t queueFamilyIndices[] = {indices.graphicsFamily.value(),
                                     indices.presentFamily.value()};

    if (indices.graphicsFamily != indices.presentFamily) {
        createInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
        createInfo.queueFamilyIndexCount = 2;
        createInfo.pQueueFamilyIndices = queueFamilyIndices;
    } else {
        createInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    }

    createInfo.preTransform = swapChainSupport.capabilities.currentTransform;
    createInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    createInfo.presentMode = presentMode;
    createInfo.clipped = VK_TRUE;

    // This typically occurs when the logical device was not created properly
    // The swap chain extension (VK_KHR_swapchain) must be enabled when creating
    // the logical device:
    if (vkCreateSwapchainKHR(CreateLogicalDevice::device, &createInfo, nullptr,
                             &swapChain) != VK_SUCCESS) {
        throw std::runtime_error("failed to create swap chain!");
    }

    vkGetSwapchainImagesKHR(CreateLogicalDevice::device, swapChain, &imageCount,
                            nullptr);
    swapChainImages.resize(imageCount);
    vkGetSwapchainImagesKHR(CreateLogicalDevice::device, swapChain, &imageCount,
                            swapChainImages.data());

    swapChainImageFormat = surfaceFormat.format;
    swapChainExtent = extent;
}

void cleanup() {
    // Cleanup logic placeholder
    std::cout << "cleanup() CreateSwapChain resources cleaned up successfully."
              << std::endl;
}

}  // namespace CreateSwapChain
