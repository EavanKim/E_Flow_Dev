#include "CVulkan_Core.h"

namespace GV_Core
{
	CVulkan_Core* CVulkan_Core::m_Instance = nullptr;

	void CVulkan_Core::CreateInstance(std::string _ProgramName, int _Width, int _Height)
	{
		if (!m_Instance)
			m_Instance = new CVulkan_Core(_ProgramName, _Width, _Height);
	}

	CVulkan_Core* CVulkan_Core::GetInstance()
	{
		if (!m_Instance)
			throw new std::exception("Vulkan_Core Instance Is Nullptr");
		return m_Instance;
	}

	void CVulkan_Core::DestroyInstance()
	{
		cleanup();

		if (!m_Instance)
		{
			delete m_Instance;
			m_Instance = nullptr;
		}
	}

	void CVulkan_Core::initVulkan()
	{

	}

	void CVulkan_Core::readScene()
	{

	}

	void CVulkan_Core::mainLoop()
	{
		while (!glfwWindowShouldClose(m_ModuleWindow->GetPoint()))
		{
			glfwPollEvents();
			DrawScene();
		}
	}

	void CVulkan_Core::cleanup()
	{


	}

	void CVulkan_Core::DrawScene()
	{

	}

	bool CVulkan_Core::checkValidationLayerSupport()
	{
		return false;
	}

	std::vector<const char*> CVulkan_Core::getRequiredExtensions()
	{
		return std::vector<const char*>();
	}

	VKAPI_ATTR VkBool32 VKAPI_CALL CVulkan_Core::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT _messageSeverity, VkDebugUtilsMessageTypeFlagsEXT _messageType, const VkDebugUtilsMessengerCallbackDataEXT* _pCallbackData, void* _pUserData)
	{
		return false;
	}

	void CVulkan_Core::setupDebugMessenger()
	{
	}

	VkResult CVulkan_Core::CreateDebugUtilsMessengerEXT(VkInstance _Vk, const VkDebugUtilsMessengerCreateInfoEXT* _pCreateInfo, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT* _pDebugMessenger)
	{
		return VkResult();
	}

	void CVulkan_Core::DestroyDebugUtilsMessengerEXT(VkInstance _Vk, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT _pDebugMessenger)
	{
	}

	void CVulkan_Core::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& _debugInfo)
	{
	}

	CVulkan_Core::CVulkan_Core(std::string _ProgramName, int _Width, int _Height)
		: m_ProgramName(_ProgramName)
		, m_ModuleWindow(new CE_Window(_ProgramName, _Width, _Height))
		, m_PhysicalDevice(new CE_PDevice("pDevice"))
		, m_VirtualDevice(new CE_VDevice("vDevice"))
		, m_Surface(new CE_Surface("Surface"))
	{
		m_Modules->insert(std::make_pair(_ProgramName, (GV_Module*)m_ModuleWindow));
		m_Modules->insert(std::make_pair("pDevice", (GV_Module*)m_PhysicalDevice));
		m_Modules->insert(std::make_pair("vDevice", (GV_Module*)m_VirtualDevice));
		m_Modules->insert(std::make_pair("Surface", (GV_Module*)m_Surface));
		m_PhysicalDevice->pickPhysicalDevice(m_Vk, m_Surface);
		m_VirtualDevice->createLogicalDevice(m_PhysicalDevice, m_Surface, true);
	}
}