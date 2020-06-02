#ifndef GVCAMERA_H__
#define GVCAMERA_H__

class GRAPHIC_API GV_Camera : GV_Instance
{
public:
	GV_Camera(uint32_t _width, uint32_t _height);
	~GV_Camera();

	virtual void DestroyInstance(VkDevice _device);
	virtual void Update() = 0;
	virtual void Update(glm::vec3 _Pos) = 0;


	glm::mat4 GetView();
	glm::mat4 GetProj();

protected:
	void UpdatePLU();
	glm::vec3 m_vecWorld; // Initialize In Creater
	glm::vec3 m_vecDistance; // Initialize In Creater
	glm::vec3 m_vecUP; // Initialize In Creater
	glm::vec3 m_vecLook; // Initialize In Creater
	glm::mat4 m_matView; // Initialize In Creater
	glm::mat4 m_matProj; // Initialize In Creater
	CAMERA_TYPE m_Type = CAMERA_TYPE::CAMERA_END;

private:
	uint32_t m_width = 0;
	uint32_t m_height = 0;

};

#endif // !GVCAMERA_H__
