#ifndef ARRAYACCESSOR_HPP__
#define ARRAYACCESSOR_HPP__

template<typename T, size_t N>
class UTIL_EXPORTS ArrayAccessor final {};

template <typename T>
class UTIL_EXPORTS ArrayAccessor<T, 3> final
{
public:
	ArrayAccessor();

	explicit ArrayAccessor(const Size3& size, T* const data);

	T& operator() (size_t _x, size_t _y, size_t _z);
	const T& operator() (size_t _x, size_t _y, size_t _z) const;

	Size3 size() const;
	size_t width() const;
	size_t height() const;
	size_t depth() const;

private:
	Size3 _size;
	T* _data;
};

template <typename T> using ArrayAccessor3 = ArrayAccessor<T, 3>;

template<typename T, size_t N>
class UTIL_EXPORTS ConstArrayAccessor final {};

template <typename T>
class UTIL_EXPORTS ConstArrayAccessor<T, 3>
{
public:
	ConstArrayAccessor();
	explicit ConstArrayAccessor(const Size3& size, const T* const data);
	const T& operator () (size_t i, size_t j, size_t k) const;
	
	Size3 size() const;
	size_t width() const;
	size_t height() const;
	size_t depth() const;

private: 
	Size3 _size;
	const T _data;
};
template <typename T>using ConstArrayAccessors = ConstArrayAccessor<T, 3>;

#endif