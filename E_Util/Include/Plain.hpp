#ifndef PLAIN_HPP__
#define PLAIN_HPP__

namespace util
{
	class Ray
	{
		__m128 m_Data;
	};

	struct SurfaceRayIntersection3
	{
		bool isIntersecting;
		float t;
		Vector point;
		Vector normal;
	};

	class Plain
	{
	public:
		Plain();

		virtual ~Plain();

		virtual Vector closestPoint(const Vector& _otherPoint) const = 0;
		virtual Vector closestNormal(const Vector& _otherPoint) const = 0;
		virtual BoundingBox boundingBox() const = 0;

		virtual void getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const;

		virtual bool intersects(const Ray& _ray) const;

		virtual float closestDistance(const Vector& _otherPoint) const;
	};
}

#endif