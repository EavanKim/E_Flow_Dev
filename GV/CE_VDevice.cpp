#include "CVulkan_Core.h"

CE_VDevice::CE_VDevice(std::string _Name)
	: GV_Module(_Name)
{
}

CE_VDevice::~CE_VDevice()
{
}

void CE_VDevice::createLogicalDevice(CE_PDevice* _PhysicalDevice, CE_Swapchain* _Surface, bool _enableValidationLayers)
{
	QueueFamilyIndices indices = _PhysicalDevice->findQueueFamilies(_Surface);

	///
	//Window Surface
	std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
	std::set<uint32_t> uniqueQueueFamilies = { indices.graphicsFamily.value(), indices.presentFamily.value() };

	float queuePriority = 1.0f;
	for (uint32_t queueFamily : uniqueQueueFamilies)
	{
		VkDeviceQueueCreateInfo queueCreateinfo = {};
		queueCreateinfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateinfo.queueFamilyIndex = queueFamily;
		queueCreateinfo.queueCount = 1;
		queueCreateinfo.pQueuePriorities = &queuePriority;
		queueCreateInfos.push_back(queueCreateinfo);
	}

	///
	VkPhysicalDeviceFeatures deviceFeatures = {};
	deviceFeatures.samplerAnisotropy = VK_TRUE;

	VkDeviceCreateInfo LogicalDevInfo = {};
	LogicalDevInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	LogicalDevInfo.queueCreateInfoCount = static_cast<uint32_t>(queueCreateInfos.size());
	LogicalDevInfo.pQueueCreateInfos = queueCreateInfos.data();

	LogicalDevInfo.pEnabledFeatures = &deviceFeatures;

	///
	//Swap Chain
	LogicalDevInfo.enabledExtensionCount = static_cast<uint32_t>(deviceExtensions.size());
	LogicalDevInfo.ppEnabledExtensionNames = deviceExtensions.data();
	///

	if (_enableValidationLayers)
	{
		LogicalDevInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		LogicalDevInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else
	{
		LogicalDevInfo.enabledLayerCount = 0;
	}

	if (vkCreateDevice(_PhysicalDevice->GetDevice(), &LogicalDevInfo, nullptr, &m_Device) != VK_SUCCESS)
		throw std::runtime_error("failed to create logical device!");

	vkGetDeviceQueue(m_Device, indices.graphicsFamily.value(), 0, &m_GraphicsQueue);
	vkGetDeviceQueue(m_Device, indices.presentFamily.value(), 0, &m_PresentQueue);
}

void CE_VDevice::setUpRenderPass(CE_Swapchain* _Swapchain, CE_RenderPass* _Pass)
{
	VkPipelineShaderStageCreateInfo* shaderStages = _Pass->GetInfo();

	///
	//Fixed function
	VkPipelineVertexInputStateCreateInfo vertexInputInfo = {};
	vertexInputInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

	///
	//Vertex Input
	VkVertexInputBindingDescription Description = Vertex::getBindingDescription();

	///
	//Combined Image
	std::array<VkVertexInputAttributeDescription, 3U> Attribute = Vertex::getAttributeDescriptions();
	///

	vertexInputInfo.vertexBindingDescriptionCount = 1;
	vertexInputInfo.vertexAttributeDescriptionCount = static_cast<uint32_t>(Attribute.size());
	vertexInputInfo.pVertexBindingDescriptions = &Description;
	vertexInputInfo.pVertexAttributeDescriptions = Attribute.data();

	///
	VkPipelineInputAssemblyStateCreateInfo inputAssembly = {};
	inputAssembly.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
	inputAssembly.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
	inputAssembly.primitiveRestartEnable = VK_FALSE;

	VkExtent2D GetSwapchainExtent = _Swapchain->GetSwapchainExtent();

	VkViewport viewport = {};
	viewport.x = 0.0f;
	viewport.y = 0.0f;
	viewport.width = (float)GetSwapchainExtent.width;
	viewport.height = (float)GetSwapchainExtent.height;
	viewport.minDepth = 0.0f;
	viewport.maxDepth = 1.0f;

	VkRect2D scissor = {};
	scissor.offset = { 0, 0 };
	scissor.extent = GetSwapchainExtent;

	VkPipelineViewportStateCreateInfo viewportState = {};
	viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
	viewportState.viewportCount = 1;
	viewportState.pViewports = &viewport;
	viewportState.scissorCount = 1;
	viewportState.pScissors = &scissor;

	VkPipelineRasterizationStateCreateInfo rasterizer = {};
	rasterizer.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
	rasterizer.depthClampEnable = VK_FALSE;
	rasterizer.rasterizerDiscardEnable = VK_FALSE;
	rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
	rasterizer.lineWidth = 1.0f;
	rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
	rasterizer.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;

	rasterizer.depthBiasEnable = VK_FALSE;

	VkPipelineMultisampleStateCreateInfo multisampling = {};
	multisampling.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
	multisampling.sampleShadingEnable = VK_FALSE;
	multisampling.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;

	///
	//Depth buffering
	VkPipelineDepthStencilStateCreateInfo depthStencil = {};
	depthStencil.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
	depthStencil.depthTestEnable = VK_TRUE;
	depthStencil.depthWriteEnable = VK_TRUE;

	depthStencil.depthCompareOp = VK_COMPARE_OP_LESS;

	depthStencil.depthBoundsTestEnable = VK_FALSE;

	depthStencil.stencilTestEnable = VK_FALSE;
	///

	VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
	colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
	colorBlendAttachment.blendEnable = VK_FALSE;

	VkPipelineColorBlendStateCreateInfo colorBlending = {};
	colorBlending.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
	colorBlending.logicOpEnable = VK_FALSE;
	colorBlending.logicOp = VK_LOGIC_OP_COPY; // Optional
	colorBlending.attachmentCount = 1;
	colorBlending.pAttachments = &colorBlendAttachment;
	colorBlending.blendConstants[0] = 0.0f; // Optional
	colorBlending.blendConstants[1] = 0.0f; // Optional
	colorBlending.blendConstants[2] = 0.0f; // Optional
	colorBlending.blendConstants[3] = 0.0f; // Optional

	VkPipelineLayoutCreateInfo pipelineLayoutInfo = {};
	pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;

	///
	//uniform buffers
	pipelineLayoutInfo.setLayoutCount = 1;
	pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout;
	///

	if (vkCreatePipelineLayout(m_Device, &pipelineLayoutInfo, nullptr, &m_PipelineLayout) != VK_SUCCESS)
		throw std::runtime_error("failed to create pipeline layout!");
	///

	///
	//Conclusion
	VkGraphicsPipelineCreateInfo pipelineInfo = {};
	pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
	pipelineInfo.stageCount = 2;
	pipelineInfo.pStages = shaderStages;

	pipelineInfo.pVertexInputState = &vertexInputInfo;
	pipelineInfo.pInputAssemblyState = &inputAssembly;
	pipelineInfo.pViewportState = &viewportState;
	pipelineInfo.pRasterizationState = &rasterizer;
	pipelineInfo.pMultisampleState = &multisampling;
	///
	//Depth buffering
	pipelineInfo.pDepthStencilState = &depthStencil;
	///
	pipelineInfo.pColorBlendState = &colorBlending;

	pipelineInfo.layout = m_PipelineLayout;

	pipelineInfo.renderPass = m_RenderPass;
	pipelineInfo.subpass = 0;

	pipelineInfo.basePipelineHandle = VK_NULL_HANDLE;

	if (vkCreateGraphicsPipelines(m_Device, VK_NULL_HANDLE, 1, &pipelineInfo, nullptr, &m_GraphicsPipeline) != VK_SUCCESS)
		throw std::runtime_error("failed to create graphics pipeline!");
}

void CE_VDevice::DestroyInstance(VkDevice _device)
{

}

VkDevice CE_VDevice::GetDevice()
{
	return m_Device;
}
