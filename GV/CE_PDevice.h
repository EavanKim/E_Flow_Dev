#pragma once
class CE_PDevice : GV_Module
{
public:
	CE_PDevice(std::string _Name);
	virtual ~CE_PDevice();

	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice _device);

	int rateDeviceSuitablility(VkPhysicalDevice _device);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice _device);

	// GV_Module��(��) ���� ��ӵ�
	virtual void DestroyInstance(VkDevice _device) override;

private:
	VkPhysicalDevice m_PhysicalDevice = nullptr;
};

