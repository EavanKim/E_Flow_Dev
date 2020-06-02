#include "Graphic.h"
#include "GV_Scene.h"

GV_Scene::GV_Scene()
{
}

GV_Scene::~GV_Scene()
{
}

std::vector<GV_Obj*>* GV_Scene::GetObject()
{
	return m_Object;
}

std::vector<GV_Obj*>* GV_Scene::GetPlayer()
{
	return m_Player;
}

std::vector<GV_Obj*>* GV_Scene::GetMonster()
{
	return m_Monster;
}

std::vector<GV_Obj*>* GV_Scene::GetMap()
{
	return m_Map;
}

void GV_Scene::DestroyInstance(VkDevice _device)
{
	for (GV_Obj* Instance : *m_Object)
		Instance->DestroyInstance(_device);
	for (GV_Obj* Instance : *m_Player)
		Instance->DestroyInstance(_device);
	for (GV_Obj* Instance : *m_Monster)
		Instance->DestroyInstance(_device);
	for (GV_Obj* Instance : *m_Map)
		Instance->DestroyInstance(_device);
	for (GV_Obj* Instance : *m_Camera)
		Instance->DestroyInstance(_device);
}
