#include "Graphic.h"

GV_Camera::GV_Camera(uint32_t _width, uint32_t _height) : GV_Instance(GV_TYPE::CAMERA)
{
	m_width = _width;
	m_height = _height;
	m_vecUP.y = 1.f;
	m_vecWorld = glm::vec3(0.f);
	m_vecDistance = glm::vec3(0.f, 0.f, 10.f);
	m_vecWorld = m_vecWorld + m_vecDistance;
	m_vecLook = glm::vec3(0.f, 0.f, 0.f);
	m_vecUP = glm::vec3(0.f, 1.f, 0.f);
	m_matView = glm::lookAt(m_vecWorld, m_vecLook, m_vecUP);
	m_matProj = glm::perspective(glm::radians(45.0f), m_width / (float)m_height, 0.1f, 100.0f);
}

GV_Camera::~GV_Camera()
{

}

void GV_Camera::DestroyInstance(VkDevice _device)
{

}

void GV_Camera::UpdatePLU()
{
	m_matView = glm::lookAt(m_vecWorld, m_vecLook, m_vecUP);
}

glm::mat4 GV_Camera::GetView()
{
	return glm::mat4(m_matView);
}

glm::mat4 GV_Camera::GetProj()
{
	return glm::mat4(m_matProj);
}
