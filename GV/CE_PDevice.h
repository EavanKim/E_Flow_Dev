#pragma once
class CE_PDevice : GV_Module
{
public:
	CE_PDevice(std::string _Name);
	virtual ~CE_PDevice();

	void pickPhysicalDevice(VkInstance _Instance, CE_Swapchain* _Surface);

	bool isDeviceSuitable(VkPhysicalDevice _device, CE_Swapchain* _Surface);

	int rateDeviceSuitablility();

	bool checkDeviceExtensionSupport(VkPhysicalDevice _device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice _device, CE_Swapchain* _Surface);

	QueueFamilyIndices findQueueFamilies(CE_Swapchain* _Surface);

	VkPhysicalDevice GetDevice();

	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;

private:
	VkPhysicalDevice m_PhysicalDevice = nullptr;
};

