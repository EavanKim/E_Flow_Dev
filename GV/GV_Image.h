#ifndef GVIMAGE_H__
#define GVIMAGE_H__

class GRAPHIC_API GV_Image
{
public:
	VkImage m_Image = VK_NULL_HANDLE;
	VkDeviceMemory m_ImageMemory = VK_NULL_HANDLE;
	VkImageView m_ImageView = VK_NULL_HANDLE;
	VkSampler m_Sampler = VK_NULL_HANDLE;
};

#endif // ! GVIMAGE_H__
