#ifndef CVULKANCORE_HPP_
#define CVULKANCORE_HPP_

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include <optional>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <set>
#include <array>
#include <direct.h>
#include <cstdint>

#include <map>
#include <unordered_map>

#include "GV_Define.h"

#include "GV_Functor.h"
#include "GV_Struct.h"

#include "GV_Instance.h"
#include "GV_Module.h"
#include "CE_Window.h"
#include "CE_Swapchain.h"
#include "CE_PDevice.h"
#include "CE_VDevice.h"
#include "CE_Scene.h"

#include "GV_Buffer.h"
#include "GV_Image.h"

#include "GV_Obj.h"
#include "GV_Camera.h"
#include "Static_Camera.h"

#include "AABB_Function.h"
#include "OBB_Fuction.h"
#include "BSP_Function.h"

#include "GV_SubPass.h"

#include "GV_Scene.h"
#include "Sprite_Scene.h"
#include "Poly_Scene.h"

namespace GV_Core
{
	class CVulkan_Core
	{
	public:
		static void CreateInstance(std::string _ProgramName, int _Width = 800, int _Height = 600);
		static CVulkan_Core* GetInstance();
		void DestroyInstance();

		void initVulkan();
		void readScene();
		void mainLoop();
		void cleanup();
		void DrawScene();

	protected:
#pragma region Validation Layers
		///
		//Validation Layers
		bool checkValidationLayerSupport();

		std::vector<const char*> getRequiredExtensions();

		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT _messageSeverity, VkDebugUtilsMessageTypeFlagsEXT _messageType, const VkDebugUtilsMessengerCallbackDataEXT* _pCallbackData, void* _pUserData);

		void setupDebugMessenger();

		VkResult CreateDebugUtilsMessengerEXT(VkInstance _Vk, const VkDebugUtilsMessengerCreateInfoEXT* _pCreateInfo, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT* _pDebugMessenger);

		void DestroyDebugUtilsMessengerEXT(VkInstance _Vk, const VkAllocationCallbacks* _pAllocator, VkDebugUtilsMessengerEXT _pDebugMessenger);

		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& _debugInfo);

		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };

#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif

		VkDebugUtilsMessengerEXT m_debugMessenger = VK_NULL_HANDLE;
		///
#pragma endregion

	private:
		explicit CVulkan_Core(std::string _ProgramName, int _Widht, int _Height);

		GV_Scene* m_CurrentScene = nullptr;

		std::string m_ProgramName = nullptr;

		VkInstance m_Vk = nullptr;
		CE_Window* m_ModuleWindow = nullptr;
		CE_PDevice* m_PhysicalDevice = nullptr;
		CE_VDevice* m_VirtualDevice = nullptr;
		CE_Swapchain* m_Swapchain = nullptr;
		std::unordered_map<std::string, GV_Module*>* m_Modules = nullptr;

		static CVulkan_Core* m_Instance;
	};
}

#endif
