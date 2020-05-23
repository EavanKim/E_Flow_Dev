#include "pch.hpp"

int main()
{
	util::Vector test = {9.f, 8.f, 7.f, 6.f};

	util::Vector newvector = test.normalized();

	float croosss = test.dot(newvector);

	return 0;
}