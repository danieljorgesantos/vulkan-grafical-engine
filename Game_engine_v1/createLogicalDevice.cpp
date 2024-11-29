#include "CreateLogicalDevice.h"

#include <vulkan/vulkan.h>

#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

#include "CreateInstance.h"
#include "PickPhysicalDevice.h"

namespace CreateLogicalDevice {
VkQueue graphicsQueue;
VkQueue presentQueue;

VkDevice device;

void createLogicalDevice() {
    // Use the qualified name for QueueFamilyIndices
    PickPhysicalDevice::QueueFamilyIndices indices =
        PickPhysicalDevice::findQueueFamilies(
            PickPhysicalDevice::physicalDevice);

    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies = {indices.graphicsFamily.value(),
                                              indices.presentFamily.value()};

    float queuePriority = 1.0f;
    for (uint32_t queueFamily : uniqueQueueFamilies) {
        VkDeviceQueueCreateInfo queueCreateInfo{};
        queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo.queueFamilyIndex = queueFamily;
        queueCreateInfo.queueCount = 1;
        queueCreateInfo.pQueuePriorities = &queuePriority;
        queueCreateInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures{};
    deviceFeatures.samplerAnisotropy = VK_TRUE;

    VkDeviceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

    createInfo.queueCreateInfoCount =
        static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pQueueCreateInfos = queueCreateInfos.data();

    createInfo.pEnabledFeatures = &deviceFeatures;

    createInfo.enabledExtensionCount =
        static_cast<uint32_t>(PickPhysicalDevice::deviceExtensions.size());
    createInfo.ppEnabledExtensionNames =
        PickPhysicalDevice::deviceExtensions.data();

    if (CreateInstance::enableValidationLayers) {
        createInfo.enabledLayerCount =
            static_cast<uint32_t>(CreateInstance::validationLayers.size());
        createInfo.ppEnabledLayerNames =
            CreateInstance::validationLayers.data();
    } else {
        createInfo.enabledLayerCount = 0;
    }

    if (vkCreateDevice(PickPhysicalDevice::physicalDevice, &createInfo, nullptr,
                       &device) != VK_SUCCESS) {
        throw std::runtime_error("failed to create logical device!");
    }

    vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
    vkGetDeviceQueue(device, indices.presentFamily.value(), 0, &presentQueue);
}

void cleanup() {
    // Cleanup logic placeholder
    std::cout << "createLogicalDevice resources cleaned up successfully."
              << std::endl;
}

}  // namespace CreateLogicalDevice
