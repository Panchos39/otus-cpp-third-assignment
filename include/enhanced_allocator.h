#ifndef CUSTOM_MEMORY_ALLOCATOR_ENHANCED_ALLOCATOR_H
#define CUSTOM_MEMORY_ALLOCATOR_ENHANCED_ALLOCATOR_H

#include <iostream>
#include <memory>
template <typename T, std::size_t BlockSize>
struct enhanced_allocator {


    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    template<typename U>
    struct rebind {
        using other = enhanced_allocator<U, BlockSize>;
    };

    std::unique_ptr<unsigned char []> mData;
    size_type mOffset;
    size_type mSize;

    enhanced_allocator();
    ~enhanced_allocator();

    template<typename U>
    explicit enhanced_allocator(const enhanced_allocator<U, BlockSize>&);
    enhanced_allocator(const enhanced_allocator<T, BlockSize>&);

    [[maybe_unused]] pointer allocate(std::size_t n);

    void deallocate(pointer p, std::size_t n);

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args);

    void destroy(pointer p);
};

#include "../src/enhanced_allocator.tpp"


#endif //CUSTOM_MEMORY_ALLOCATOR_ENHANCED_ALLOCATOR_H
