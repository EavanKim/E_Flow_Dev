#pragma once
class GRAPHIC_API GV_Base
{
public:
	explicit GV_Base()
		: m_dwRefCnt(0)
	{

	}

	virtual ~GV_Base()
	{

	}

	unsigned long AddRef()
	{
		return (++m_dwRefCnt);
	}

	unsigned long Release()
	{
		if (!m_dwRefCnt)
		{
			Free();

			delete this;

			return 0;
		}

		return (--m_dwRefCnt);
	}

	virtual void Free() = 0;

private:
	unsigned long m_dwRefCnt = 0;
};