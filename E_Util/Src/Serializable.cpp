#include "utilpch.hpp"

void serialize(const Serializable* _serializable, std::vector<uint8_t>* _buffer)
{
	_serializable->serialize(_buffer);
}

void serialize(const uint8_t* _data, size_t _size, std::vector<uint8_t>* _buffer)
{
	
}

void deserialize(const std::vector<uint8_t>& buffer, Serializable* _serializable)
{

}

void deserialize(const std::vector<uint8_t>& _buffer, std::vector<uint8_t>* _data)
{

}
