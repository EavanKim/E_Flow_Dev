#ifndef VECTOR_HPP__
#define VECTOR_HPP__

class Vector
{
public:
	Vector();
	Vector(float _x, float _y, float _z, float _a);
	Vector(const Vector& other);

	void set(const std::initializer_list<float>& _lst);
	void set(const Vector& _other);

	Vector& operator=(const std::initializer_list<float>& _lst);
	Vector& operator=(const Vector& _other);

	float& operator[](std::size_t _Index);
	const float& operator[](std::size_t _Index) const;

	const __m128 GetData();

private:
	__m128 _data;
};

#endif