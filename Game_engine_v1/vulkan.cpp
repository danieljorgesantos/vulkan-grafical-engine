#include "Vulkan.h"

#include <iostream>
#include <stdexcept>

#include "CreateColorResources.h"
#include "CreateCommandBuffers.h"
#include "CreateCommandPool.h"
#include "CreateDepthResources.h"
#include "CreateDescriptorPool.h"
#include "CreateDescriptorSetLayout.h"
#include "CreateDescriptorSets.h"
#include "CreateFramebuffers.h"
#include "CreateGraphicsPipeline.h"
#include "CreateImageViews.h"
#include "CreateIndexBuffer.h"
#include "CreateInstance.h"
#include "CreateLogicalDevice.h"
#include "CreateRenderPass.h"
#include "CreateSurface.h"
#include "CreateSwapChain.h"
#include "CreateSyncObjects.h"
#include "CreateTextureImage.h"
#include "CreateTextureImageView.h"
#include "CreateTextureSampler.h"
#include "CreateUniformBuffers.h"
#include "CreateVertexBuffer.h"
#include "LoadModel.h"
#include "PickPhysicalDevice.h"
#include "SetupDebugMessenger.h"
#include "Skybox.h"

namespace Vulkan {

void initialize() {
    CreateInstance::createInstance();
    SetupDebugMessenger::initializeDebugMessenger();
    CreateSurface::initializeCreateSurface();
    PickPhysicalDevice::initializePickPhysicalDevice();
    CreateLogicalDevice::createLogicalDevice();
    CreateSwapChain::createSwapChain();
    CreateImageViews::createImageViews();
    CreateRenderPass::createRenderPass();
    CreateDescriptorSetLayout::createDescriptorSetLayout();
    CreateGraphicsPipeline::createGraphicsPipeline();
    CreateCommandPool::createCommandPool();
    CreateColorResources::createColorResources();
    CreateDepthResources::createDepthResources();
    CreateFramebuffers::createFramebuffers();
    CreateTextureImage::createTextureImage();
    CreateTextureImageView::createTextureImageView();
    CreateTextureSampler::createTextureSampler();
    LoadModel::loadModel();
    CreateVertexBuffer::createVertexBuffer();
    CreateIndexBuffer::createIndexBuffer();
    CreateUniformBuffers::createUniformBuffers();
    CreateDescriptorPool::createDescriptorPool();
    CreateDescriptorSets::createDescriptorSets();
    CreateCommandBuffers::createCommandBuffers();
    CreateSyncObjects::createSyncObjects();

    // Skybox Initialization
    std::cout << "Initializing Skybox..." << std::endl;
    Skybox::createDescriptorSetLayout();  // Create layout for uniform buffers
                                          // and sampler
    Skybox::createSkyboxImage("game/skybox/lisbon.jpg");
    Skybox::createSkyboxImageView();
    Skybox::createSkyboxSampler();
    Skybox::createSkyboxPipeline();
    std::cout << "Skybox initialized successfully!" << std::endl;
}

void cleanup() {
    if (CreateInstance::instance != VK_NULL_HANDLE) {
        vkDestroyInstance(CreateInstance::instance, nullptr);
        std::cout << "Vulkan instance destroyed." << std::endl;
    }
}

}  // namespace Vulkan
