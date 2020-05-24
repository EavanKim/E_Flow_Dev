#ifndef FLATBUFFER_HPP__
#define FLATBUFFER_HPP__

typedef uint32_t uoffset_t;
typedef int32_t soffset_t;
typedef uint16_t voffset_t;
typedef uintmax_t largest_scalar_t;

#define FLATBUFFERS_MAX_BUFFER_SIZE ((1ULL << (sizeof(soffset_t) * 8 - 1)) - 1)
#define FLATBUFFERS_MAX_ALIGNMENT 16

template<typename T> T EndianScalar(T _type);
template<typename T> T ReadScalar(const void* _point);
template<typename T> void WriteScalar(void* _point, T _type);
size_t PaddingBytes(size_t _buf_size, size_t _scalar_size);

template<typename T> struct Offset
{
	uoffset_t offset;
	Offset() : offset(0) {}
	Offset(uoffset_t _offset) : offset(_offset) {}
	Offset<void> Union() const { return Offset<void>(offset); }
	bool IsNull() const { return !offset; }
};

void EndianCheck();
template<typename T> T EndianSwap(T _type);


class UTIL_EXPORTS FlatBufferBuilder
{

};

#endif // !FLATBUFFER_HPP__
