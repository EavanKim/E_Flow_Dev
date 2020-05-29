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

		virtual double sample(const Vector& _x) const = 0;

		Derivative GetAllDerivative();
		Derivative PartialDerivative(AXIS _Axis);

		Vector m_Vector;
	};

	class UTIL_EXPORTS VectorField3 : public Field3
	{
	public:
		VectorField3();

		virtual ~VectorField3();

		virtual Vector sample(const Vector& _x) const = 0;

	};
}
#endif // !FIELD3_HPP__
