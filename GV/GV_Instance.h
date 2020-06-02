#pragma once

enum GV_TYPE { OBJECT, CAMERA, MODULE, GV_END };
enum CAMERA_TYPE { STATIC, DYNAMIC, CAMERA_END };
enum BUFFER_TYPE { TRIANGLE_BUFFER, RECTANGLE_BUFFER, SQUER_BUFFER, SPRITE_BUFFER, BUFFER_END };
enum IMAGE_TYPE { IMAGE_2D, IMAGE_3D, IMAGE_END };
enum OBJECT_TYPE { PLAYER, ENEMY, OBJECT_END };
enum RENDER_TYPE { RENDER_END };

class GRAPHIC_API GV_Instance
{
public:
	GV_Instance() {}
	GV_Instance(GV_TYPE _Type) { m_InstanceType = _Type; }
	virtual ~GV_Instance() { }

	virtual void DestroyInstance(VkDevice _device) = 0;

protected:
	GV_TYPE m_InstanceType = GV_TYPE::GV_END;
};

