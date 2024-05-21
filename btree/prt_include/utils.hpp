#pragma once

#include <assert.h>
#include <vector>
#include <cstdint>

template<typename T>
T read(std::vector<uint8_t> const& byteSequence, size_t position = 0) {
    assert(byteSequence.size() - position >= sizeof(T));
    const uint8_t* bytePtr = &byteSequence[position];
    T value = *reinterpret_cast<const T*>(bytePtr);
    return value;
}

template<typename T>
void write(std::vector<uint8_t>& byteSequence, size_t position, T value) {
    assert(byteSequence.size() - position >= sizeof(T));
    uint8_t* bytePtr = &byteSequence[position];
    *reinterpret_cast<T*>(bytePtr) = value;
}
