#include "CVulkan_Core.h"

namespace GV_Core
{
	CVulkan_Core* CVulkan_Core::m_Instance = nullptr;

	void CVulkan_Core::CreateInstance(char* _ProgramName, int _Width, int _Height)
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

	void CVulkan_Core::initWindow(void(*_framebufferResizeCallback)(GLFWwindow* _window, int _width, int _height), void(*_Key_Callback_Function)(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods))
	{	
		///
		//default
		glfwInit();
		///

		///
		//Instance
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		//glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_Window = glfwCreateWindow(m_WindowWidth, m_WindowHeight, "EW_GV", nullptr, nullptr);
		///

		///
		//Swap Chain Recreation
		if(!_framebufferResizeCallback)
			glfwSetFramebufferSizeCallback(m_Window, _framebufferResizeCallback);
		else
			glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);
		///

		if(!_Key_Callback_Function)
			glfwSetKeyCallback(m_Window, _Key_Callback_Function);
		else
			glfwSetKeyCallback(m_Window, DefaultKey_callback);
	}

	void CVulkan_Core::DestroyWindow()
	{
		glfwDestroyWindow(m_Window);

		glfwTerminate();
	}

	void CVulkan_Core::initVulkan()
	{

	}

	void CVulkan_Core::readScene()
	{

	}

	void CVulkan_Core::mainLoop()
	{
		while (!glfwWindowShouldClose(m_Window))
		{
			glfwPollEvents();
			DrawScene();
		}
	}



	void CVulkan_Core::cleanup()
	{


		DestroyWindow();
	}

	void CVulkan_Core::DrawScene()
	{

	}

	void CVulkan_Core::DefaultKey_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
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

	void CVulkan_Core::framebufferResizeCallback(GLFWwindow* _window, int _width, int _height)
	{
		CVulkan_Core::GetInstance()->m_FramebufferResized = true;
	}

	CVulkan_Core::CVulkan_Core(char* _ProgramName, int _Widht, int _Height)
		: m_WindowWidth(_Widht)
		, m_WindowHeight(_Height)
		, m_ProgramName(_ProgramName)
	{

	}
}