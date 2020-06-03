#include "utilpch.hpp"

util::vSurface::vSurface()
{
}

util::vSurface::~vSurface()
{
}

util::Vector util::vSurface::closestPoint(const Vector& _otherPoint) const
{
	return Vector();
}

util::Vector util::vSurface::closestNormal(const Vector& _otherPoint) const
{
	return Vector();
}

util::BoundingBox util::vSurface::boundingBox() const
{
	return BoundingBox(Vector(), Vector());
}

void util::vSurface::getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const
{

}

bool util::vSurface::intersects(const Ray& _ray) const
{
	SurfaceRayIntersection3 Intersect;
	getClosestIntersection(_ray, &Intersect);
	return Intersect.isIntersecting;
}

float util::vSurface::closestDistance(const Vector& _otherPoint) const
{
	return _otherPoint.distanceTo(closestPoint(_otherPoint));
}

util::ImplicitSurface::ImplicitSurface()
{
}

util::ImplicitSurface::~ImplicitSurface()
{
}
