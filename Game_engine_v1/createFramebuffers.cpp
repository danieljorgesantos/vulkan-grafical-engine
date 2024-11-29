#include "CreateFramebuffers.h"

#include <vulkan/vulkan.h>

#include <array>
#include <iostream>
#include <vector>

#include "CreateColorResources.h"
#include "CreateDepthResources.h"
#include "CreateImageViews.h"
#include "CreateLogicalDevice.h"
#include "CreateRenderPass.h"
#include "CreateSwapChain.h"

/*
 * This file serves as the implementation file for the `CreateFramebuffers`
 * namespace. It defines the functions declared in the corresponding header
 * file.
 */
namespace CreateFramebuffers {
std::vector<VkFramebuffer> swapChainFramebuffers;

void createFramebuffers() {
    swapChainFramebuffers.resize(CreateImageViews::swapChainImageViews.size());

    for (size_t i = 0; i < CreateImageViews::swapChainImageViews.size(); i++) {
        std::array<VkImageView, 3> attachments = {
            CreateColorResources::colorImageView,
            CreateDepthResources::depthImageView,
            CreateImageViews::swapChainImageViews[i]};

        VkFramebufferCreateInfo framebufferInfo{};
        framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebufferInfo.renderPass = CreateRenderPass::renderPass;
        framebufferInfo.attachmentCount =
            static_cast<uint32_t>(attachments.size());
        framebufferInfo.pAttachments = attachments.data();
        framebufferInfo.width = CreateSwapChain::swapChainExtent.width;
        framebufferInfo.height = CreateSwapChain::swapChainExtent.height;
        framebufferInfo.layers = 1;

        if (vkCreateFramebuffer(CreateLogicalDevice::device, &framebufferInfo,
                                nullptr,
                                &swapChainFramebuffers[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create framebuffer!");
        }
    }
}

void cleanup() {
    // Placeholder for cleanup logic
    std::cout << "createFramebuffers Cleaned up successfully." << std::endl;
}

}  // namespace CreateFramebuffers
