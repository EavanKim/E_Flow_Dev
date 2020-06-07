#include "CVulkan_Core.h"

CE_Surface::CE_Surface(std::string _Name)
	: GV_Module(_Name)
{
}

CE_Surface::~CE_Surface()
{
}

void CE_Surface::DestroyInstance(VkDevice _device)
{
}

VkSurfaceKHR CE_Surface::GetSurface()
{
	return m_Surface;
}
