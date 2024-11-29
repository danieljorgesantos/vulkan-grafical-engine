#ifndef CREATE_UNIFORM_BUFFERS_H
#define CREATE_UNIFORM_BUFFERS_H

#include <vulkan/vulkan.h>

#include <vector>

#include "glm_includes.h"

/*
 * The CreateUniformBuffers namespace provides functionalities
 * related to creating and managing Vulkan uniform buffers.
 *
 * Key responsibilities:
 * - Initializing uniform buffers for rendering.
 * - Cleaning up uniform buffer resources.
 */

namespace CreateUniformBuffers {

extern const int
    MAX_FRAMES_IN_FLIGHT;  // Declared as extern to avoid redefinition errors

// Structure for the Uniform Buffer Object
struct UniformBufferObject {
    alignas(16) glm::mat4 model;
    alignas(16) glm::mat4 view;
    alignas(16) glm::mat4 proj;
};

// Vulkan uniform buffer objects
extern std::vector<VkBuffer> uniformBuffers;
extern std::vector<VkDeviceMemory> uniformBuffersMemory;
extern std::vector<void*> uniformBuffersMapped;

// Function to create uniform buffers
void createUniformBuffers();

// Function to clean up uniform buffer resources
void cleanup();

}  // namespace CreateUniformBuffers

#endif  // CREATE_UNIFORM_BUFFERS_H
