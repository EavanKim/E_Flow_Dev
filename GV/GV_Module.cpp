#include "CVulkan_Core.h"

GV_Module::GV_Module(std::string _Name)
	: GV_Instance()
{
	m_ModuleName = _Name;
}

GV_Module::~GV_Module()
{
	if(!m_ModuleName.data())
	{
		m_ModuleName.clear();
		m_ModuleName = nullptr;
	}
}
