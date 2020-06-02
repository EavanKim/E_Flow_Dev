#pragma once

namespace AABB_Function
{
	enum AABB_LINE_DATA { AABB_LINE_MIN, AABB_LINE_MAX, AABB_LINE_CENTER, AABB_LINE_RADIUS, AABB_LINE_END };
	enum AABB_SPHERE_DATA { AABB_SPHERE_X, AABB_SPHERE_Y, AABB_SPHERE_Z, AABB_SPHERE_RADIUS, AABB_SPHERE_END };

	struct AABB_SPHERE
	{
		AABB_SPHERE(const glm::vec3& _pos, const float& _radiusLength)
			: data(_pos[AABB_SPHERE_DATA::AABB_SPHERE_X], _pos[AABB_SPHERE_DATA::AABB_SPHERE_X], _pos[AABB_SPHERE_DATA::AABB_SPHERE_X], _radiusLength)
		{

		}

		float operator[](AABB_SPHERE_DATA _index)
		{
			return data[_index];
		}

		glm::vec4 data = { 0.f, 0.f, 0.f, 0.f };
	};

	struct AABB_AXIS_ONE
	{
	public:
		AABB_AXIS_ONE(float _min, float _max);

		AABB_AXIS_ONE(float _min, float _max, float _center);

		AABB_AXIS_ONE(float _min, float _max, float _center, float _radiuslength);

		AABB_AXIS_ONE(const glm::vec2& _Axis);

		AABB_AXIS_ONE(const glm::vec4& _Axis);

		float operator[](AABB_LINE_DATA _index);

		glm::vec4 data = { 0.f, 0.f, 0.f, 0.f };
	};

	struct AABB_AXIS_TWO
	{
	public:
		AABB_AXIS_TWO(AABB_AXIS_ONE _Axis0, AABB_AXIS_ONE _Axis1)
		{
			axis0 = _Axis0;
			axis1 = _Axis1;
		}

		AABB_AXIS_ONE axis0 = { 0.f, 0.f };
		AABB_AXIS_ONE axis1 = { 0.f, 0.f };
	};

	struct AABB_AXIS_THREE
	{
	public:
		AABB_AXIS_THREE(AABB_AXIS_ONE _Axis0, AABB_AXIS_ONE _Axis1, AABB_AXIS_ONE _Axis2)
		{
			axis0 = _Axis0;
			axis1 = _Axis1;
			axis2 = _Axis2;
		}

		AABB_AXIS_ONE axis0 = { 0.f, 0.f };
		AABB_AXIS_ONE axis1 = { 0.f, 0.f };
		AABB_AXIS_ONE axis2 = { 0.f, 0.f };
	};

	bool calculation(const AABB_SPHERE& _0, const AABB_SPHERE& _1);
	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_ONE& _1);
	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_TWO& _1);
	bool calculation(const AABB_SPHERE& _0, const AABB_AXIS_THREE& _1);
	bool calculation(const AABB_AXIS_ONE& _0, const AABB_AXIS_ONE& _1);
	bool calculation(const AABB_AXIS_TWO& _0, const AABB_AXIS_TWO& _1);
	bool calculation(const AABB_AXIS_THREE& _0, const AABB_AXIS_THREE& _1);
	bool calculation(const glm::vec2& _0, const glm::vec2& _1);
	bool calculation(const glm::vec3& _0, const glm::vec3& _1);
};
