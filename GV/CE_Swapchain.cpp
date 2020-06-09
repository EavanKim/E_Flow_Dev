#include "CVulkan_Core.h"

CE_Swapchain::CE_Swapchain(std::string _Name)
	: GV_Module(_Name)
{
}

CE_Swapchain::~CE_Swapchain()
{
}

VkSurfaceKHR CE_Swapchain::GetSurface()
{
	return m_Surface;
}

void CE_Swapchain::createSurface(VkInstance _Vk, CE_Window* _Window)
{
	if (glfwCreateWindowSurface(_Vk, _Window->GetPoint(), nullptr, &m_Surface) != VK_SUCCESS)
		throw std::runtime_error("failed to create window surface!");
}

bool CE_Swapchain::checkDeviceExtensionSupport(VkPhysicalDevice _device)
{
	return false;
}

SwapChainSupportDetails CE_Swapchain::querySwapChainSupport(VkPhysicalDevice _device)
{
	return SwapChainSupportDetails();
}

VkSurfaceFormatKHR CE_Swapchain::chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& _availableFormats)
{
	return VkSurfaceFormatKHR();
}

VkPresentModeKHR CE_Swapchain::chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& _avaliablePresentModes)
{
	return VkPresentModeKHR();
}

VkExtent2D CE_Swapchain::chooseSwapExtent(const VkSurfaceCapabilitiesKHR& _capabilities)
{
	return VkExtent2D();
}

void CE_Swapchain::createSwapChain(CE_PDevice* _PDevice, CE_VDevice* _VDevice)
{
	SwapChainSupportDetails swapChainSupport = querySwapChainSupport(_PDevice->GetDevice());

	VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
	VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.presentModes);
	VkExtent2D extent = chooseSwapExtent(swapChainSupport.capabilities);

	uint32_t imageCount = swapChainSupport.capabilities.minImageCount + 1;

	if ((swapChainSupport.capabilities.maxImageCount > 0) && (imageCount > swapChainSupport.capabilities.maxImageCount))
		imageCount = swapChainSupport.capabilities.maxImageCount;

	VkSwapchainCreateInfoKHR swapChainInfo = {};

	swapChainInfo.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
	swapChainInfo.surface = m_Surface;

	swapChainInfo.minImageCount = imageCount;
	swapChainInfo.imageFormat = surfaceFormat.format;
	swapChainInfo.imageColorSpace = surfaceFormat.colorSpace;
	swapChainInfo.imageExtent = extent;
	swapChainInfo.imageArrayLayers = 1;
	swapChainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;

	QueueFamilyIndices indices = _PDevice->findQueueFamilies(this);
	uint32_t queueFamilyIndices[] = { indices.graphicsFamily.value(), indices.presentFamily.value() };

	if (indices.graphicsFamily != indices.presentFamily)
	{
		swapChainInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
		swapChainInfo.queueFamilyIndexCount = 2;
		swapChainInfo.pQueueFamilyIndices = queueFamilyIndices;
	}
	else
	{
		swapChainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
		//swapChainInfo.queueFamilyIndexCount = 0; //optional
		//swapChainInfo.pQueueFamilyIndices = nullptr; //optional
	}

	swapChainInfo.preTransform = swapChainSupport.capabilities.currentTransform;
	swapChainInfo.compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
	swapChainInfo.presentMode = presentMode;
	swapChainInfo.clipped = VK_TRUE;

	//swapChainInfo.oldSwapchain = VK_NULL_HANDLE;

	if (vkCreateSwapchainKHR(_VDevice->GetDevice(), &swapChainInfo, nullptr, &m_SwapChain) != VK_SUCCESS)
		throw std::runtime_error("failed to create swap chain!");

	vkGetSwapchainImagesKHR(_VDevice->GetDevice(), m_SwapChain, &imageCount, nullptr);
	m_SwapChainImages.resize(imageCount);
	vkGetSwapchainImagesKHR(_VDevice->GetDevice(), m_SwapChain, &imageCount, m_SwapChainImages.data());

	m_SwapChainImageFormat = surfaceFormat.format;
	m_SwapChainExtent = extent;
}

void CE_Swapchain::recreateSwapChain()
{
}

void CE_Swapchain::cleanupSwapChain()
{
}

void CE_Swapchain::framebufferResizeCallback(GLFWwindow* _window, int _width, int _height)
{
}

void CE_Swapchain::DestroyInstance(VkDevice _device)
{
}
