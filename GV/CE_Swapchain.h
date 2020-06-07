#pragma once
class CE_Swapchain : GV_Module
{
public:
	CE_Swapchain(std::string _Name);
	virtual ~CE_Swapchain();

	VkSurfaceKHR GetSurface();

	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;

private:
	VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
};

