#ifndef CREATE_SYNC_OBJECTS_H
#define CREATE_SYNC_OBJECTS_H

#include <vulkan/vulkan.h>

#include <vector>

/*
 * The CreateSyncObjects namespace provides functionalities
 * for creating and managing Vulkan synchronization objects.
 *
 * Key responsibilities:
 * - Creating semaphores and fences for frame synchronization.
 * - Cleaning up synchronization resources.
 */

namespace CreateSyncObjects {

// Synchronization primitives
extern std::vector<VkSemaphore> imageAvailableSemaphores;
extern std::vector<VkSemaphore> renderFinishedSemaphores;
extern std::vector<VkFence> inFlightFences;

// Function to create synchronization objects
void createSyncObjects();

// Function to clean up synchronization resources
void cleanup();

}  // namespace CreateSyncObjects

#endif  // CREATE_SYNC_OBJECTS_H
