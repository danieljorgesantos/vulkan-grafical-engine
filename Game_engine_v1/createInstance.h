#ifndef CREATEINSTANCE_H
#define CREATEINSTANCE_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateInstance {

// Vulkan instance handle
extern VkInstance instance;

// Enable validation layers in debug builds
#ifdef NDEBUG
constexpr bool enableValidationLayers = false;  // Compile-time constant
#else
constexpr bool enableValidationLayers = true;  // Compile-time constant
#endif

// List of validation layers
extern const std::vector<const char*> validationLayers;

// Populate the debug messenger creation info structure
void populateDebugMessengerCreateInfo(
    VkDebugUtilsMessengerCreateInfoEXT& createInfo);

// Get the required Vulkan instance extensions for GLFW and validation layers
std::vector<const char*> getRequiredExtensions();

// Check if the requested validation layers are supported
bool checkValidationLayerSupport();

// Create a Vulkan instance
void createInstance();

}  // namespace CreateInstance

#endif  // CREATEINSTANCE_H
