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
		createVK();

		m_PhysicalDevice->pickPhysicalDevice(m_Vk, m_Swapchain);
		m_VirtualDevice->createLogicalDevice(m_PhysicalDevice, m_Swapchain, true);
		m_Swapchain->createSurface(m_Vk, m_ModuleWindow);
		m_Swapchain->createSwapChain(m_ModuleWindow, m_PhysicalDevice, m_VirtualDevice);
	}

	void CVulkan_Core::createVK()
	{
		///
//Validation Layers
		if (enableValidationLayers && !checkValidationLayerSupport()) {
			throw std::runtime_error("validation layers requested, but not available!");
		}
		///

		///
		//Window Infomation
		VkApplicationInfo VkInfo = GetApplicationInfo("EW_GV", "Eavan's Work", 0, 1, 0, 0, 1, 0);
		///


		///
		//Vulkan Infomation
		VkInstanceCreateInfo VkInstanceInfo = {};
		VkInstanceInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		VkInstanceInfo.pApplicationInfo = &VkInfo;
		///

		///
		//Validation Layers
		std::vector<const char*> extensions = getRequiredExtensions();
		VkInstanceInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		VkInstanceInfo.ppEnabledExtensionNames = extensions.data();

		VkDebugUtilsMessengerCreateInfoEXT debugInfo;
		if (enableValidationLayers)
		{
			VkInstanceInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
			VkInstanceInfo.ppEnabledLayerNames = validationLayers.data();

			populateDebugMessengerCreateInfo(debugInfo);
			VkInstanceInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugInfo;
		}
		else
		{
			VkInstanceInfo.enabledLayerCount = 0;

			VkInstanceInfo.pNext = nullptr;
		}
		///

		///
		//Create vk
		CheckSuccessInRuntime(vkCreateInstance(&VkInstanceInfo, nullptr, &m_Vk), "failed to create instance!");
		///
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
		std::map<std::string, GV_Module*>::iterator End = m_Modules->end();

		for (std::map<std::string, GV_Module*>::iterator Begin = m_Modules->begin(); Begin != End; ++Begin)
			delete Begin->second;

		m_Modules->clear();
	}

	void CVulkan_Core::DrawScene()
	{
		Render_Begin();

		//submitInfo.commandBufferCount = 1;
		//submitInfo.pCommandBuffers = &drawCmdBuffers[currentBuffer];
		//VK_CHECK_RESULT(vkQueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE));

		Render_End();
	}

	void CVulkan_Core::Suspend()
	{

	}

	void CVulkan_Core::Reseum()
	{

	}

	void CVulkan_Core::CheckSuccessInRuntime(VkResult _result, char* _comment)
	{

		if (_result != VK_SUCCESS)
		{
			switch (_result)
			{

			default:
				throw std::runtime_error(_comment);
				break;
			}
		}
	}

	void CVulkan_Core::CheckSuccessInRuntime(VkResult _result, const char* _comment)
	{

		if (_result != VK_SUCCESS)
		{
			switch (_result)
			{

			default:
				throw std::runtime_error(_comment);
				break;
			}
		}
	}

	void CVulkan_Core::createFramebuffers()
	{

	}

	void CVulkan_Core::recreateSwapChain()
	{

	}

	void CVulkan_Core::Render_Begin()
	{
		//// Acquire the next image from the swap chain
		//VkResult result = swapChain.acquireNextImage(semaphores.presentComplete, &currentBuffer);
		//// Recreate the swapchain if it's no longer compatible with the surface (OUT_OF_DATE) or no longer optimal for presentation (SUBOPTIMAL)
		//if ((result == VK_ERROR_OUT_OF_DATE_KHR) || (result == VK_SUBOPTIMAL_KHR)) 
		//{
		//	windowResize();
		//}
		//else
		//{
		//	VK_CHECK_RESULT(result);
		//}
	}

	void CVulkan_Core::Render_End()
	{
		//VkResult result = swapChain.queuePresent(queue, currentBuffer, semaphores.renderComplete);
		//if (!((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))) {
		//	if (result == VK_ERROR_OUT_OF_DATE_KHR) {
		//		// Swap chain is no longer compatible with the surface and needs to be recreated
		//		windowResize();
		//		return;
		//	}
		//	else {
		//		VK_CHECK_RESULT(result);
		//	}
		//}
		//VK_CHECK_RESULT(vkQueueWaitIdle(queue));
	}

	bool CVulkan_Core::checkValidationLayerSupport()
	{
		uint32_t layerCount;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers) 
		{
			bool layerFound = false;

			for (const VkLayerProperties& layerProperties : availableLayers)
			{
				if (strcmp(layerName, layerProperties.layerName) == 0)
				{
					layerFound = true;
					break;
				}
			}

			if (!layerFound)
			{
				return false;
			}
		}

		return true;
	}

	std::vector<const char*> CVulkan_Core::getRequiredExtensions()
	{
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

		if (enableValidationLayers)
		{
			extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
		}

		return extensions;
	}

	VKAPI_ATTR VkBool32 VKAPI_CALL CVulkan_Core::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT _messageSeverity, VkDebugUtilsMessageTypeFlagsEXT _messageType, const VkDebugUtilsMessengerCallbackDataEXT* _pCallbackData, void* _pUserData)
	{
		std::cerr << "validation layer: " << _pCallbackData->pMessage << std::endl;

		//if (_messageSeverity >= VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT) 
		//{
		//	// Message is important enough to show
		//}

		return VK_FALSE;
	}

	void CVulkan_Core::setupDebugMessenger()
	{
		if (!enableValidationLayers) return;

		VkDebugUtilsMessengerCreateInfoEXT debugInfo;
		populateDebugMessengerCreateInfo(debugInfo);

		if (CreateDebugUtilsMessengerEXT(m_Vk, &debugInfo, nullptr, &m_debugMessenger) != VK_SUCCESS)
			throw std::runtime_error("failed to setup debug messenger");
	}

	VkResult CVulkan_Core::CreateDebugUtilsMessengerEXT(VkInstance _Vk, const VkDebugUtilsMessengerCreateInfoEXT* _pCreateInfo, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT* _pDebugMessenger)
	{
		auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(_Vk, "vkCreateDebugUtilsMessengerEXT");
		if (func != nullptr)
			return func(_Vk, _pCreateInfo, _pAllocator, _pDebugMessenger);
		else
			return VK_ERROR_EXTENSION_NOT_PRESENT;
	}

	void CVulkan_Core::DestroyDebugUtilsMessengerEXT(VkInstance _Vk, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT _pDebugMessenger)
	{
		auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(_Vk, "vkDestroyDebugUtilsMessengerEXT");

		if (func != nullptr)
			func(_Vk, _pDebugMessenger, _pAllocator);
	}

	void CVulkan_Core::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& _debugInfo)
	{
		_debugInfo = {};
		_debugInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
		_debugInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

		_debugInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
			| VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

		_debugInfo.pfnUserCallback = debugCallback;
	}

	CVulkan_Core::CVulkan_Core(std::string _ProgramName, int _Width, int _Height)
		: m_ProgramName(_ProgramName)
		, m_ModuleWindow(new CE_Window(_ProgramName, _Width, _Height))
		, m_PhysicalDevice(new CE_PDevice("pDevice"))
		, m_VirtualDevice(new CE_VDevice("vDevice"))
		, m_Swapchain(new CE_Swapchain("Swapchain"))
	{
		m_Modules->insert(std::make_pair(_ProgramName, (GV_Module*)m_ModuleWindow));
		m_Modules->insert(std::make_pair("pDevice", (GV_Module*)m_PhysicalDevice));
		m_Modules->insert(std::make_pair("vDevice", (GV_Module*)m_VirtualDevice));
		m_Modules->insert(std::make_pair("Swapchain", (GV_Module*)m_Swapchain));
	}
}