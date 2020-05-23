#ifndef VECTOR_HPP__
#define VECTOR_HPP__

namespace util
{
	class UTIL_EXPORTS Vector
	{
	public:
		Vector();
		Vector(__m128 _Vector);
		Vector(float _x, float _y, float _z, float _a);
		Vector(const Vector& other);

		void set(const std::initializer_list<float>& _lst);
		void set(const Vector& _other);

		Vector& operator=(const std::initializer_list<float>& _lst);
		Vector& operator=(const Vector& _other);

		float& operator[](std::size_t _Index);
		const float& operator[](std::size_t _Index) const;

		Vector add(__m128 _Vector) const;
		Vector add(const Vector& _Vector) const;
		Vector sub(__m128 _Vector) const;
		Vector sub(const Vector& _Vector) const;
		Vector mul(__m128 _Vector) const;
		Vector mul(const Vector& _Vector) const;
		Vector div(__m128 _Vector) const;
		Vector div(const Vector& _Vector) const;
		float dot(__m128 _Vector) const;
		float dot(const Vector& _Vector) const;
		float cross3(__m128 _Vector) const;
		float cross3(const Vector& _Vector) const;
		float cross4(__m128 _Vector) const;
		float cross4(const Vector& _Vector) const;


	private:
		__declspec (align (128)) __m128 _data;
	};
}

#endif