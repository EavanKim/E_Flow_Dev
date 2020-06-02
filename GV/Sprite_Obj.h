#pragma once

class Sprite_Obj :	public GV_Obj
{
public:
	Sprite_Obj();
	Sprite_Obj(GV_Image _image);
	Sprite_Obj(GV_Buffer _Vertex, GV_Buffer _Index, GV_Image _image);
	~Sprite_Obj();

	void InsertSprite(GV_Image _image);
	GV_Image Sprite(int _index, int _currentCut);

	virtual void DestroyInstance(VkDevice _device);

protected:


private:
	std::unordered_map<int, std::vector<GV_Image>*> m_SpritePath;
};

