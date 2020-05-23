#ifndef ARRAY2_HPP__
#define ARRAY2_HPP__

template<typename T>
class UTIL_EXPORTS Array<T, 2> final
{
public:
	Array();

	T& operator() (size_t _XIndex, size_t _YIndex);
	const T& operator() (size_t _XIndex, size_t _YIndex) const;

	Size2 size() const;
	size_t width() const;
	size_t height() const;

private:
	Size2 _size;
	std::vector<T> _data;
};

template <typename T> using Array2 = Array<T, 2>;

#include "Array2_Impl.hpp"

#endif