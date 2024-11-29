#ifndef VULKAN_H
#define VULKAN_H

namespace Vulkan {

// Initializes Vulkan by setting up the instance, debug messenger, surface,
// physical device, and logical device
void initialize();

// Cleans up Vulkan resources
void cleanup();

}  // namespace Vulkan

#endif  // VULKAN_H
