#pragma once
class GV_Module : GV_Instance
{
public:
	GV_Module(std::string _Name);
	virtual ~GV_Module();

protected:
	std::string m_ModuleName = nullptr;
};

