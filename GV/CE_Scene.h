#pragma once

//Director in Builder Pattern
//Use Particle Builder, Player Builder, Enemy Builder, Geometry Builder, Camera Builder

class CE_Scene : GV_Instance
{
public:
	CE_Scene();
	virtual ~CE_Scene();

	// GV_Instance��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;
};

