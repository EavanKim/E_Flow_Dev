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
	uint32_t extensionCount;
	vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, nullptr);

	std::vector<VkExtensionProperties> availableExtensions(extensionCount);
	vkEnumerateDeviceExtensionProperties(_device, nullptr, &extensionCount, availableExtensions.data());

	std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

	for (const VkExtensionProperties& extension : availableExtensions)
		requiredExtensions.erase(extension.extensionName);

	return requiredExtensions.empty();
}

SwapChainSupportDetails CE_Swapchain::querySwapChainSupport(VkPhysicalDevice _device)
{
	SwapChainSupportDetails details;

	vkGetPhysicalDeviceSurfaceCapabilitiesKHR(_device, m_Surface, &details.capabilities);

	uint32_t formatCount;
	vkGetPhysicalDeviceSurfaceFormatsKHR(_device, m_Surface, &formatCount, nullptr);

	if (formatCount != 0)
	{
		details.formats.resize(formatCount);
		vkGetPhysicalDeviceSurfaceFormatsKHR(_device, m_Surface, &formatCount, details.formats.data());
	}

	uint32_t presentModeCount;
	vkGetPhysicalDeviceSurfacePresentModesKHR(_device, m_Surface, &presentModeCount, nullptr);

	if (presentModeCount != 0)
	{
		details.presentModes.resize(presentModeCount);
		vkGetPhysicalDeviceSurfacePresentModesKHR(_device, m_Surface, &presentModeCount, details.presentModes.data());
	}

	return details;
}

VkSurfaceFormatKHR CE_Swapchain::chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& _availableFormats)
{
	for (const VkSurfaceFormatKHR& availableFormat : _availableFormats)
	{
		if ((availableFormat.format == VK_FORMAT_B8G8R8A8_SRGB) && (availableFormat.colorSpace == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR))
			return availableFormat;
	}

	return _availableFormats[0];
}

VkPresentModeKHR CE_Swapchain::chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& _avaliablePresentModes)
{
	for (const VkPresentModeKHR& availablePresentMode : _avaliablePresentModes)
	{
		if (availablePresentMode == VK_PRESENT_MODE_MAILBOX_KHR)
			return availablePresentMode;
	}

	return VK_PRESENT_MODE_FIFO_KHR;
}

VkExtent2D CE_Swapchain::chooseSwapExtent(CE_Window* _Window, const VkSurfaceCapabilitiesKHR& _capabilities)
{
	if (_capabilities.currentExtent.width != UINT32_MAX)
		return _capabilities.currentExtent;
	else
	{
		int width, height;

		glfwGetFramebufferSize(_Window->GetPoint(), &width, &height);

		//VkExtent2D actualExtent = {m_WindowWidth, m_WindowHeight};

		VkExtent2D actualExtent = { static_cast<uint32_t>(width), static_cast<uint32_t>(height) };

		actualExtent.width = std::max(_capabilities.minImageExtent.width, std::min(_capabilities.maxImageExtent.width, actualExtent.width));
		actualExtent.height = std::max(_capabilities.minImageExtent.height, std::min(_capabilities.maxImageExtent.height, actualExtent.height));

		return actualExtent;
	}
}

void CE_Swapchain::createSwapChain(CE_Window* _Window, CE_PDevice* _PDevice, CE_VDevice* _VDevice)
{
	SwapChainSupportDetails swapChainSupport = querySwapChainSupport(_PDevice->GetDevice());

	VkSurfaceFormatKHR surfaceFormat = chooseSwapSurfaceFormat(swapChainSupport.formats);
	VkPresentModeKHR presentMode = chooseSwapPresentMode(swapChainSupport.presentModes);
	VkExtent2D extent = chooseSwapExtent(_Window, swapChainSupport.capabilities);

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

void CE_Swapchain::createImageViews(CE_VDevice* _Device)
{
	m_SwapChainImageViews.resize(m_SwapChainImages.size());

	//for (size_t Count = 0; m_SwapChainImages.size() > Count; ++Count)
	//{
	//	VkImageViewCreateInfo ImageViewInfo = {};

	//	ImageViewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	//	ImageViewInfo.image = m_SwapChainImages[Count];

	//	ImageViewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
	//	ImageViewInfo.format = m_SwapChainImageFormat;

	//	ImageViewInfo.components.r = VK_COMPONENT_SWIZZLE_IDENTITY;
	//	ImageViewInfo.components.g = VK_COMPONENT_SWIZZLE_IDENTITY;
	//	ImageViewInfo.components.b = VK_COMPONENT_SWIZZLE_IDENTITY;
	//	ImageViewInfo.components.a = VK_COMPONENT_SWIZZLE_IDENTITY;

	//	ImageViewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
	//	ImageViewInfo.subresourceRange.baseMipLevel = 0;
	//	ImageViewInfo.subresourceRange.layerCount = 1;
	//	ImageViewInfo.subresourceRange.baseArrayLayer = 0;
	//	ImageViewInfo.subresourceRange.layerCount = 1;

	//	if (vkCreateImageView(m_Device, &ImageViewInfo, nullptr, &m_SwapChainImageViews[Count]) != VK_SUCCESS)
	//		throw std::runtime_error("failed to create image views!");
	//}

	///
	//Imageview
	//for (uint32_t Count = 0; m_SwapChainImages.size() > Count; ++Count)
	//	m_SwapChainImageViews[Count] = createImageView(m_SwapChainImages[Count], m_SwapChainImageFormat);
	///

	///
	//Depth buffers
	for (uint32_t Count = 0; m_SwapChainImages.size() > Count; ++Count)
		m_SwapChainImageViews[Count] = createImageView(_Device, m_SwapChainImages[Count], m_SwapChainImageFormat, VK_IMAGE_ASPECT_COLOR_BIT);
	///
}

VkImageView CE_Swapchain::createImageView(CE_VDevice* _Device, VkImage _image, VkFormat _format, VkImageAspectFlags _aspectFlages)
{
	VkImageViewCreateInfo viewInfo = {};
	viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
	viewInfo.image = _image;
	viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
	viewInfo.format = _format;
	viewInfo.subresourceRange.aspectMask = _aspectFlages;
	viewInfo.subresourceRange.baseMipLevel = 0;
	viewInfo.subresourceRange.levelCount = 1;
	viewInfo.subresourceRange.baseArrayLayer = 0;
	viewInfo.subresourceRange.layerCount = 1;

	VkImageView imageView = VK_NULL_HANDLE;
	if (vkCreateImageView(_Device->GetDevice(), &viewInfo, nullptr, &imageView) != VK_SUCCESS)
		throw std::runtime_error("failed to create texture image view!");

	return imageView;
}

void CE_Swapchain::createFrameBuffers(CE_VDevice* _Device)
{
	m_SwapChainFramebuffers.resize(m_SwapChainImageViews.size());

	for (size_t Count = 0; m_SwapChainImageViews.size() > Count; ++Count)
	{

		std::array<VkImageView, 1> attachements = { m_SwapChainImageViews[Count] };

		//std::array<VkImageView, 2> attachements = { m_SwapChainImageViews[Count], m_DepthImageView };

		VkFramebufferCreateInfo framebufferInfo = {};
		framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
		framebufferInfo.renderPass = _Device->GetRenderPass();
		framebufferInfo.attachmentCount = static_cast<uint32_t>(attachements.size());
		framebufferInfo.pAttachments = attachements.data();
		framebufferInfo.width = m_SwapChainExtent.width;
		framebufferInfo.height = m_SwapChainExtent.height;
		framebufferInfo.layers = 1;

		if (vkCreateFramebuffer(_Device->GetDevice(), &framebufferInfo, nullptr, &m_SwapChainFramebuffers[Count]) != VK_SUCCESS)
			throw std::runtime_error("failed to create framebuffer!");
	}
}

void CE_Swapchain::cleanupSwapChain(CE_VDevice* _VDevice)
{
	for (size_t Count = 0; m_SwapChainFramebuffers.size() > Count; ++Count)
		vkDestroyFramebuffer(_VDevice->GetDevice(), m_SwapChainFramebuffers[Count], nullptr);

	for (size_t Count = 0; m_SwapChainImageViews.size() > Count; ++Count)
		vkDestroyImageView(_VDevice->GetDevice(), m_SwapChainImageViews[Count], nullptr);

	vkDestroySwapchainKHR(_VDevice->GetDevice(), m_SwapChain, nullptr);
}

void CE_Swapchain::framebufferResizeCallback(GLFWwindow* _window, int _width, int _height)
{

}

void CE_Swapchain::DestroyInstance(VkDevice _device)
{

}

VkExtent2D CE_Swapchain::GetSwapchainExtent()
{
	return m_SwapChainExtent;
}
