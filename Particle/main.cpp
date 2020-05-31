#include "pch.hpp"

int main()
{
	util::Vector test = {9.f, 8.f, 7.f, 6.f};

	util::Vector newvector = test.normalized();

	float croosss = test.dot(newvector);

	float checkfunction0 = util::E_Math::old_bilerp(90.f, 100.f, 90.f, 100.f, 0.5f, 0.5f);
	float checkfunction1 = util::E_Math::bilerp(90.f, 100.f, 90.f, 100.f, 0.5f, 0.5f);

	if (checkfunction0 != checkfunction1)
	{
		int i = 0;
	}

	float checkfunction2 = util::E_Math::old_trilerp(90.f, 100.f, 90.f, 100.f, 90.f, 100.f, 90.f, 100.f, 0.5f, 0.5f, 0.5f);
	float checkfunction3 = util::E_Math::trilerp(90.f, 100.f, 90.f, 100.f, 90.f, 100.f, 90.f, 100.f, 0.5f, 0.5f, 0.5f);

	if (checkfunction2 != checkfunction3)
	{
		int i = 0;
	}

	util::Vector T0 = {90.f, 90.f, 90.f, 90.f};
	util::Vector T1 = {100.f, 100.f, 100.f, 100.f};
	util::Vector R0 = util::E_Math::lerp(T0, T1, 0.5);

	return 0;
}