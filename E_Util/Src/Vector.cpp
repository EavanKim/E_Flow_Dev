#include "utilpch.hpp"

Vector::Vector()
	:_data({0.f, 0.f, 0.f, 0.f})
{

}

Vector::Vector(float _x, float _y, float _z, float _a)
	: _data({ _x, _y, _z, _a })
{

}

Vector::Vector(const Vector& other)
	: _data(other._data)
{
}

void Vector::set(const std::initializer_list<float>& _lst)
{
}

void Vector::set(const Vector& _other)
{
}

Vector& Vector::operator=(const std::initializer_list<float>& _lst)
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return (*this);
}

Vector& Vector::operator=(const Vector& _other)
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return (*this);
}

float& Vector::operator[](std::size_t _Index)
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return _data.m128_f32[_Index];
}

const float& Vector::operator[](std::size_t _Index) const
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return _data.m128_f32[_Index];
}

const __m128 Vector::GetData()
{
	return _data;
}
