#ifndef VECTOR_HPP__
#define VECTOR_HPP__

class UTIL_EXPORTS Vector3F
{
public:
	Vector3F();
	Vector3F(float _x, float _y, float _z, float _a);
	Vector3F(const Vector3F& other);

	void set(const std::initializer_list<float>& _lst);
	void set(const Vector3F& _other);

	Vector3F& operator=(const std::initializer_list<float>& _lst);
	Vector3F& operator=(const Vector3F& _other);

	float& operator[](std::size_t _Index);
	const float& operator[](std::size_t _Index) const;

private:
	__m128 _data;
};

#endif