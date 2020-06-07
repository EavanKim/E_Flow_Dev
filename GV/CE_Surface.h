#pragma once
class CE_Surface : GV_Module
{
public:
	CE_Surface(std::string _Name);
	virtual ~CE_Surface();

	// GV_Module��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;

	VkSurfaceKHR GetSurface();

private:
	VkSurfaceKHR m_Surface = VK_NULL_HANDLE;
};

