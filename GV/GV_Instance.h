#pragma once

enum class GV_TYPE { OBJECT, CAMERA, MODULE, GV_END };
enum class CAMERA_TYPE { STATIC, DYNAMIC, CAMERA_END };
enum class BUFFER_TYPE { TRIANGLE_BUFFER, RECTANGLE_BUFFER, SQUER_BUFFER, SPRITE_BUFFER, BUFFER_END };
enum class IMAGE_TYPE { IMAGE_2D, IMAGE_3D, IMAGE_END };
enum class OBJECT_TYPE { TERRAIN, ENEMY, PLAYER, OBJECT_END };
enum class RENDER_TYPE { RENDER_END };

class GRAPHIC_API GV_Instance
{
public:
	GV_Instance() { }
	GV_Instance(GV_TYPE _Type) { m_InstanceType = _Type; }
	virtual ~GV_Instance() { }

	virtual void DestroyInstance(VkDevice _device) = 0;

protected:
	GV_TYPE m_InstanceType = GV_TYPE::GV_END;
};
