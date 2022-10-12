#ifndef CUSTOM_MEMORY_ALLOCATOR_LINKED_LIST_H
#define CUSTOM_MEMORY_ALLOCATOR_LINKED_LIST_H

#include <memory>
#include "node.h"
#include "list_iterator.h"
template <class T, class A = std::allocator<T> >
class linked_list {
public:

    using node_alloc_t = typename std::allocator_traits<A>::template rebind_alloc<node<T>>;
    using allocator_type = node_alloc_t;
    using value_type = typename node_alloc_t ::value_type ;
    using reference =  typename node_alloc_t ::reference ;
    using const_reference = typename node_alloc_t ::const_reference ;
    using difference_type = typename node_alloc_t ::difference_type ;
    using size_type = typename node_alloc_t ::size_type ;

    using iterator = list_iterator<T>;
    using const_iterator = list_iterator<const T>;

    linked_list();
    linked_list(const linked_list&);
    ~linked_list();
    allocator_type alloc;


    iterator begin();
    iterator end();


    reference front(); //optional
    const_reference front() const; //optional
    reference back(); //optional
    const_reference back() const; //optional

    void insert(iterator, const T&);
    void insert(const_iterator, const T&); //optional

    void erase(iterator);
    void erase(const_iterator); //optional

    void push_front(T&);
    void push_front(const T&); //optional
    void push_back(T&);
    void push_back(const T&); //optional
    void pop_front(); //optional
    void pop_back(); //optional


    [[nodiscard]]bool empty() const;
    void clear(); //optional
    size_type size() const;



private:
    node<T>* m_nHead;
    node<T>* m_nTail;
};


#include "../src/linked_list.tpp"
#endif //CUSTOM_MEMORY_ALLOCATOR_LINKED_LIST_H
