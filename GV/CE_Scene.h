#pragma once
class CE_Scene : GV_Instance
{
public:
	CE_Scene();
	virtual ~CE_Scene();

	// GV_Instance��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;
};

