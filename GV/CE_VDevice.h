#pragma once
class CE_VDevice : GV_Module
{
public:
	CE_VDevice(std::string _Name);
	virtual ~CE_VDevice();

	void createLogicalDevice(CE_PDevice* _PhysicalDevice, CE_Swapchain* _Surface, bool _enableValidationLayers);
	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;

private:

	VkQueue m_GraphicsQueue = nullptr;
	VkQueue m_PresentQueue = nullptr;

	VkDevice m_Device = nullptr;
};

