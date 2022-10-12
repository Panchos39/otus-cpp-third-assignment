#include "../include/enhanced_allocator.h"
#include <cstdlib>

template<typename T, std::size_t BlockSize>
enhanced_allocator<T, BlockSize>::enhanced_allocator(){
    mOffset = 0;
    mSize = BlockSize;
    mData = std::make_unique<unsigned char[]>(sizeof(value_type) * mSize);
}

template<typename T, std::size_t BlockSize>
enhanced_allocator<T, BlockSize>::~enhanced_allocator()=default;


template<typename T, std::size_t BlockSize>
template<typename U>
enhanced_allocator<T, BlockSize>::enhanced_allocator(const enhanced_allocator<U, BlockSize>& ){}

template<typename T, std::size_t BlockSize>
enhanced_allocator<T, BlockSize>::enhanced_allocator(const enhanced_allocator<T, BlockSize>& other){
    this->mOffset = other.mOffset;
    this->mData = other.mData;
    this->mSize = other.mSize;
}

template<typename T, std::size_t BlockSize>
typename enhanced_allocator<T, BlockSize>::pointer
enhanced_allocator<T, BlockSize>::allocate(std::size_t n) {

    if (mData == nullptr) {
        mData = std::move(std::make_unique<unsigned char[]>(sizeof(value_type) * this->mSize));
    }
    if ((mOffset + sizeof(value_type) * n) > (mSize * sizeof(value_type))) {
        throw std::bad_alloc();

    }

    void* result = mData.get() + mOffset;
    mOffset += sizeof(value_type) * n;

    return static_cast<pointer>(result);
}

template<typename T, std::size_t BlockSize>
void enhanced_allocator<T, BlockSize>::deallocate( [[maybe_unused]] pointer p, [[maybe_unused]] std::size_t n) {}

template<typename T, std::size_t BlockSize>
template<typename U, typename ...Args>
void enhanced_allocator<T, BlockSize>::construct(U *p, Args &&...args) {
    new(p) U(std::forward<Args>(args)...);
}

template<typename T, std::size_t BlockSize>
void enhanced_allocator<T, BlockSize>::destroy(pointer p) {
    p->~T();
}