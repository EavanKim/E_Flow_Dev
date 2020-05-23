#include "pch.hpp"

int main()
{
	Vector3F test = {1.f, 0.f, 1.f, 0.f};

	Vector3F* newvector = new Vector3F(test);

	delete newvector;
	newvector = nullptr;

	return 0;
}