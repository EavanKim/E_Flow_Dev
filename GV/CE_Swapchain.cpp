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

void CE_Swapchain::DestroyInstance(VkDevice _device)
{
}
