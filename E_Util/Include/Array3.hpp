#ifndef ARRAY3_HPP__
#define ARRAY3_HPP__

template<typename T>
class UTIL_EXPORTS Array<T, 3> final
{
public:
	Array();

	T& operator() (size_t _XIndex, size_t _YIndex, size_t _ZIndex);
	const T& operator() (size_t _XIndex, size_t _YIndex, size_t _ZIndex) const;

	void forEachIndex(const std::function<void(size_t, size_t, size_t)>& func) const;
	void ParallelforEachIndex(const std::function<void(size_t, size_t, size_t)>& func) const;

	Size3 size() const;
	size_t width() const;
	size_t height() const;
	size_t depth() const;

private:
	Size3 _size;
	std::vector<T> _data;
};

template <typename T> using Array3 = Array<T, 3>;

#endif