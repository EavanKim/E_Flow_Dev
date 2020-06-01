#include "pch.hpp"

int main()
{
	util::Vector test = {9.f, 8.f, 7.f, 6.f};

	util::Vector newvector = test.normalized();

	float croosss = test.dot(newvector);


	util::Vector T0 = { 90.f, 90.f, 90.f, 90.f };
	util::Vector T1 = { 100.f, 100.f, 100.f, 100.f };
	util::Vector R0 = util::E_Math::lerp(T0, T1, 0.5);

	util::Vector checkfunction0 = util::E_Math::bilerp(util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0), util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0), 0.5f, 0.5f);
	util::Vector checkfunction3 = util::E_Math::trilerp(util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0), util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0),
														util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0), util::Vector(90, 80, 70, 0), util::Vector(100, 90, 80, 0),
														0.5f, 0.5f, 0.5f);


	return 0;
}