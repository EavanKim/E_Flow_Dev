#include "Graphic.h"

Static_Camera::Static_Camera(uint32_t _width, uint32_t _height, glm::vec3 _Distincet) : GV_Camera(_width, _height) { }

Static_Camera::Static_Camera(uint32_t _width, uint32_t _height, glm::vec3 _Distince, GV_Obj* _Player) : GV_Camera(_width, _height) { m_Player = _Player; }

Static_Camera::~Static_Camera()
{

}

void Static_Camera::SetUpCustomPosition(glm::vec3 _Pos)
{
	m_vecLook = _Pos;
	m_vecWorld = m_vecLook + m_vecDistance;
	m_matView = glm::lookAt(m_vecWorld, m_vecLook, m_vecUP);
}

void Static_Camera::SetUpCustomPosition(float _x, float _y, float _z)
{
	m_vecLook = glm::vec3(_x, _y, _z);
	m_vecWorld = m_vecLook + m_vecDistance;
	m_matView = glm::lookAt(m_vecWorld, m_vecLook, m_vecUP);
}

void Static_Camera::SetUpPlayerPosition()
{
	m_vecLook = m_Player->GetPosVector();
	m_vecWorld = m_vecLook + m_vecDistance;
	m_matView = glm::lookAt(m_vecWorld, m_vecLook, m_vecUP);
}

void Static_Camera::Update() { SetUpPlayerPosition(); }

void Static_Camera::Update(glm::vec3 _Pos) { SetUpCustomPosition(_Pos); }
