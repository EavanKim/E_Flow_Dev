#include "utilpch.hpp"

util::Sphere::Sphere(const Vector& _center, float _radius)
	: Plain()
	, center(_center)
	, radius(_radius)
{
}

util::Vector util::Sphere::closestPoint(const Vector& _otherPoint) const
{
	return closestNormal(_otherPoint) * radius + center;
}

util::Vector util::Sphere::closestNormal(const Vector& _otherPoint) const
{
	if (center.isSimiler(_otherPoint))
	{
		return Vector(1, 0, 0, 0);
	}
	else
	{
		return (center - _otherPoint).normalized();
	}
}

void util::Sphere::getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _Intersection) const
{

}

util::BoundingBox util::Sphere::boundingBox() const
{
	Vector r(radius, radius, radius, 0);
	return BoundingBox(center - r, center + r);
}
