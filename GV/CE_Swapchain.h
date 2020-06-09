#pragma once

class CE_PDevice;
class CE_VDevice;
class CE_Swapchain : GV_Module
{
public:
	CE_Swapchain(std::string _Name);
	virtual ~CE_Swapchain();

	VkSurfaceKHR GetSurface();

	void createSurface(VkInstance _Vk, CE_Window* _Window);

	bool checkDeviceExtensionSupport(VkPhysicalDevice _device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice _device);

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& _availableFormats);

	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& _avaliablePresentModes);

	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& _capabilities);

	void createSwapChain(CE_PDevice* _PDevice, CE_VDevice* _VDevice);

	void recreateSwapChain();

	void cleanupSwapChain();

	static void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);


	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;

private:
	VkQueue m_PresentQueue = nullptr;

	VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
	VkFormat m_SwapChainImageFormat;
	VkExtent2D m_SwapChainExtent;
	std::vector<VkImage> m_SwapChainImages;

	VkSwapchainKHR m_SwapChain = VK_NULL_HANDLE;
};

