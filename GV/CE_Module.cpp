#include "CVulkan_Core.h"


CE_Module::CE_Module(char* _Name)
	: GV_Base()
	, m_strName(_Name)
{
}

CE_Module::CE_Module(std::string _Name)
	: GV_Base()
	, m_strName(_Name)
{
}

CE_Module::~CE_Module()
{
	m_strName.clear();
	m_strName = nullptr;
}
