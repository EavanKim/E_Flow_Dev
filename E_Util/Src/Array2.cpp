#include <utilpch.hpp>

template<typename T>
inline T& Array<T, 2>::operator()(size_t _XIndex, size_t _YIndex)
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return _data[_XIndex + _size.x * _YIndex];
}

template<typename T>
inline const T& Array<T, 2>::operator()(size_t _XIndex, size_t _YIndex) const
{
	// TODO: ���⿡ return ���� �����մϴ�.

	return _data[_XIndex + _size.x * _YIndex];
}

template<typename T>
inline size_t Array<T, 2>::width() const
{
	return size_t();
}

template<typename T>
inline size_t Array<T, 2>::height() const
{
	return size_t();
}
