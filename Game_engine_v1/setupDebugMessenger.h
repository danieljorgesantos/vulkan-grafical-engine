#ifndef SETUPDEBUGMESSENGER_H
#define SETUPDEBUGMESSENGER_H

#include <vulkan/vulkan.h>

#include <iostream>

namespace SetupDebugMessenger {

// Vulkan debug messenger handle
extern VkDebugUtilsMessengerEXT debugMessenger;

// Callback function for debug messages
VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT messageType,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

// Create a Vulkan Debug Utils Messenger
VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger);

// Populate the debug messenger creation info structure
void populateDebugMessengerCreateInfo(
    VkDebugUtilsMessengerCreateInfoEXT& createInfo);

// Setup the debug messenger
void setupDebugMessenger(VkInstance instance);

// Initialize the debug messenger
void initializeDebugMessenger();

// Cleanup the debug messenger
void cleanupDebugMessenger();

}  // namespace SetupDebugMessenger

#endif  // SETUPDEBUGMESSENGER_H
