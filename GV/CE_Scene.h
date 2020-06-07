#pragma once
class CE_Scene : GV_Instance
{
public:
	CE_Scene();
	virtual ~CE_Scene();

	// GV_Instance을(를) 통해 상속됨
	virtual void DestroyInstance(VkDevice _device) override;
};

