#include "utilpch.hpp"

Vector3F::Vector3F()
	:_data({0.f, 0.f, 0.f, 0.f})
{

}

Vector3F::Vector3F(float _x, float _y, float _z, float _a)
	: _data({ _x, _y, _z, _a })
{

}

Vector3F::Vector3F(const Vector3F& other)
	: _data(other._data)
{

}

void Vector3F::set(const std::initializer_list<float>& _lst)
{
}

void Vector3F::set(const Vector3F& _other)
{
}

Vector3F& Vector3F::operator=(const std::initializer_list<float>& _lst)
{
	// TODO: 여기에 return 문을 삽입합니다.

	return (*this);
}

Vector3F& Vector3F::operator=(const Vector3F& _other)
{
	// TODO: 여기에 return 문을 삽입합니다.

	return (*this);
}

float& Vector3F::operator[](std::size_t _Index)
{
	// TODO: 여기에 return 문을 삽입합니다.

	return _data.m128_f32[_Index];
}

const float& Vector3F::operator[](std::size_t _Index) const
{
	// TODO: 여기에 return 문을 삽입합니다.

	return _data.m128_f32[_Index];
}

