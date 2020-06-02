#ifndef GVOBJ_H__
#define GVOBJ_H__

class GRAPHIC_API GV_Obj : public GV_Instance
{
public:
	GV_Obj();
	GV_Obj(BUFFER_TYPE _Buffertype, IMAGE_TYPE _ImageType);
	GV_Obj(GV_Buffer _Vertex, GV_Buffer _Index, BUFFER_TYPE _Buffertype, IMAGE_TYPE _ImageType);
	virtual ~GV_Obj();

	void SetAngle(float _delta, glm::vec3 _tripleAngle);
	void SetAngle(float _delta, float _x, float _y, float _z);
	void rotateX(float _x);
	void rotateY(float _y);
	void rotateZ(float _z);
	void Move(glm::vec3 _moveVector);
	void Move(float _x, float _y, float _z);

	RENDER_TYPE GetRenderType();
	OBJECT_TYPE GetObjectType();
	BUFFER_TYPE GetBufferType();

	glm::mat4 MatWorld();
	glm::vec3 GetPosVector();

	GV_Buffer GetVertex();
	void GetVertex(GV_Buffer _Buffer);
	GV_Buffer GetIndex();
	void GetIndex(GV_Buffer _Buffer);
	GV_Buffer Uniform(int _CurrentSwapChain);
	void InsertUniform(int _Index, GV_Buffer _Buffer);
	void ResizeUniform(size_t _Size);

	virtual void DestroyInstance(VkDevice _device);

protected:
	GV_Buffer m_Vertex;
	GV_Buffer m_Index;
	std::vector<GV_Buffer> m_Uniforms;

	glm::vec3 m_Angle = glm::vec3(0.f);
	glm::mat4 m_MatWorld = glm::mat4(1.f);
	BUFFER_TYPE m_BufferType = BUFFER_TYPE::BUFFER_END;
	IMAGE_TYPE m_ImageType = IMAGE_TYPE::IMAGE_END;

	int CurrentSpriteKey = 0;
	std::map<std::string, int> mappingSpriteKey;

private:
	RENDER_TYPE m_Render = RENDER_TYPE::RENDER_END;
	OBJECT_TYPE m_ObjectType = OBJECT_TYPE::OBJECT_END;
};

#include "Sprite_Obj.h"

#endif
