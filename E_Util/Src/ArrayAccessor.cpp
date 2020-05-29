#include <utilpch.hpp>

namespace util
{

	template<typename T>
	inline ArrayAccessor<T, 3>::ArrayAccessor()
	{

	}

	template<typename T>
	inline ArrayAccessor<T, 3>::ArrayAccessor(const Size3& size, T* const data)
	{
		_size = size;

		_data = data;
	}

	template<typename T>
	inline T& ArrayAccessor<T, 3>::operator()(size_t _x, size_t _y, size_t _z)
	{
		_size.x = _x;
		_size.y = _y;
		_size.z = _z;
	}

	template<typename T>
	inline const T& ArrayAccessor<T, 3>::operator()(size_t _x, size_t _y, size_t _z) const
	{
		_size.x = _x;
		_size.y = _y;
		_size.z = _z;
	}

	template<typename T>
	inline Size3 ArrayAccessor<T, 3>::size() const
	{
		return _size;
	}

	template<typename T>
	inline size_t ArrayAccessor<T, 3>::width() const
	{
		return _size.x;
	}

	template<typename T>
	inline size_t ArrayAccessor<T, 3>::height() const
	{
		return _size.y;
	}

	template<typename T>
	inline size_t ArrayAccessor<T, 3>::depth() const
	{
		return _size.z;
	}



	template<typename T>
	inline ConstArrayAccessor<T, 3>::ConstArrayAccessor()
	{

	}

	template<typename T>
	inline ConstArrayAccessor<T, 3>::ConstArrayAccessor(const Size3& size, const T* const data)
	{
		_size = size;
		_data = data;
	}

	template<typename T>
	inline const T& ConstArrayAccessor<T, 3>::operator()(size_t _x, size_t _y, size_t _z) const
	{
		// TODO: 여기에 return 문을 삽입합니다.

		_size.x = _x;
		_size.y = _y;
		_size.z = _z;
	}

	template<typename T>
	inline Size3 ConstArrayAccessor<T, 3>::size() const
	{
		return _size;
	}

	template<typename T>
	inline size_t ConstArrayAccessor<T, 3>::width() const
	{
		return _size.x;
	}

	template<typename T>
	inline size_t ConstArrayAccessor<T, 3>::height() const
	{
		return _size.y;
	}

	template<typename T>
	inline size_t ConstArrayAccessor<T, 3>::depth() const
	{
		return _size.z;
	}
}

