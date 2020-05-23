#include "pch.hpp"

int main()
{
	util::Vector test = {1.f, 0.f, 1.f, 0.f};

	util::Vector* newvector = new util::Vector(test);

	delete newvector;
	newvector = nullptr;

	return 0;
}