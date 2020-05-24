#include "utilpch.hpp"

namespace util
{
	Vector::Vector()
		:_data({ 0.f, 0.f, 0.f, 0.f })
	{

	}

	Vector::Vector(__m128 _Vector)
		: _data(_Vector)
	{
	}

	Vector::Vector(float _x, float _y, float _z, float _a)
		: _data({ _x, _y, _z, _a })
	{

	}

	Vector::Vector(const Vector& _other)
		: _data(_other._data)
	{

	}

	float Vector::x()
	{
		return _data.m128_f32[0];
	}

	float Vector::y()
	{
		return _data.m128_f32[1];
	}

	float Vector::z()
	{
		return _data.m128_f32[2];
	}

	float Vector::a()
	{
		return _data.m128_f32[3];
	}

	void Vector::set(const std::initializer_list<float>& _lst)
	{
		int Index = 0;
		for (float Iterator : _lst)
		{
			_data.m128_f32[Index] = Iterator;
			++Index;
		}
	}

	void Vector::set(const Vector& _other)
	{
		_data = _other._data;
	}

	Vector& Vector::operator=(const std::initializer_list<float>& _lst)
	{
		// TODO: 여기에 return 문을 삽입합니다.
		int Index = 0;
		for (float Iterator : _lst)
		{
			_data.m128_f32[Index] = Iterator;
			++Index;
		}

		return (*this);
	}

	Vector& Vector::operator=(const Vector& _other)
	{
		// TODO: 여기에 return 문을 삽입합니다.

		return (*this);
	}

	float& Vector::operator[](std::size_t _Index)
	{
		// TODO: 여기에 return 문을 삽입합니다.

		return _data.m128_f32[_Index];
	}

	const float& Vector::operator[](std::size_t _Index) const
	{
		// TODO: 여기에 return 문을 삽입합니다.

		return _data.m128_f32[_Index];
	}

	Vector Vector::add(__m128 _Vector) const
	{
		return Vector(_mm_add_ps(_data, _Vector));
	}

	Vector Vector::add(const Vector& _Vector) const
	{
		return Vector(_mm_add_ps(_data, _Vector._data));
	}

	Vector Vector::sub(__m128 _Vector) const
	{
		return Vector(_mm_sub_ps(_data, _Vector));
	}

	Vector Vector::sub(const Vector& _Vector) const
	{
		return Vector(_mm_sub_ps(_data, _Vector._data));
	}

	Vector Vector::mul(__m128 _Vector) const
	{
		return Vector(_mm_mul_ps(_data, _Vector));
	}

	Vector Vector::mul(const Vector& _Vector) const
	{
		return Vector(_mm_mul_ps(_data, _Vector._data));
	}

	Vector Vector::div(__m128 _Vector) const
	{
		return Vector(_mm_div_ps(_data, _Vector));
	}

	Vector Vector::div(const Vector& _Vector) const
	{
		return Vector(_mm_div_ps(_data, _Vector._data));
	}

	Vector Vector::operator+(__m128 _Vector) const
	{
		return Vector(_mm_add_ps(_data, _Vector));
	}

	Vector Vector::operator+(const Vector& _Vector) const
	{
		return Vector(_mm_add_ps(_data, _Vector._data));
	}

	Vector Vector::operator-(__m128 _Vector) const
	{
		return Vector(_mm_sub_ps(_data, _Vector));
	}

	Vector Vector::operator-(const Vector& _Vector) const
	{
		return Vector(_mm_sub_ps(_data, _Vector._data));
	}

	Vector Vector::operator*(__m128 _Vector) const
	{
		return Vector(_mm_mul_ps(_data, _Vector));
	}

	Vector Vector::operator*(const Vector& _Vector) const
	{
		return Vector(_mm_mul_ps(_data, _Vector._data));
	}

	Vector Vector::operator/(__m128 _Vector) const
	{
		return Vector(_mm_div_ps(_data, _Vector));
	}

	Vector Vector::operator/(const Vector& _Vector) const
	{
		return Vector(_mm_div_ps(_data, _Vector._data));
	}

	Vector Vector::operator+(float _val) const
	{
		return Vector(add(_mm_set_ps(_val, _val, _val, _val)));
	}

	Vector Vector::operator-(float _val) const
	{
		return Vector(sub(_mm_set_ps(_val, _val, _val, _val)));
	}

	Vector Vector::operator*(float _val) const
	{
		return Vector(mul(_mm_set_ps(_val, _val, _val, _val)));
	}

	Vector Vector::operator/(float _val) const
	{
		if (!_val)
			return Vector();
		return Vector(div(_mm_set_ps(_val, _val, _val, _val)));
	}

	float Vector::dot(__m128 _Vector) const
	{
		__declspec (align (128)) __m128 Calc = _mm_mul_ps(_data, _Vector);
		return Calc.m128_f32[0] + Calc.m128_f32[1] + Calc.m128_f32[2] + Calc.m128_f32[3];
	}

	float Vector::dot(const Vector& _Vector) const
	{
		__declspec (align (128)) __m128 Calc = _mm_mul_ps(_data, _Vector._data);
		return Calc.m128_f32[0] + Calc.m128_f32[1] + Calc.m128_f32[2] + Calc.m128_f32[3];
	}

	Vector Vector::cross(__m128 _Vector) const
	{
		__declspec (align (128)) __m128 Temp0 = _mm_set_ps(0.f, _Vector.m128_f32[0], _Vector.m128_f32[2], _Vector.m128_f32[1]);
		__declspec (align (128)) __m128 Temp1 = _mm_set_ps(0.f, _Vector.m128_f32[1], _Vector.m128_f32[2], _Vector.m128_f32[0]);
		__declspec (align (128)) __m128 Mul0 = _mm_mul_ps(_data, Temp0);
		__declspec (align (128)) __m128 Mul1 = _mm_mul_ps(_data, Temp1);
		__declspec (align (128)) __m128 Return = _mm_sub_ps(Mul0, Mul1);

		return _mm_sub_ps(Mul0, Mul1);
	}

	Vector Vector::cross(const Vector& _Vector) const
	{
		__declspec (align (128)) __m128 Temp0 = _mm_set_ps(0.f, _Vector._data.m128_f32[0], _Vector._data.m128_f32[2], _Vector._data.m128_f32[1]);
		__declspec (align (128)) __m128 Temp1 = _mm_set_ps(0.f, _Vector._data.m128_f32[1], _Vector._data.m128_f32[2], _Vector._data.m128_f32[0]);
		__declspec (align (128)) __m128 Mul0 = _mm_mul_ps(_data, Temp0);
		__declspec (align (128)) __m128 Mul1 = _mm_mul_ps(_data, Temp1);
		__declspec (align (128)) __m128 Return = _mm_sub_ps(Mul0, Mul1);

		return _mm_sub_ps(Mul0, Mul1);
	}

	float Vector::lengthSquared() const
	{
		__declspec (align (128)) __m128 Calc = _mm_mul_ps(_data, _data);
		return Calc.m128_f32[0] + Calc.m128_f32[1] + Calc.m128_f32[2];
	}

	float Vector::length() const
	{
		return std::sqrt(lengthSquared());
	}

	void Vector::normalize() 
	{
		__declspec (align (128)) __m128 Temp0 = _mm_set_ps(length(), length(), length(), length());
		__declspec (align (128)) __m128 Result = _mm_div_ps(_data, Temp0);
		_data = Result;
	}

	Vector Vector::normalized() const
	{
		__declspec (align (128)) __m128 Temp0 = _mm_set_ps(length(), length(), length(), length());
		return Vector(_mm_div_ps(_data, Temp0));
	}

	Vector Vector::projected(const Vector& _normal) const
	{
		return sub(_normal * dot(_normal));
	}

	Vector Vector::reflected(const Vector& _normal) const
	{
		return sub(_normal * (2 * dot(_normal)));
	}

	std::tuple<Vector, Vector> Vector::tangential() const
	{
		Vector a = (((std::fabsf(_data.m128_f32[1]) > 0) || (std::fabsf(_data.m128_f32[2]) > 0)) ? Vector(1, 0, 0, 0) : Vector(0, 1, 0, 0)).cross(*this).normalized();
		Vector b = cross(a);
		return std::tuple<Vector, Vector>(a, b);
	}

}
