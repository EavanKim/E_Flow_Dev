#ifndef POLYGON_HPP__
#define POLYGON_HPP__

namespace util
{
	class Triangle : vSurface
	{
	public:
		std::array<Vector, 3> points;
		std::array<Vector, 3> normals;
		std::array<Vector, 3> uvs;

		Triangle();
		Triangle(const std::array<Vector, 3>& newPoints, const std::array<Vector, 3>& newNormals, std::array<Vector, 3> newUvs);

		Vector closestPoint(const Vector& _otherPoint) const override;
		Vector closestNormal(const Vector& _otherPoint) const override;

		void getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const override;

		bool intersects(const Ray& _ray) const override;

		BoundingBox boundingBox() const override;
	};

	class Polygon : vSurface
	{
	public:
		typedef std::vector<Vector> VectorArray;
		typedef std::vector<Vector> IndexArray;

		Polygon();
		Polygon(const Polygon& _other);

		Vector closestPoint(const Vector& _otherPoint) const override;
		Vector closestNormal(const Vector& _otherPoint) const override;

		void getClosestIntersection(const Ray& _ray, SurfaceRayIntersection3* _intersection) const override;

		BoundingBox boundingBox() const override;

		bool intersects(const Ray& _ray) const override;

		float closestDistance(const Vector& _otherPoint) const override;

	private:
		VectorArray _points;
		VectorArray _normals;
		VectorArray _uvs;
		IndexArray _pointIndices;
		IndexArray _normalIndices;
		IndexArray _uvIndices;
	};
}

#endif // !POLYGON_HPP__
