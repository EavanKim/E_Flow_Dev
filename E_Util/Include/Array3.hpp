#ifndef ARRAY3_HPP__
#define ARRAY3_HPP__

template<typename T>
class Array<T, 3> final
{
public:
	Array();

	T& operator() (size_t _XIndex, size_t _YIndex, size_t _ZIndex);
	const T& operator() (size_t _XIndex, size_t _YIndex, size_t _ZIndex) const;

	Size3 size() const;
	size_t width() const;
	size_t height() const;
	size_t depth() const;

private:
	Size3 _size;
	std::vector<T> _data;
};

template <typename T> using Array3 = Array<T, 3>;

#include "Array3_Impl.hpp"

#endif