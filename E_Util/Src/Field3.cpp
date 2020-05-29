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

util::Derivative util::ScalarField3::GetAllDerivative()
{
	float Sin_X = sinf(m_Vector.x());
	float Sin_Y = sinf(m_Vector.y());
	float Sin_Z = sinf(m_Vector.z());
	float Cos_X = cosf(m_Vector.x());
	float Cos_Y = cosf(m_Vector.y());
	float Cos_Z = cosf(m_Vector.z());

	__m128 Mem0 = _mm_set_ps(Sin_X, Cos_X, Sin_X, Sin_X);
	__m128 Mem1 = _mm_set_ps(Sin_Y, Sin_Y, Cos_Y, Sin_Y);
	__m128 Mem2 = _mm_set_ps(Sin_Z, Cos_Z, Sin_Z, Cos_Z);

	__m128 CalcMiddle = _mm_mul_ps(Mem0, Mem1);
	__m128 Result = _mm_mul_ps(CalcMiddle, Mem2);

	Derivative Returnvalue;

	Returnvalue.Derivative = Result.m128_f32[3];
	Returnvalue.Gradient = _mm_set_ps(Result.m128_f32[2], Result.m128_f32[1], Result.m128_f32[0], 0.f);

	return Returnvalue;
}

util::Derivative util::ScalarField3::PartialDerivative(AXIS _Axis)
{
	return Derivative();
}

util::VectorField3::VectorField3()
{

}

util::VectorField3::~VectorField3()
{

}
