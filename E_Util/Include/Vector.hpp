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

		void x(float _x);
		void y(float _y);
		void z(float _z);
		void a(float _a);

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

		Vector operator+(__m128 _Vector) const;
		Vector operator+(const Vector& _Vector) const;
		Vector operator-(__m128 _Vector) const;
		Vector operator-(const Vector& _Vector) const;
		Vector operator*(__m128 _Vector) const;
		Vector operator*(const Vector& _Vector) const;
		Vector operator/(__m128 _Vector) const;
		Vector operator/(const Vector& _Vector) const;

		float dot(__m128 _Vector) const;
		float dot(const Vector& _Vector) const;
		float cross(__m128 _Vector) const;
		float cross(const Vector& _Vector) const;

		float lengthSquared() const;
		float length() const;
		void normalize();
		Vector normalized() const;

		Vector projected(const Vector normal) const;

	private:
		__m128 _data;
	};
}

#endif