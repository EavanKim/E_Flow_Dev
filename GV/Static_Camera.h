#pragma once
class Static_Camera : public GV_Camera
{
public:
	Static_Camera(uint32_t _width, uint32_t _height, glm::vec3 _Distince);
	Static_Camera(uint32_t _width, uint32_t _height, glm::vec3 _Distince, GV_Obj* _Player);
	~Static_Camera();

	void SetUpCustomPosition(glm::vec3 _Pos);
	void SetUpCustomPosition(float _x, float _y, float _z);
	void SetUpPlayerPosition();

	virtual void Update();
	virtual void Update(glm::vec3 _Pos);

protected:


private:
	GV_Obj* m_Player = nullptr;
};

