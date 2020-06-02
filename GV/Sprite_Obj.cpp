#include "Graphic.h"

Sprite_Obj::Sprite_Obj() : GV_Obj(BUFFER_TYPE::SPRITE_BUFFER, IMAGE_TYPE::IMAGE_2D)
{
}

Sprite_Obj::Sprite_Obj(GV_Image _image) : GV_Obj(BUFFER_TYPE::SPRITE_BUFFER, IMAGE_TYPE::IMAGE_2D)
{
	InsertSprite(_image);
}

Sprite_Obj::Sprite_Obj(GV_Buffer _Vertex, GV_Buffer _Index, GV_Image _image) : GV_Obj(_Vertex, _Index, BUFFER_TYPE::SPRITE_BUFFER, IMAGE_TYPE::IMAGE_2D)
{
	InsertSprite(_image);
}

Sprite_Obj::~Sprite_Obj()
{

}

void Sprite_Obj::InsertSprite(GV_Image _image)
{
	int CurrentImageKey = m_SpritePath.size();
	m_SpritePath.insert(std::make_pair(static_cast<int>(CurrentImageKey), new std::vector<GV_Image>()));
	m_SpritePath[CurrentImageKey]->clear();
	m_SpritePath[CurrentImageKey]->push_back(_image);
}

GV_Image Sprite_Obj::Sprite(int _index, int _currentCut)
{
	std::vector<GV_Image> Sprite = *(m_SpritePath[_index]);
	return Sprite[_currentCut];
}

void Sprite_Obj::DestroyInstance(VkDevice _device)
{
	for (std::pair<int, std::vector<GV_Image>*> ImageVector : m_SpritePath)
	{
		for (GV_Image Image : *(ImageVector.second))
		{
			vkDestroySampler(_device, Image.m_Sampler, nullptr);
			vkDestroyImageView(_device, Image.m_ImageView, nullptr);
			vkDestroyImage(_device, Image.m_Image, nullptr);
			vkFreeMemory(_device, Image.m_ImageMemory, nullptr);
		}
		ImageVector.second->clear();
	}
	m_SpritePath.clear();
	GV_Obj::DestroyInstance(_device);
}
