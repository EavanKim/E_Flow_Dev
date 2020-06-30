#pragma once
class CE_Module : public GV_Base
{
public:
	explicit CE_Module(char* _Name);
	explicit CE_Module(std::string _Name);
	virtual ~CE_Module();

	virtual int Update() = 0;

private:
	std::string m_strName = nullptr;
};
