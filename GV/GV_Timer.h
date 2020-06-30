#pragma once
class GV_Timer : GV_Base
{
public:
	static GV_Timer* Create();
	virtual void Free();

private:
	explicit GV_Timer();
	virtual ~GV_Timer();

};

