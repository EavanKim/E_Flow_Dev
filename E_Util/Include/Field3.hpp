#ifndef FIELD3_HPP__
#define FIELD3_HPP__

namespace util
{

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
