#ifndef SERIALIZABLE_HPP__
#define SERIALIZABLE_HPP__

class UTIL_EXPORTS Serializable
{
public:
	Serializable() = default;

	virtual ~Serializable() = default;

	virtual void serialize(std::vector<uint8_t>* _buffer) const = 0;

	virtual void deserialize(const std::vector<uint8_t>& _buffer) = 0;
};

void serialize(const Serializable* _serializable, std::vector<uint8_t>* _buffer);

void serialize(const uint8_t* _data, size_t _size, std::vector<uint8_t>* _buffer);

void deserialize(const std::vector<uint8_t>& buffer, Serializable* _serializable);

void deserialize(const std::vector<uint8_t>& _buffer, std::vector<uint8_t>* _data);

#endif // !SERIALIZABLE_HPP__
