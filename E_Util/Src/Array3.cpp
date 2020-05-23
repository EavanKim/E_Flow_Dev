#include <utilpch.hpp>

template<typename T>
T& Array<T, 3>::operator()(size_t _XIndex, size_t _YIndex, size_t _ZIndex)
{
	// TODO: 여기에 return 문을 삽입합니다.

	return _data[_XIndex + _size.x * (_YIndex + _size.y * _ZIndex)];
}

template<typename T>
const T& Array<T, 3>::operator()(size_t _XIndex, size_t _YIndex, size_t _ZIndex) const
{
	// TODO: 여기에 return 문을 삽입합니다.

	return _data[_XIndex + _size.x * (_YIndex + _size.y * _ZIndex)];
}

template<typename T>
size_t Array<T, 3>::width() const
{
	return size_t();
}

template<typename T>
size_t Array<T, 3>::height() const
{
	return size_t();
}

template<typename T>
size_t Array<T, 3>::depth() const
{
	return size_t();
}
