#include "CVulkan_Core.h"

CE_VDevice::CE_VDevice(std::string _Name)
	: GV_Module(_Name)
{
}

CE_VDevice::~CE_VDevice()
{
}

void CE_VDevice::createLogicalDevice(CE_PDevice* _PhysicalDevice, CE_Swapchain* _Surface, bool _enableValidationLayers)
{
	QueueFamilyIndices indices = _PhysicalDevice->findQueueFamilies(_Surface);

	///
	//Window Surface
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	std::set<uint32_t> uniqueQueueFamilies = { indices.graphicsFamily.value(), indices.presentFamily.value() };

	float queuePriority = 1.0f;
	for (uint32_t queueFamily : uniqueQueueFamilies)
	{
		VkDeviceQueueCreateInfo queueCreateinfo = {};
		queueCreateinfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateinfo.queueFamilyIndex = queueFamily;
		queueCreateinfo.queueCount = 1;
		queueCreateinfo.pQueuePriorities = &queuePriority;
		queueCreateInfos.push_back(queueCreateinfo);
	}

	///
	VkPhysicalDeviceFeatures deviceFeatures = {};
	deviceFeatures.samplerAnisotropy = VK_TRUE;

	VkDeviceCreateInfo LogicalDevInfo = {};
	LogicalDevInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	LogicalDevInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	LogicalDevInfo.pQueueCreateInfos = queueCreateInfos.data();

	LogicalDevInfo.pEnabledFeatures = &deviceFeatures;

	///
	//Swap Chain
	LogicalDevInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
	LogicalDevInfo.ppEnabledExtensionNames = deviceExtensions.data();
	///

	if (_enableValidationLayers)
	{
		LogicalDevInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		LogicalDevInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else
	{
		LogicalDevInfo.enabledLayerCount = 0;
	}

	if (vkCreateDevice(_PhysicalDevice->GetDevice(), &LogicalDevInfo, nullptr, &m_Device) != VK_SUCCESS)
		throw std::runtime_error("failed to create logical device!");

	vkGetDeviceQueue(m_Device, indices.graphicsFamily.value(), 0, &m_GraphicsQueue);
	vkGetDeviceQueue(m_Device, indices.presentFamily.value(), 0, &m_PresentQueue);
}

void CE_VDevice::DestroyInstance(VkDevice _device)
{

}
