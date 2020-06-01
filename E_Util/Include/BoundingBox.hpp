#ifndef BOUNDINGBOX_HPP__
#define BOUNDINGBOX_HPP__

namespace util
{
	class BoundingBox
	{
	public:
		BoundingBox(Vector _lefttop, Vector _rightbottom);



		Vector LeftTop = { 0.f, 0.f, 0.f, 0.f };
		Vector RightBottom = { 0.f, 0.f, 0.f, 0.f };
	};
}

#endif // !BOUNDINGBOX_HPP__
