#ifndef CREATE_LOGICAL_DEVICE_H
#define CREATE_LOGICAL_DEVICE_H

#include <vulkan/vulkan.h>

#include <vector>

namespace CreateLogicalDevice {

// Vulkan handles for queues and logical device
extern VkQueue graphicsQueue;
extern VkQueue presentQueue;
extern VkDevice device;

// Function to create the logical device
void createLogicalDevice();

// Function to clean up resources related to the logical device
void cleanup();

}  // namespace CreateLogicalDevice

#endif  // CREATE_LOGICAL_DEVICE_H
