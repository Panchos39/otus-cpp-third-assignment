#ifndef CUSTOM_MEMORY_ALLOCATOR_LIST_ITERATOR_H
#define CUSTOM_MEMORY_ALLOCATOR_LIST_ITERATOR_H

#include <memory>
#include "node.h"

template <class T>
class list_iterator {
public:


    using iterator = list_iterator<T>;
    using const_iterator = const list_iterator<T>;
    using pointer = node<T>*;

    explicit list_iterator(pointer p = nullptr);
    ~list_iterator()=default;

    T operator*() const;
    T* operator->() const;

    iterator& operator=(iterator*);
    bool operator==(const iterator&) const;
    bool operator!=(const iterator&) const;


    iterator& operator++();
    iterator operator++(int);
    iterator& operator--();
    iterator operator--(int);


    pointer m_Ptr;
};

#include "../src/list_iterator.tpp"
#endif //CUSTOM_MEMORY_ALLOCATOR_LIST_ITERATOR_H
