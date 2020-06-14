#pragma once
class CE_VDevice : GV_Module
{
public:
	CE_VDevice(std::string _Name);
	virtual ~CE_VDevice();

	void createLogicalDevice(CE_PDevice* _PhysicalDevice, CE_Swapchain* _Surface, bool _enableValidationLayers);

	void setUpRenderPass(CE_Swapchain* _Swapchain, CE_RenderPass* _Pass);

	virtual void DestroyInstance(VkDevice _device) override;

	VkDevice GetDevice();

private:
	VkQueue m_GraphicsQueue = nullptr;
	VkQueue m_PresentQueue = nullptr;

	VkRenderPass m_RenderPass = VK_NULL_HANDLE;
	VkPipeline m_GraphicsPipeline = VK_NULL_HANDLE;
	VkPipelineLayout m_PipelineLayout = VK_NULL_HANDLE;
	VkDescriptorSetLayout descriptorSetLayout = VK_NULL_HANDLE;

	VkDevice m_Device = nullptr;
};

