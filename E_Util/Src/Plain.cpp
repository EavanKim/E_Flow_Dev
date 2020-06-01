#include "utilpch.hpp"

util::Plain::Plain()
{
}

util::Plain::~Plain()
{
}

util::Vector util::Plain::closestPoint(const Vector& _otherPoint) const
{
	return Vector();
}

util::Vector util::Plain::closestNormal(const Vector& _otherPoint) const
{
	return Vector();
}

util::BoundingBox util::Plain::boundingBox() const
{
	return BoundingBox(Vector(), Vector());
}

void util::Plain::getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const
{

}

bool util::Plain::intersects(const Ray& _ray) const
{
	SurfaceRayIntersection3 Intersect;
	getClosestIntersection(_ray, &Intersect);
	return Intersect.isIntersecting;
}

float util::Plain::closestDistance(const Vector& _otherPoint) const
{
	return _otherPoint.distanceTo(closestPoint(_otherPoint));
}
