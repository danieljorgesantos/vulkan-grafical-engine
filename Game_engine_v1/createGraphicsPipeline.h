#ifndef CREATEGRAPHICSPIPELINE_H
#define CREATEGRAPHICSPIPELINE_H

#include <vulkan/vulkan.h>

#include <vector>

/*
 * Header file for the CreateGraphicsPipeline namespace.
 * This namespace manages the creation and cleanup of Vulkan graphics pipelines.
 * Graphics pipelines define the stages and configuration for rendering.
 */

namespace CreateGraphicsPipeline {

// Vulkan pipeline objects
extern VkPipelineLayout pipelineLayout;
extern VkPipeline graphicsPipeline;

/**
 * Creates a Vulkan shader module from SPIR-V binary code.
 *
 * @param code The SPIR-V binary code for the shader.
 * @return The created VkShaderModule.
 * @throws std::runtime_error if shader module creation fails.
 */
VkShaderModule createShaderModule(const std::vector<char>& code);

/**
 * Creates the Vulkan graphics pipeline.
 * Sets up all pipeline stages, input states, and configurations.
 *
 * @throws std::runtime_error if graphics pipeline creation fails.
 */
void createGraphicsPipeline();

/**
 * Cleans up resources associated with the graphics pipeline.
 * Should be called during Vulkan application cleanup.
 */
void cleanup();

}  // namespace CreateGraphicsPipeline

#endif  // CREATEGRAPHICSPIPELINE_H
