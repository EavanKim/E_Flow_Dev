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
		static void CreateInstance(char* _ProgramName, int _Width = 800, int _Height = 600);
		static CVulkan_Core* GetInstance();
		void DestroyInstance();

		void initWindow(void(*_framebufferResizeCallback)(GLFWwindow* _window, int _width, int _height) = nullptr, void(*_Key_Callback_Function)(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods) = nullptr);
		void DestroyWindow();

		void initVulkan();
		void readScene();
		void mainLoop();
		void cleanup();
		void DrawScene();

		static void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);
		static void DefaultKey_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);

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
		explicit CVulkan_Core(char* _ProgramName, int _Widht, int _Height);

		int m_WindowWidth = 800;
		int m_WindowHeight = 600;

		bool m_FramebufferResized = false;

		GLFWwindow* m_Window = nullptr;

		GV_Scene* m_CurrentScene = nullptr;

		std::string m_ProgramName = nullptr;

		static CVulkan_Core* m_Instance;
	};
}

#endif