#ifndef GVBUFFER_H__
#define GVBUFFER_H__

class GRAPHIC_API GV_Buffer
{
public:
	GV_Buffer()
	{

	}

	GV_Buffer(VkBuffer _Buffer, VkDeviceMemory _BufferGPUMemory)
	{
		m_Buffer = _Buffer;
		m_BufferMemory = _BufferGPUMemory;
	}

	VkBuffer m_Buffer = VK_NULL_HANDLE;
	VkDeviceMemory m_BufferMemory = VK_NULL_HANDLE;
};

#endif // !GVBUFFER_H__
