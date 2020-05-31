#include "utilpch.hpp"

util::Field3::Field3()
{

}

util::Field3::~Field3()
{

}

util::ScalarField3::ScalarField3()
{

}

util::ScalarField3::~ScalarField3()
{

}

float util::ScalarField3::sample(const Vector& _v) const
{
	return sinf(_v.x()) * sinf(_v.y()) * sinf(_v.z());
}

util::Derivative util::ScalarField3::GetAllDerivative(Vector _vector)
{
	float Sin_X = sinf(_vector.x());
	float Sin_Y = sinf(_vector.y());
	float Sin_Z = sinf(_vector.z());
	float Cos_X = cosf(_vector.x());
	float Cos_Y = cosf(_vector.y());
	float Cos_Z = cosf(_vector.z());

	__m128 Mem0 = _mm_set_ps(Sin_X, Sin_X, Cos_X, Sin_X);
	__m128 Mem1 = _mm_set_ps(Sin_Y, Cos_Y, Sin_Y, Sin_Y);
	__m128 Mem2 = _mm_set_ps(Cos_Z, Sin_Z, Sin_Z, Sin_Z);

	__m128 CalcMiddle = _mm_mul_ps(Mem0, Mem1);
	__m128 Result = _mm_mul_ps(CalcMiddle, Mem2);

	Derivative Returnvalue;

	Returnvalue.Derivative = Result.m128_f32[0];
	Returnvalue.Gradient = _mm_set_ps(0.f, Result.m128_f32[3], Result.m128_f32[2], Result.m128_f32[1]);

	return Returnvalue;
}

float util::ScalarField3::PartialDerivative(AXIS _Axis, Vector _vector)
{
	float sin0;
	float sin1;
	float cos0;

	switch (_Axis)
	{
	case AXIS::X:
		cos0 = cosf(_vector.x());
		sin0 = sinf(_vector.y());
		sin1 = sinf(_vector.z());
		break;
	case AXIS::Y:
		sin0 = sinf(_vector.x());
		cos0 = cosf(_vector.y());
		sin1 = sinf(_vector.z());
		break;
	case AXIS::Z:
		sin0 = sinf(_vector.x());
		sin1 = sinf(_vector.y());
		cos0 = cosf(_vector.z());
		break;
	default:
		return 0.f;
	}

	return sin0 * sin1 * cos0;
}

util::VectorField3::VectorField3()
{

}

util::VectorField3::~VectorField3()
{

}

util::Vector util::VectorField3::sample(const Vector& _vector) const
{
	return Vector();
}

float util::VectorField3::divergence(const Vector _vector) const
{
	float Sin_X = sinf(_vector.x());
	float Sin_Y = sinf(_vector.y());
	float Sin_Z = sinf(_vector.z());
	float Cos_X = cosf(_vector.x());
	float Cos_Y = cosf(_vector.y());
	float Cos_Z = cosf(_vector.z());

	__m128 Mem0 = _mm_set_ps(0.f, Sin_Z, Sin_Y, Sin_X);
	__m128 Mem1 = _mm_set_ps(0.f, Cos_Z, Cos_Y, Cos_X);
	__m128 Result = _mm_mul_ps(Mem0, Mem1);

	return Result.m128_f32[0] + Result.m128_f32[1] + Result.m128_f32[2] + Result.m128_f32[3];
}
