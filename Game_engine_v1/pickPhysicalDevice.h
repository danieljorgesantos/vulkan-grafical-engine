#ifndef PICK_PHYSICAL_DEVICE_H
#define PICK_PHYSICAL_DEVICE_H

#include <vulkan/vulkan.h>

#include <optional>
#include <vector>

namespace PickPhysicalDevice {

// Structure to hold swap chain support details
struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

// Structure to hold queue family indices
struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    // Checks if all required queue families are present
    bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

// Vulkan handles and configuration values
extern VkPhysicalDevice physicalDevice;
extern VkSampleCountFlagBits msaaSamples;
extern const std::vector<const char*> deviceExtensions;

// Function declarations
SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
bool checkDeviceExtensionSupport(VkPhysicalDevice device);
VkSampleCountFlagBits getMaxUsableSampleCount();
QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
bool isDeviceSuitable(VkPhysicalDevice device);
void pickPhysicalDevice();
void initializePickPhysicalDevice();
void cleanup();

}  // namespace PickPhysicalDevice

#endif  // PICK_PHYSICAL_DEVICE_H
