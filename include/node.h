#ifndef CUSTOM_MEMORY_ALLOCATOR_NODE_H
#define CUSTOM_MEMORY_ALLOCATOR_NODE_H

#include <memory>

template <class T>
class node {
public:
    using value_type = T;
    using pointer = node<T>*;

    node();
    explicit node(value_type data);
    ~node()=default;
    pointer get_prev();
    pointer get_next();
    value_type get_data();

    void set_prev(pointer);
    void set_next(pointer);
    void set_data(value_type);

    bool operator==(const node& b) const;
    bool operator!=(const node& b) const;

    bool operator>(const node& b) const;
    bool operator>=(const node& b) const;
    bool operator<(const node& b) const;
    bool operator<=(const node& b) const;

protected:
    value_type m_tData;
    pointer m_nNext;
    pointer m_nPrev;
};

#include "../src/node.tpp"

#endif //CUSTOM_MEMORY_ALLOCATOR_NODE_H
