#ifndef EMATH_HPP__
#define EMATH_HPP__

namespace util
{
	class E_Math
	{
	public:
		static float lerp(const float& _Point0, const float& _Point1, float _Time) 
		{
			return (1 - _Time) * _Point0 + _Time * _Point1;
		}

		static float bilerp(const float& _x0, const float& _x1, const float& _y0, const float& _y1, float _time)
		{
			float _time0 = 1 - _time;

			__m128 mem0 = _mm_set_ps(0.f, 0.f, _y0, _x0);
			__m128 memT0 = _mm_set_ss(_time0);
			
			__m128 Middle0 = _mm_mul_ps(mem0, memT0);
			
			__m128 mem1 = _mm_set_ps(0.f, 0.f, _y1, _x1);
			__m128 memT1 = _mm_set_ss(_time);

			__m128 Middle1 = _mm_mul_ps(mem1, memT1);

			__m128 result = _mm_add_ps(Middle0, Middle1);

			return lerp(result.m128_f32[0], result.m128_f32[1], _time);
		}

		static float bilerp(const float& _x0, const float& _x1, const float& _y0, const float& _y1, float _time0, float _time1)
		{
			float time0 = 1 - _time0;

			__m128 mem0 = _mm_set_ps(0.f, 0.f, _y0, _x0);
			__m128 memT0 = _mm_set_ps(time0, time0, time0, time0);

			__m128 Middle0 = _mm_mul_ps(mem0, memT0);

			__m128 mem1 = _mm_set_ps(0.f, 0.f, _y1, _x1);
			__m128 memT1 = _mm_set_ps(_time0, _time0, _time0, _time0);

			__m128 Middle1 = _mm_mul_ps(mem1, memT1);

			__m128 result = _mm_add_ps(Middle0, Middle1);

			return lerp(result.m128_f32[0], result.m128_f32[1], _time1);
		}

		static float old_bilerp(const float& _x0, const float& _x1, const float& _y0, const float& _y1, float _time0, float _time1)
		{
			return lerp(lerp(_x0, _x1, _time0), lerp(_y0, _y1, _time0), _time1);
		}

		static float trilerp(const float& _x00, const float& _x01, const float& _y00, const float& _y01, const float& _x10, const float& _x11, const float& _y10, const float& _y11, float _time)
		{
			float time0 = 1 - _time;

			__m128 memT0 = _mm_set_ps(time0, time0, time0, time0);
			__m128 memT1 = _mm_set_ps(_time, _time, _time, _time);

			__m128 mem0 = _mm_set_ps(_y10, _y00, _x10, _x00);
			__m128 mem1 = _mm_set_ps(_y11, _y01, _x11, _x01);

			__m128 Middle0 = _mm_mul_ps(mem0, memT0);
			__m128 Middle1 = _mm_mul_ps(mem1, memT1);

			__m128 midresult = _mm_add_ps(Middle0, Middle1);

			__m128 midmem0 = _mm_set_ps(0.f, 0.f, midresult.m128_f32[1], midresult.m128_f32[0]);

			__m128 Middle2 = _mm_mul_ps(midmem0, memT0);

			__m128 midmem1 = _mm_set_ps(0.f, 0.f, midresult.m128_f32[3], midresult.m128_f32[2]);

			__m128 Middle3 = _mm_mul_ps(midmem1, memT1);

			__m128 result = _mm_add_ps(Middle2, Middle3);

			return lerp(result.m128_f32[0], result.m128_f32[1], _time);
		}

		static float trilerp(const float& _x00, const float& _x01, const float& _y00, const float& _y01, const float& _x10, const float& _x11, const float& _y10, const float& _y11, float _time0, float _time1, float _time2)
		{
			float time0 = 1 - _time0;
			__m128 memT0 = _mm_set_ps(time0, time0, time0, time0);
			__m128 memT1 = _mm_set_ps(_time0, _time0, _time0, _time0);
			float time1 = 1 - _time1;
			__m128 memT2 = _mm_set_ps(time1, time1, time1, time1);
			__m128 memT3 = _mm_set_ps(_time1, _time1, _time1, _time1);

			__m128 mem0 = _mm_set_ps(_y10, _y00, _x10, _x00);
			__m128 mem1 = _mm_set_ps(_y11, _y01, _x11, _x01);

			__m128 Middle0 = _mm_mul_ps(mem0, memT0);
			__m128 Middle1 = _mm_mul_ps(mem1, memT1);
			__m128 midresult = _mm_add_ps(Middle0, Middle1);

			__m128 midmem0 = _mm_set_ps(0.f, 0.f, midresult.m128_f32[3], midresult.m128_f32[2]);

			__m128 Middle2 = _mm_mul_ps(midresult, memT2);
			__m128 Middle3 = _mm_mul_ps(midmem0, memT3);
			__m128 result = _mm_add_ps(Middle2, Middle3);

			return lerp(result.m128_f32[0], result.m128_f32[1], _time2);
		}

		static float old_trilerp(const float& _x00, const float& _x01, const float& _y00, const float& _y01, const float& _x10, const float& _x11, const float& _y10, const float& _y11, float _time0, float _time1, float _time2)
		{
			return lerp(old_bilerp(_x00, _x01, _y00, _y01, _time0, _time1), old_bilerp(_x10, _x11, _y10, _y11, _time0, _time1), _time2);
		}
	};
}

#endif