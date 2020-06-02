#ifndef GVSCENE_H__
#define GVSCENE_H__

class GRAPHIC_API GV_Scene : public GV_Instance
{
public:
	GV_Scene();
	~GV_Scene();

	std::vector<GV_Obj*>* GetObject();
	std::vector<GV_Obj*>* GetPlayer();
	std::vector<GV_Obj*>* GetMonster();
	std::vector<GV_Obj*>* GetMap();

	virtual void DestroyInstance(VkDevice _device) override;

protected:
	std::vector<GV_Obj*>* m_Object = nullptr;
	std::vector<GV_Obj*>* m_Player = nullptr;
	std::vector<GV_Obj*>* m_Monster = nullptr;
	std::vector<GV_Obj*>* m_Map = nullptr;
	std::vector<GV_Obj*>* m_Camera = nullptr;

private:

};

#endif // !GVSCENE_H__
