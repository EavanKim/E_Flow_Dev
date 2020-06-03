#ifndef PLAIN_HPP__
#define PLAIN_HPP__

namespace util
{
	class Ray
	{
		__m128 m_Point;
		__m128 m_Direction;
	};

	struct SurfaceRayIntersection3
	{
		bool isIntersecting;
		float t;
		Vector point;
		Vector normal;
	};

	class vSurface
	{
	public:
		vSurface();

		virtual ~vSurface();

		virtual Vector closestPoint(const Vector& _otherPoint) const = 0;
		virtual Vector closestNormal(const Vector& _otherPoint) const = 0;
		virtual BoundingBox boundingBox() const = 0;

		virtual void getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const;

		virtual bool intersects(const Ray& _ray) const;

		virtual float closestDistance(const Vector& _otherPoint) const;
	};

	class ImplicitSurface : public vSurface
	{
	public:
		ImplicitSurface();
		virtual ~ImplicitSurface();

		virtual float signedDistance(const Vector& _otherPoint) const = 0;
	};
}

#endif