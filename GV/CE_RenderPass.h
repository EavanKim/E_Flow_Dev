#pragma once

class CD_VDevice;
class CE_RenderPass : GV_Module
{
public:
	// GV_Module을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;

	CE_RenderPass(const char* _Name);

	CE_RenderPass(std::string _Name);

	void createRenderPass(CE_VDevice* _Device, std::string _Path, std::string _ShaderName, VkShaderStageFlagBits _bit);

	VkShaderModule createShaderModel(CE_VDevice* _Device, const std::vector<char>& _code);

	VkPipelineShaderStageCreateInfo* GetInfo();

private:
	std::vector<VkPipelineShaderStageCreateInfo> m_PipelineInfos;
};
