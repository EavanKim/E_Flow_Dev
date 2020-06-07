#ifndef GRAPHIC_H__
#define GRAPHIC_H__

#include <iostream>
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
#include "CE_Surface.h"
#include "CE_PDevice.h"
#include "CE_VDevice.h"

#include "GV_Buffer.h"
#include "GV_Image.h"

#include "GV_Obj.h"
#include "GV_Camera.h"
#include "Static_Camera.h"

#include "AABB_Function.h"
#include "OBB_Fuction.h"
#include "BSP_Function.h"

#include "GV_Scene.h"
#include "Sprite_Scene.h"
#include "Poly_Scene.h"

#include "CFluid_Mgr.h"

class GRAPHIC_API Graphic_Vulkan
{
public:
	// Singleton
	static Graphic_Vulkan* GetInstance();

	//Default
	void initWindow();
	void initVulkan();
	void readScene();
	void mainLoop();
	void cleanup_old();
	void cleanup();

protected:

private:
	void CheckSuccessInRuntime(VkResult _result, char* _comment);
	void CheckSuccessInRuntime(VkResult _result, const char* _comment);

	///
	//Custom
	VkApplicationInfo GetApplicationInfo(char* _applicationName, char* _enginName, int _appMajorVersion, int _appMinorVersion, int _appPatchVersion, int _engineMajorVersion, int _engineMinorVersion, int _enginePatchVersion);
	VkApplicationInfo GetApplicationInfo(const char* _applicationName, const char* _enginName, int _appMajorVersion, int _appMinorVersion, int _appPatchVersion, int _engineMajorVersion, int _engineMinorVersion, int _enginePatchVersion);

	void CreateBufferObject(BUFFER_TYPE _Type);
	void CreateCameraObject(CAMERA_TYPE _Type, uint32_t _width, uint32_t _height);

	void CreateCameraObject(CAMERA_TYPE _Type, uint32_t _width, uint32_t _height, GV_Obj* _Player);

	void CreateSpriteObject(std::string _Path);
	GV_Image LoadingImage(std::string _Path);

	void static Key_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);

	void WindowQuit();

	void KeyDoing(bool _leftright);

	void KeyDoing1(bool _updown);

	void KeyDoing2(bool _leftright);

	void KeyDoing3(bool _updown);

	void createmultipassGraphicsPipeline();

	std::vector<GV_Obj*> m_Object;
	GV_Scene* m_Scene = nullptr;
	std::unordered_map<int, GV_Camera*> m_Camera;
	///

	///
	//instance
	void createInstance();
	///

	///
	// Singleton
	static Graphic_Vulkan* m_Instance;
	///

#pragma region Vulkan Window
	///
	// Vulkan Window
	int m_WindowWidth = 800;
	int m_WindowHeight = 600;
	GLFWwindow* m_Window = nullptr;
	///
#pragma endregion

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

#pragma region Physical Device
	///
	//Physical Device
	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice _device);

	int rateDeviceSuitablility(VkPhysicalDevice _device);


	VkPhysicalDevice m_PhysicalDevice = nullptr;
	///
#pragma endregion

#pragma region Logical Device
	///
	//Logical device
	void createLogicalDevice();

	VkQueue m_GraphicsQueue = nullptr;

	VkDevice m_Device = nullptr;
	///
#pragma endregion

#pragma region Queue Families
	///
	//Queue Families
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice _device);
	///
#pragma endregion

#pragma region Presentation Window Surface
	///
	//Presentation Window Surface
	void createSurface();

	VkQueue m_PresentQueue = nullptr;

	VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Swap Chain
	///
	//Swap Chain
	const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };

	bool checkDeviceExtensionSupport(VkPhysicalDevice _device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice _device);

	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& _availableFormats);

	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& _avaliablePresentModes);

	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& _capabilities);

	void createSwapChain();

	///
	//SwapChain Recreation
	void recreateSwapChain();

	void cleanupSwapChain();

	static void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);
	///

	VkFormat m_SwapChainImageFormat;
	VkExtent2D m_SwapChainExtent;
	std::vector<VkImage> m_SwapChainImages;

	VkSwapchainKHR m_SwapChain = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Image Views
	///
	//Image Views
	void createImageViews();


	std::vector<VkImageView> m_SwapChainImageViews;
	///
#pragma endregion

#pragma region Graphic Pipeline
	///
	//Graphic Pipeline
	void createGraphicsPipeline();

	VkShaderModule createShaderModule(const std::vector<char>& _code);

	VkPipelineLayout m_PipelineLayout = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Render Passes
	///
	//Render Passes
	void createRenderPass();

	void createMultiRenderPass();

	VkRenderPass m_RenderPass = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Conclusion
	///
	//Conclusion
	VkPipeline m_GraphicsPipeline = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region FrameBuffers
	///
	//FrameBuffers
	void createFramebuffers();

	std::vector<VkFramebuffer> m_SwapChainFramebuffers;
	///
#pragma endregion

#pragma region Command Pools
	///
	//Command Pools
	void createCommandPool();
	void createCommandBuffers();

	void createCustomCommandBuffers();


	std::vector<VkCommandBuffer> m_CommandBuffers;

	VkCommandPool m_CommandPool = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Draw
	///
	//Draw
	const int MAX_FRAMES_IN_FLIGHT = 2;

	std::vector<VkSemaphore> m_ImageAvailableSemaphores;
	std::vector<VkSemaphore> m_RenderFinishedSemaphores;
	std::vector<VkFence> m_InfFlightFence;
	std::vector<VkFence> m_ImagesInFlight;
	size_t m_CurrentFrame = 0;

	///
	//Swap Chain Recreation
	bool m_FramebufferResized = false;
	///

	void createSyncObjects();

	void DrawFrame();
	void DrawFrame(static std::chrono::steady_clock::time_point _deltaTime);
	///
#pragma endregion

#pragma region Vertex buffer creation
	///
	//Vertex buffer creation
	void createVertexBuffer();
	void createVertexBuffer(std::vector<Vertex> _vertex, VkBuffer* _vertexBuffer, VkDeviceMemory* _gpuVertexMemroy);
	GV_Buffer createVertexBuffer(std::vector<Vertex> _vertex);

	uint32_t findMemroyType(uint32_t _typeFilter, VkMemoryPropertyFlags _properties);

	VkBuffer m_VertexBuffer = VK_NULL_HANDLE;
	VkDeviceMemory m_VertexBufferMemory = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Staging buffer
	///
	//Staging Buffer
	void createBuffer(VkDeviceSize _size, VkBufferUsageFlags _usage, VkMemoryPropertyFlags _properties, VkBuffer& _buffer, VkDeviceMemory& _bufferMemory);

	void copyBuffer_old(VkBuffer _srcBuffer, VkBuffer _dstBuffer, VkDeviceSize _size);

	void copyBuffer(VkBuffer _srcBuffer, VkBuffer _dstBuffer, VkDeviceSize _szie);
	///
#pragma endregion

#pragma region Index Buffer
	///
	//Index Buffer
	void createIndexBuffer();
	void createIndexBuffer(std::vector<uint16_t> _indices, VkBuffer* _indicesBuffer, VkDeviceMemory* _gpuIndicesMemroy);
	GV_Buffer createIndexBuffer(std::vector<uint16_t> _indices);

	VkBuffer m_IndexBuffer = VK_NULL_HANDLE;
	VkDeviceMemory m_IndexBufferMemory = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Uniform Buffers
	///
	//Uniform Buffers
	void createDescriptorSetLayout();

	void createUniformBuffers();

	void createUniformBuffers(GV_Obj& _Obj);

	void updateUniformBuffer(uint32_t _currentImage);

	void updateUniformBuffer(uint32_t _currentImage, GV_Obj& _Obj);

	void createDescriptorPool();

	void createDescriptorSets();

	void createDescriptorSets(size_t _ObjCount, Sprite_Obj& _Obj);

	VkDescriptorSetLayout descriptorSetLayout = VK_NULL_HANDLE;
	VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;

	std::vector<VkBuffer> m_UniformBuffers;
	std::vector<VkDeviceMemory> m_UniformBuffersMemory;


	VkDescriptorPool m_DescriptorPool = VK_NULL_HANDLE;
	std::vector<VkDescriptorSet> m_DescriptorSets;
	///
#pragma endregion

#pragma region Images
	///
	//Images
	void createTextureImage();

	void createImage(uint32_t _width, uint32_t _height, VkFormat _format, VkImageTiling _tiling, VkImageUsageFlags _usage, VkMemoryPropertyFlags _propertiesm, VkImage& _image, VkDeviceMemory& _imageMemory);

	VkCommandBuffer beginSingleTimeCommands();
	void endSingleTimeCommands(VkCommandBuffer _commandBuffer);

	void transitionImageLayout(VkImage _image, VkFormat _format, VkImageLayout _oldLayout, VkImageLayout _newLayout);

	void copyBufferToImage(VkBuffer _buffer, VkImage _image, uint32_t _width, uint32_t _height);

	VkImage m_TextureImage = VK_NULL_HANDLE;
	VkDeviceMemory m_TextureImageMemory = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region ImageView
	///
	//ImageView
	void createTextureImageView();

	VkImageView createImageView(VkImage _image, VkFormat _format);

	void createTextureSampler();

	void CreateTextureSampler(uint64_t& _Sampler);

	VkImageView m_TextureImageView = VK_NULL_HANDLE;
	VkSampler m_TextureSampler = VK_NULL_HANDLE;
	///
#pragma endregion

#pragma region Depth Buffering
	///
	//Depth Buffering
	void createDepthResource();

	VkFormat findSupportedFormat(const std::vector<VkFormat>& _candidates, VkImageTiling _tiling, VkFormatFeatureFlags _features);

	VkFormat findDepthFormat();

	bool hasStancilComponent(VkFormat _format);

	VkImageView createImageView(VkImage _image, VkFormat _format, VkImageAspectFlags _aspectFlages);

	VkImage m_DepthImage = VK_NULL_HANDLE;
	VkDeviceMemory m_DepthImageMemory = VK_NULL_HANDLE;
	VkImageView m_DepthImageView = VK_NULL_HANDLE;
	///
#pragma endregion
	
	//Instance
	VkInstance m_Vk = nullptr;
};

#endif
