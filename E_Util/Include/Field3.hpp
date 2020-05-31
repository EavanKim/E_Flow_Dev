#ifndef FIELD3_HPP__
#define FIELD3_HPP__

namespace util
{
	enum AXIS { X, Y, Z };

	class UTIL_EXPORTS Derivative
	{

	public:
		float Derivative;
		__m128 Gradient;
	};

	class UTIL_EXPORTS Field3
	{
	public:
		Field3();

		virtual ~Field3();
	};

	class UTIL_EXPORTS ScalarField3 : public Field3
	{
	public:
		ScalarField3();

		virtual ~ScalarField3();

		virtual float sample(const Vector& _v) const = 0;

		Derivative GetAllDerivative(Vector _vector);
		float PartialDerivative(AXIS _Axis, Vector _vector);

		Vector m_Vector;
	};

	class UTIL_EXPORTS VectorField3 : public Field3
	{
	public:
		VectorField3();

		virtual ~VectorField3();

		virtual Vector sample(const Vector& _v) const = 0;

		virtual float divergence(const Vector _vector) const = 0;
	};
}
#endif // !FIELD3_HPP__
