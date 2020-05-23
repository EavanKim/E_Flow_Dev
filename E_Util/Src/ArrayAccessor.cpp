#include <utilpch.hpp>

template<typename T>
inline ArrayAccessor<T, 3>::ArrayAccessor()
{
}

template<typename T>
inline ArrayAccessor<T, 3>::ArrayAccessor(const Size3& size, T* const data)
{
}

template<typename T>
inline T& ArrayAccessor<T, 3>::operator()(size_t _x, size_t _y, size_t _z)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
inline const T& ArrayAccessor<T, 3>::operator()(size_t _x, size_t _y, size_t _z) const
{
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
inline Size3 ArrayAccessor<T, 3>::size() const
{
	return Size3();
}

template<typename T>
inline size_t ArrayAccessor<T, 3>::width() const
{
	return size_t();
}

template<typename T>
inline size_t ArrayAccessor<T, 3>::height() const
{
	return size_t();
}

template<typename T>
inline size_t ArrayAccessor<T, 3>::depth() const
{
	return size_t();
}



template<typename T>
inline ConstArrayAccessor<T, 3>::ConstArrayAccessor()
{
}

template<typename T>
inline ConstArrayAccessor<T, 3>::ConstArrayAccessor(const Size3& size, const T* const data)
{
}

template<typename T>
inline const T& ConstArrayAccessor<T, 3>::operator()(size_t i, size_t j, size_t k) const
{
	// TODO: 여기에 return 문을 삽입합니다.
}

template<typename T>
inline Size3 ConstArrayAccessor<T, 3>::size() const
{
	return Size3();
}

template<typename T>
inline size_t ConstArrayAccessor<T, 3>::width() const
{
	return size_t();
}

template<typename T>
inline size_t ConstArrayAccessor<T, 3>::height() const
{
	return size_t();
}

template<typename T>
inline size_t ConstArrayAccessor<T, 3>::depth() const
{
	return size_t();
}

