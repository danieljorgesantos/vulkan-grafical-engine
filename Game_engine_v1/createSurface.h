#ifndef CREATESURFACE_H
#define CREATESURFACE_H

#include <vulkan/vulkan.h>

namespace CreateSurface {

// Vulkan surface handle
extern VkSurfaceKHR surface;

// Initialize the CreateSurface system
void initializeCreateSurface();

// Create a Vulkan surface
void createSurface();

// Cleanup the CreateSurface system
void cleanup();

}  // namespace CreateSurface

#endif  // CREATESURFACE_H
