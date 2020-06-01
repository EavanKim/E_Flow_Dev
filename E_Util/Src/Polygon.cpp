#include "utilpch.hpp"

util::Polygon::Polygon()
{
}

util::Polygon::Polygon(const Polygon& _other)
{
}

util::Vector util::Polygon::closestPoint(const Vector& _otherPoint) const
{
	return Vector();
}

util::Vector util::Polygon::closestNormal(const Vector& _otherPoint) const
{
	return Vector();
}

void util::Polygon::getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const
{
}

util::BoundingBox util::Polygon::boundingBox() const
{
	return BoundingBox(Vector(), Vector());
}

bool util::Polygon::intersects(const Ray& _ray) const
{
	return false;
}

float util::Polygon::closestDistance(const Vector& _otherPoint) const
{
	return 0.0f;
}
