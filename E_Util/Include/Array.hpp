#ifndef ARRAY_HPP__
#define ARRAY_HPP__

template<typename T, size_t N>
class Array final{};

template<typename T>
class Array<T, 1> final 
{
public:
	Array();

	T& operator [] (size_t _Index);
	const T& operator [] (size_t _Index) const;

	size_t size() const;

private:
	std::vector<T> _data;
};

template <typename T> using Array1 = Array<T, 1>;

#include "Array_Impl.hpp"
#endif
