#pragma once

class CMem_Chunk
{
public:
	explicit CMem_Chunk(size_t _EachSize, int _Count);
	~CMem_Chunk();

	size_t m_iChunkSize = 0;
private:
	void* m_Memory = nullptr;
};

class GRAPHIC_API CMem_Mgr
{
public:

	
private:
	explicit CMem_Mgr(int _MemSize);
	~CMem_Mgr();
};
