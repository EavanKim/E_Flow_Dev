#ifndef SPHERE_HPP__
#define SPHERE_HPP__

namespace util
{
	class Sphere : vSurface
	{
	public:
		Sphere(const Vector& _center, float _radius);
		
		Vector closestPoint(const Vector& _otherPoint) const override;
		Vector closestNormal(const Vector& _otherPoint) const override;

		void getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _Intersection) const override;

		BoundingBox boundingBox() const override;

	private:
		Vector center;
		float radius = 1.f;
	};

	class ImplicitSphere final : public ImplicitSurface
	{
	public:
		ImplicitSphere(const Vector& _center, float _radius);
		float signedDistance(const Vector& _otherPoint) const override;

	private:
		Vector center;
		float radius = 1.f;
	};
}

#endif