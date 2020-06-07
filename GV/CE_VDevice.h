#pragma once
class CE_VDevice : GV_Module
{
public:
	CE_VDevice(std::string _Name);
	virtual ~CE_VDevice();
	// GV_Module��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;

private:
	VkQueue m_GraphicsQueue = nullptr;

	VkDevice m_Device = nullptr;
};

