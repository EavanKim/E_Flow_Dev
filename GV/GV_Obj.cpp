#include "Graphic.h"

GV_Obj::GV_Obj() : GV_Instance(GV_TYPE::OBJECT)
{

}

GV_Obj::GV_Obj(BUFFER_TYPE _Buffertype, IMAGE_TYPE _ImageType) : GV_Instance(GV_TYPE::OBJECT)
{
	m_BufferType = _Buffertype;
	m_ImageType = _ImageType;
}

GV_Obj::GV_Obj(GV_Buffer _Vertex, GV_Buffer _Index, BUFFER_TYPE _Buffertype, IMAGE_TYPE _ImageType) : GV_Instance(GV_TYPE::OBJECT)
{
	m_BufferType = _Buffertype;
	m_ImageType = _ImageType;

	m_Vertex = _Vertex;
	m_Index = _Index;
}

GV_Obj::~GV_Obj()
{

}

void GV_Obj::SetAngle(float _delta, glm::vec3 _tripleAngle)
{
	m_MatWorld = glm::rotate(m_MatWorld, glm::radians(_delta), _tripleAngle);
}

void GV_Obj::SetAngle(float _delta, float _x, float _y, float _z)
{
	m_MatWorld = glm::rotate(m_MatWorld, glm::radians(_delta), glm::vec3(_x, _y, _z));
}

void GV_Obj::rotateX(float _x)
{
	m_MatWorld = glm::rotate(m_MatWorld, glm::radians(_x), glm::vec3(1.0f, 0.0f, 0.0f));
}

void GV_Obj::rotateY(float _y)
{
	m_MatWorld = glm::rotate(m_MatWorld, glm::radians(_y), glm::vec3(0.0f, 1.0f, 0.0f));
}

void GV_Obj::rotateZ(float _z)
{
	m_MatWorld = glm::rotate(m_MatWorld, glm::radians(_z), glm::vec3(0.0f, 0.0f, 1.0f));
}

void GV_Obj::Move(glm::vec3 _moveVector)
{
	m_MatWorld = glm::translate(m_MatWorld, _moveVector);
}

void GV_Obj::Move(float _x, float _y, float _z)
{
	m_MatWorld = glm::translate(m_MatWorld, glm::vec3(_x, _y, _z));
}

RENDER_TYPE GV_Obj::GetRenderType()
{
	return m_Render;
}

OBJECT_TYPE GV_Obj::GetObjectType()
{
	return m_ObjectType;
}

BUFFER_TYPE GV_Obj::GetBufferType()
{
	return m_BufferType;
}

glm::mat4 GV_Obj::MatWorld()
{
	return m_MatWorld;
}

glm::vec3 GV_Obj::GetPosVector()
{
	return glm::vec3(m_MatWorld[3][0], m_MatWorld[3][1], m_MatWorld[3][2]);
}

GV_Buffer GV_Obj::GetVertex()
{
	return m_Vertex;
}

void GV_Obj::GetVertex(GV_Buffer _Buffer)
{
	m_Vertex = _Buffer;
}

GV_Buffer GV_Obj::GetIndex()
{
	return m_Index;
}

void GV_Obj::GetIndex(GV_Buffer _Buffer)
{
	m_Index = _Buffer;
}

GV_Buffer GV_Obj::Uniform(int _CurrentSwapChain)
{
	return m_Uniforms[_CurrentSwapChain];
}

void GV_Obj::InsertUniform(int _Index, GV_Buffer _Buffer)
{
	//m_Uniforms.push_back(_Buffer);
	m_Uniforms[_Index] = _Buffer;
}

void GV_Obj::ResizeUniform(size_t _Size)
{
	m_Uniforms.clear();
	m_Uniforms.resize(_Size);
}

void GV_Obj::DestroyInstance(VkDevice _device)
{
	for (GV_Buffer Buffer : m_Uniforms)
	{
		vkDestroyBuffer(_device, Buffer.m_Buffer, nullptr);
		vkFreeMemory(_device, Buffer.m_BufferMemory, nullptr);
	}
	vkDestroyBuffer(_device, m_Index.m_Buffer, nullptr);
	vkFreeMemory(_device, m_Index.m_BufferMemory, nullptr);
	vkDestroyBuffer(_device, m_Vertex.m_Buffer, nullptr);
	vkFreeMemory(_device, m_Vertex.m_BufferMemory, nullptr);
}

