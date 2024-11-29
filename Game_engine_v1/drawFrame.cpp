#include "DrawFrame.h"

#include <vulkan/vulkan.h>

#include <chrono>
#include <cstring>
#include <iostream>

#include "Camera.h"
#include "CreateColorResources.h"
#include "CreateCommandBuffers.h"
#include "CreateDepthResources.h"
#include "CreateDescriptorSets.h"
#include "CreateFramebuffers.h"
#include "CreateGraphicsPipeline.h"
#include "CreateImageViews.h"
#include "CreateIndexBuffer.h"
#include "CreateLogicalDevice.h"
#include "CreateRenderPass.h"
#include "CreateSwapChain.h"
#include "CreateSyncObjects.h"
#include "CreateUniformBuffers.h"
#include "CreateVertexBuffer.h"
#include "LoadModel.h"
#include "Window.h"
#include "glm_includes.h"

namespace DrawFrame {

uint32_t currentFrame = 0;

void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex) {
    VkCommandBufferBeginInfo beginInfo{};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    if (vkBeginCommandBuffer(commandBuffer, &beginInfo) != VK_SUCCESS) {
        throw std::runtime_error("failed to begin recording command buffer!");
    }

    VkRenderPassBeginInfo renderPassInfo{};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = CreateRenderPass::renderPass;
    renderPassInfo.framebuffer =
        CreateFramebuffers::swapChainFramebuffers[imageIndex];
    renderPassInfo.renderArea.offset = {0, 0};
    renderPassInfo.renderArea.extent = CreateSwapChain::swapChainExtent;

    std::array<VkClearValue, 2> clearValues{};
    clearValues[0].color = {{0.0f, 0.0f, 0.0f, 1.0f}};
    clearValues[1].depthStencil = {1.0f, 0};

    renderPassInfo.clearValueCount = static_cast<uint32_t>(clearValues.size());
    renderPassInfo.pClearValues = clearValues.data();

    vkCmdBeginRenderPass(commandBuffer, &renderPassInfo,
                         VK_SUBPASS_CONTENTS_INLINE);

    vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
                      CreateGraphicsPipeline::graphicsPipeline);

    VkViewport viewport{};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)CreateSwapChain::swapChainExtent.width;
    viewport.height = (float)CreateSwapChain::swapChainExtent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;
    vkCmdSetViewport(commandBuffer, 0, 1, &viewport);

    VkRect2D scissor{};
    scissor.offset = {0, 0};
    scissor.extent = CreateSwapChain::swapChainExtent;
    vkCmdSetScissor(commandBuffer, 0, 1, &scissor);

    VkBuffer vertexBuffers[] = {CreateVertexBuffer::vertexBuffer};
    VkDeviceSize offsets[] = {0};
    vkCmdBindVertexBuffers(commandBuffer, 0, 1, vertexBuffers, offsets);

    vkCmdBindIndexBuffer(commandBuffer, CreateIndexBuffer::indexBuffer, 0,
                         VK_INDEX_TYPE_UINT32);

    vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
                            CreateGraphicsPipeline::pipelineLayout, 0, 1,
                            &CreateDescriptorSets::descriptorSets[currentFrame],
                            0, nullptr);

    vkCmdDrawIndexed(commandBuffer,
                     static_cast<uint32_t>(LoadModel::indices.size()), 1, 0, 0,
                     0);

    vkCmdEndRenderPass(commandBuffer);

    if (vkEndCommandBuffer(commandBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to record command buffer!");
    }
}

void cleanupSwapChain() {
    vkDestroyImageView(CreateLogicalDevice::device,
                       CreateDepthResources::depthImageView, nullptr);
    vkDestroyImage(CreateLogicalDevice::device,
                   CreateDepthResources::depthImage, nullptr);
    vkFreeMemory(CreateLogicalDevice::device,
                 CreateDepthResources::depthImageMemory, nullptr);

    vkDestroyImageView(CreateLogicalDevice::device,
                       CreateColorResources::colorImageView, nullptr);
    vkDestroyImage(CreateLogicalDevice::device,
                   CreateColorResources::colorImage, nullptr);
    vkFreeMemory(CreateLogicalDevice::device,
                 CreateColorResources::colorImageMemory, nullptr);

    for (auto framebuffer : CreateFramebuffers::swapChainFramebuffers) {
        vkDestroyFramebuffer(CreateLogicalDevice::device, framebuffer, nullptr);
    }

    for (auto imageView : CreateImageViews::swapChainImageViews) {
        vkDestroyImageView(CreateLogicalDevice::device, imageView, nullptr);
    }

    vkDestroySwapchainKHR(CreateLogicalDevice::device,
                          CreateSwapChain::swapChain, nullptr);
}

void recreateSwapChain() {
    int width = 0, height = 0;
    glfwGetFramebufferSize(Window::window, &width, &height);
    while (width == 0 || height == 0) {
        glfwGetFramebufferSize(Window::window, &width, &height);
        glfwWaitEvents();
    }

    vkDeviceWaitIdle(CreateLogicalDevice::device);

    cleanupSwapChain();

    CreateSwapChain::createSwapChain();
    CreateImageViews::createImageViews();
    CreateColorResources::createColorResources();
    CreateDepthResources::createDepthResources();
    CreateFramebuffers::createFramebuffers();
}

void updateUniformBuffer(uint32_t currentImage) {
    static auto startTime = std::chrono::high_resolution_clock::now();

    auto currentTime = std::chrono::high_resolution_clock::now();
    float time = std::chrono::duration<float, std::chrono::seconds::period>(
                     currentTime - startTime)
                     .count();

    CreateUniformBuffers::UniformBufferObject ubo{};

    // Apply corrective rotation to fix the model's orientation
    ubo.model = glm::rotate(
        glm::mat4(1.0f), glm::radians(0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f));  // Rotate -90 degrees around X-axis

    // Use the camera's view matrix for the view transformation
    ubo.view = Camera::camera.getViewMatrix();

    // Set up a perspective projection
    ubo.proj =
        glm::perspective(glm::radians(45.0f),
                         CreateSwapChain::swapChainExtent.width /
                             (float)CreateSwapChain::swapChainExtent.height,
                         0.1f, 100.0f);
    ubo.proj[1][1] *= -1;  // Flip Y-axis for Vulkan's coordinate system

    // Copy the uniform buffer object data into the mapped memory
    memcpy(CreateUniformBuffers::uniformBuffersMapped[currentImage], &ubo,
           sizeof(ubo));
}

void drawFrame() {
    vkWaitForFences(CreateLogicalDevice::device, 1,
                    &CreateSyncObjects::inFlightFences[currentFrame], VK_TRUE,
                    UINT64_MAX);

    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(
        CreateLogicalDevice::device, CreateSwapChain::swapChain, UINT64_MAX,
        CreateSyncObjects::imageAvailableSemaphores[currentFrame],
        VK_NULL_HANDLE, &imageIndex);

    if (result == VK_ERROR_OUT_OF_DATE_KHR) {
        recreateSwapChain();
        return;
    } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        throw std::runtime_error("failed to acquire swap chain image!");
    }

    updateUniformBuffer(currentFrame);

    vkResetFences(CreateLogicalDevice::device, 1,
                  &CreateSyncObjects::inFlightFences[currentFrame]);

    vkResetCommandBuffer(CreateCommandBuffers::commandBuffers[currentFrame],
                         /*VkCommandBufferResetFlagBits*/ 0);
    recordCommandBuffer(CreateCommandBuffers::commandBuffers[currentFrame],
                        imageIndex);

    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {
        CreateSyncObjects::imageAvailableSemaphores[currentFrame]};
    VkPipelineStageFlags waitStages[] = {
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers =
        &CreateCommandBuffers::commandBuffers[currentFrame];

    VkSemaphore signalSemaphores[] = {
        CreateSyncObjects::renderFinishedSemaphores[currentFrame]};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(CreateLogicalDevice::graphicsQueue, 1, &submitInfo,
                      CreateSyncObjects::inFlightFences[currentFrame]) !=
        VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {CreateSwapChain::swapChain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;

    presentInfo.pImageIndices = &imageIndex;

    result = vkQueuePresentKHR(CreateLogicalDevice::presentQueue, &presentInfo);

    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR ||
        Window::context.framebufferResized) {  // Access via Window::context
        Window::context.framebufferResized = false;  // Reset the flag
        recreateSwapChain();
    } else if (result != VK_SUCCESS) {
        throw std::runtime_error("failed to present swap chain image!");
    }

    currentFrame =
        (currentFrame + 1) % CreateUniformBuffers::MAX_FRAMES_IN_FLIGHT;
}

void cleanup() {
    // Cleanup logic for DrawFrame
    std::cout << "DrawFrame cleaned up successfully." << std::endl;
}

}  // namespace DrawFrame
