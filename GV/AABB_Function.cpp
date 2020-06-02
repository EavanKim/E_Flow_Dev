#include "Graphic.h"

namespace AABB_Function
{
	AABB_AXIS_ONE::AABB_AXIS_ONE(float _min, float _max)
		: data(_min, _max, _min + std::abs(_min - _max) / 2, std::abs(_min - _max) / 2)
	{

	}

	AABB_AXIS_ONE::AABB_AXIS_ONE(float _min, float _max, float _center)
		: data(_min, _max, _center, std::abs(_min - _max) / 2)
	{

	}

	AABB_AXIS_ONE::AABB_AXIS_ONE(float _min, float _max, float _center, float _radiuslength)
		: data(_min, _max, _center, _radiuslength)
	{

	}

	AABB_AXIS_ONE::AABB_AXIS_ONE(const glm::vec2& _Axis)
		: data(_Axis[AABB_LINE_MIN], _Axis[AABB_LINE_MAX], _Axis[AABB_LINE_MIN] + std::abs(_Axis[AABB_LINE_MIN] - _Axis[AABB_LINE_MAX]) / 2, std::abs(_Axis[AABB_LINE_MIN] - _Axis[AABB_LINE_MAX]) / 2)
	{

	}

	AABB_AXIS_ONE::AABB_AXIS_ONE(const glm::vec4& _Axis)
		: data(_Axis)
	{

	}

	float AABB_AXIS_ONE::operator[](AABB_LINE_DATA _index)
	{
		return data[_index];
	}

	bool calculation(const AABB_SPHERE& _0, const AABB_SPHERE& _1)
	{
		float distance = glm::length(glm::vec3(_0.data[AABB_SPHERE_X], _0.data[AABB_SPHERE_Y], _0.data[AABB_SPHERE_Z]) - glm::vec3(_1.data[AABB_SPHERE_X], _1.data[AABB_SPHERE_Y], _1.data[AABB_SPHERE_Z]));

		if (distance > _0.data[AABB_SPHERE_RADIUS] + _1.data[AABB_SPHERE_RADIUS])
			return true;

		return false;
	}

	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_ONE& _1)
	{


		return false;
	}

	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_TWO& _1)
	{
		return false;
	}

	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_THREE& _1)
	{
		return false;
	}

	bool calculation(const AABB_AXIS_ONE& _0, const AABB_AXIS_ONE& _1)
	{
		float centerdistance = std::abs(_0.data[AABB_LINE_DATA::AABB_LINE_CENTER] - _1.data[AABB_LINE_DATA::AABB_LINE_CENTER]);
		if (centerdistance < _0.data[AABB_LINE_DATA::AABB_LINE_RADIUS] + _1.data[AABB_LINE_DATA::AABB_LINE_RADIUS])
			return true;

		return false;
	}
	bool calculation(const AABB_AXIS_TWO& _0, const AABB_AXIS_TWO& _1)
	{
		return calculation(_0.axis0, _1.axis0) | calculation(_0.axis1, _1.axis1);
	}
	bool calculation(const AABB_AXIS_THREE& _0, const AABB_AXIS_THREE& _1)
	{
		return calculation(_0.axis0, _1.axis0) | calculation(_0.axis1, _1.axis1) | calculation(_0.axis2, _1.axis2);
	}
	bool calculation(const glm::vec2& _0, const glm::vec2& _1)
	{
		return false;
	}

	bool calculation(const glm::vec3& _0, const glm::vec3& _1)
	{
		return false;
	}
}