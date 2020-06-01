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

		float x() const;
		float y() const;
		float z() const;
		float a() const;

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

		Vector operator+(float _val) const;
		Vector operator-(float _val) const;
		Vector operator*(float _val) const;
		Vector operator/(float _val) const;

		float dot(__m128 _Vector) const;
		float dot(const Vector& _Vector) const;
		Vector cross(__m128 _Vector) const;
		Vector cross(const Vector& _Vector) const;

		float lengthSquared() const;
		float length() const;
		void normalize();
		Vector normalized() const;

		Vector projected(const Vector& normal) const;
		Vector reflected(const Vector& noraml) const;

		bool isSimiler(const Vector& _other) const;
		float distanceTo(const Vector& _other) const;

		std::tuple<Vector, Vector> tangential() const;

	private:
		__m128 _data;
	};
}

#endif