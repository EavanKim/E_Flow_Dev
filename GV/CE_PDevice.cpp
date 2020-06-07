#include "CVulkan_Core.h"

CE_PDevice::CE_PDevice(std::string _Name)
	: GV_Module(_Name)
{
}

CE_PDevice::~CE_PDevice()
{
}

void CE_PDevice::pickPhysicalDevice(VkInstance _Instance, CE_Swapchain* _Surface)
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(_Instance, &deviceCount, nullptr);

	if (deviceCount == 0)
		throw std::runtime_error("failed to find GPUs with Vulkan Support!");

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(_Instance, &deviceCount, devices.data());

	for (const VkPhysicalDevice& device : devices)
	{
		if (isDeviceSuitable(device, _Surface))
		{
			m_PhysicalDevice = device;
			break;
		}
	}

	if (m_PhysicalDevice == VK_NULL_HANDLE)
		throw std::runtime_error("failed to find a suitable GPU!");
}

bool CE_PDevice::isDeviceSuitable(VkPhysicalDevice _device, CE_Swapchain* _Surface)
{
	QueueFamilyIndices indices = findQueueFamilies(_Surface);

	///
	//Swap Chain
	bool extensionSupported = checkDeviceExtensionSupport(_device);

	bool swapChainAdequate = false;
	if (extensionSupported)
	{
		SwapChainSupportDetails swapChainSupport = querySwapChainSupport(_device, _Surface);
		swapChainAdequate = swapChainSupport.isTakeData();
	}
	///

	///
	//ImageView
	VkPhysicalDeviceFeatures supportedFeatures;
	vkGetPhysicalDeviceFeatures(_device, &supportedFeatures);
	///

	return indices.isTakeData() && extensionSupported && swapChainAdequate && supportedFeatures.samplerAnisotropy;
}

int CE_PDevice::rateDeviceSuitablility()
{
	return 0;
}

bool CE_PDevice::checkDeviceExtensionSupport(VkPhysicalDevice _device)
{
	uint32_t extensionCount;
	vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> availableExtensions(extensionCount);
	vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, availableExtensions.data());

	std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

	for (const VkExtensionProperties& extension : availableExtensions)
		requiredExtensions.erase(extension.extensionName);

	return requiredExtensions.empty();
}

SwapChainSupportDetails CE_PDevice::querySwapChainSupport(VkPhysicalDevice _device, CE_Swapchain* _Surface)
{
	SwapChainSupportDetails details;

	vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_device, _Surface->GetSurface(), &details.capabilities);

	uint32_t formatCount;
	vkGetPhysicalDeviceSurfaceFormatsKHR(_device, _Surface->GetSurface(), &formatCount, nullptr);

	if (formatCount != 0)
	{
		details.formats.resize(formatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(_device, _Surface->GetSurface(), &formatCount, details.formats.data());
	}

	uint32_t presentModeCount;
	vkGetPhysicalDeviceSurfacePresentModesKHR(_device, _Surface->GetSurface(), &presentModeCount, nullptr);

	if (presentModeCount != 0)
	{
		details.presentModes.resize(presentModeCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(_device, _Surface->GetSurface(), &presentModeCount, details.presentModes.data());
	}

	return details;
}

QueueFamilyIndices CE_PDevice::findQueueFamilies(CE_Swapchain* _Surface)
{
	QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(m_PhysicalDevice, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(m_PhysicalDevice, &queueFamilyCount, queueFamilies.data());

	int Count = 0;
	for (const VkQueueFamilyProperties& queueFamily : queueFamilies)
	{
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			indices.graphicsFamily = Count;

		}

		///
		//Window Surface
		VkBool32 presentSupport = false;
		vkGetPhysicalDeviceSurfaceSupportKHR(m_PhysicalDevice, Count, _Surface->GetSurface(), &presentSupport);

		if (presentSupport)
			indices.presentFamily = Count;
		///

		if (indices.isTakeData())
			break;

		++Count;
	}

	return indices;
}

VkPhysicalDevice CE_PDevice::GetDevice()
{
	return m_PhysicalDevice;
}

void CE_PDevice::DestroyInstance(VkDevice _device)
{

}
