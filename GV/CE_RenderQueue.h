#pragma once
class CE_RenderQueue : GV_Module
{
public:
	CE_RenderQueue();
	~CE_RenderQueue();

private:
	VkQueue m_Queue = nullptr;
};

