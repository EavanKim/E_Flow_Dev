#include "CVulkan_Core.h"


CE_RenderPass::CE_RenderPass(const char* _Name)
	: GV_Module(_Name)
{

}

CE_RenderPass::CE_RenderPass(std::string _Name)
	: GV_Module(_Name)
{

}

void CE_RenderPass::createRenderPass(CE_VDevice* _Device, std::string _Path, std::string _ShaderName, VkShaderStageFlagBits _bit)
{
	std::vector<char> ShaderCode = readFile(_Path);

	VkShaderModule ShaderModule = createShaderModel(_Device, ShaderCode);

	VkPipelineShaderStageCreateInfo ShaderStageInfo = {};
	ShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	ShaderStageInfo.stage = _bit;
	ShaderStageInfo.module = ShaderModule;
	ShaderStageInfo.pName = _ShaderName.c_str();

	m_PipelineInfos.push_back(ShaderStageInfo);
}

VkShaderModule CE_RenderPass::createShaderModel(CE_VDevice* _Device, const std::vector<char>& _code)
{
	VkShaderModuleCreateInfo ShaderInfo = {};
	ShaderInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	ShaderInfo.codeSize = _code.size();
	ShaderInfo.pCode = reinterpret_cast<const uint32_t*>(_code.data());

	VkShaderModule shaderModule;
	if (vkCreateShaderModule(_Device->GetDevice(), &ShaderInfo, nullptr, &shaderModule) != VK_SUCCESS)
		throw std::runtime_error("failed to create shader module!");

	return shaderModule;
}

VkPipelineShaderStageCreateInfo* CE_RenderPass::GetInfo()
{
	return m_PipelineInfos.data();
}

void CE_RenderPass::DestroyInstance(VkDevice _device)
{
	for (VkPipelineShaderStageCreateInfo Iterator : m_PipelineInfos)
		vkDestroyShaderModule(_device, Iterator.module, nullptr);
}
