#include "../include/linked_list.h"
#include "../include/list_iterator.h"
#include "../include/node.h"
#include <memory>

template<class T, class A>
linked_list<T, A>::linked_list() {
    this->m_nHead = nullptr;
    this->m_nTail = nullptr;
}

template<class T, class A>
linked_list<T, A>::linked_list(const linked_list& other) {
    this->m_nHead = other->m_nHead;
    this->m_nTail = other->m_nTail;
}

template<class T, class A>
linked_list<T, A>::~linked_list() {
    this->clear();
}


//---------------------------------------------------------------------
template<class T, class A>
typename linked_list<T, A>::iterator linked_list<T, A>::begin() {
    return typename linked_list<T, A>::iterator(this->m_nHead);
}

template<class T, class A>
typename linked_list<T, A>::iterator linked_list<T, A>::end() {
    return typename linked_list<T, A>::iterator();
}

//------------------------------------------------------------------------
template<class T, class A>
typename linked_list<T, A>::reference linked_list<T, A>::front() {
    return this->m_nHead;
}

template<class T, class A>
typename linked_list<T, A>::const_reference linked_list<T, A>::front() const {
    return this->m_nHead;
}
template<class T, class A>
typename linked_list<T, A>::reference linked_list<T, A>::back() {
    return this->m_nTail;
}

template<class T, class A>
typename linked_list<T, A>::const_reference linked_list<T, A>::back() const{
    return this->m_nTail;
}

//-------------------------------------------------------------------------
template<class T, class A>
void linked_list<T, A>::insert(typename linked_list<T, A>::iterator pos, const T& data) {
    //auto some_node = new node<T>(data);
    auto some_node = this->alloc.allocate(1);
    this->alloc.construct(some_node, data);
    if (pos == this->begin()) {
        some_node->set_next(this->m_nHead);
        this->m_nHead = some_node;
    } else if (pos == this->end()) {
        some_node->set_prev(this->m_nTail);
        this->m_nTail->set_next(some_node);
        this->m_nTail = some_node;
    } else {
        some_node->set_next(pos.m_Ptr->get_next());
        some_node->set_prev(pos.m_Ptr);
        pos.m_Ptr->get_next()->set_prev(some_node);
        pos.m_Ptr->set_next(some_node);
    }
}

template<class T, class A>
void linked_list<T, A>::insert(typename linked_list<T, A>::const_iterator pos, const T& data) {
    //auto some_node = new node<T>(data);
    auto some_node = this->alloc.allocate(1);
    this->alloc.construct(some_node, data);
    if (pos == this->begin()) {
        some_node->set_next(this->m_nHead);
        this->m_nHead = some_node;
    } else if (pos == this->end()) {
        some_node->set_prev(this->m_nTail);
        this->m_nTail->set_next(some_node);
        this->m_nTail = some_node;
    } else {
        some_node->set_next(pos.m_Ptr->get_next());
        some_node->set_prev(pos.m_Ptr);
        pos.m_Ptr->get_next()->set_prev(some_node);
        pos.m_Ptr->set_next(some_node);
    }
}

template <class T, class A>
void linked_list<T, A>::erase(typename linked_list<T, A>::iterator pos) {
    if (pos == this->begin()) {
        this->pop_front();
    } else if (pos == this->end()) {
        this->pop_back();
    } else {
        pos.m_Ptr->get_prev()->set_next(pos.m_Ptr->get_next());
        pos.m_Ptr->get_next()->set_prev(pos.m_Ptr->get_prev());
        this->alloc.deallocate(pos.m_Ptr, 1);
        this->alloc.destroy(pos.m_Ptr);
    }

}

template <class T, class A>
void linked_list<T, A>::erase(typename linked_list<T, A>::const_iterator pos) {
    if (pos == this->begin()) {
        this->pop_front();
    } else if (pos == this->end()) {
        this->pop_back();
    } else {
        pos.m_Ptr->get_prev()->set_next(pos.m_Ptr->get_next());
        pos.m_Ptr->get_next()->set_prev(pos.m_Ptr->get_prev());
        this->alloc.deallocate(pos.m_Ptr, 1);
        this->alloc.destroy(pos.m_Ptr);
    }

}

//---------------------------------------------------------------------------------------

template <class T, class A>
void linked_list<T, A>::push_front(T& data) {
    this->insert(this->begin(), data);
}

template <class T, class A>
void linked_list<T, A>::push_front(const T& data) {
    this->insert(this->begin(), data);
}


template <class T, class A>
void linked_list<T, A>::pop_front() {
    if (this->m_nHead->get_next()) {
        //auto data = this->m_nHead->get_data();
        auto old_head = this->m_nHead;
        this->m_nHead = this->m_nHead->get_next();
        this->m_nHead->set_prev(nullptr);

        //old_head->set_next(nullptr);
        this->alloc.deallocate(old_head, 1);
        this->alloc.destroy(old_head);

    }
}

template <class T, class A>
void linked_list<T, A>::push_back(T& data) {
    if (!this->m_nHead || !this->m_nTail) {
        auto some_node = this->alloc.allocate(1);
        this->alloc.construct(some_node, data);
        this->m_nHead = some_node;
        this->m_nTail = some_node;
    } else {
        this->insert(this->end(), data);
    }
}

template <class T, class A>
void linked_list<T, A>::push_back(const T& data) {

    if (!this->m_nHead || !this->m_nTail) {
        auto some_node = this->alloc.allocate(1);
        this->alloc.construct(some_node, data);
        this->m_nHead = some_node;
        this->m_nTail = some_node;
    } else {
        this->insert(this->end(), data);
    }
}
template <class T, class A>
void linked_list<T, A>::pop_back() {
    if (this->m_nTail->get_prev()) {
        // Create pointer to current tail to delete later
        auto some_node = this->m_nTail;
        // Tail needs to now point to the previous node
        this->m_nTail = this->m_nTail->get_prev();
        // And it should not point to any "next" node
        this->m_nTail->set_next(nullptr);
        // Delete old tail
        this->alloc.deallocate(some_node, 1);
        this->alloc.destroy(some_node);

    }
    else {
        this->m_nHead = nullptr;
        this->m_nTail = nullptr;
    }
}

//------------------------------------------------------------------------------------------
template <class T, class A>
bool linked_list<T, A>::empty() const {
    return !this->m_nHead;
}

template <class T, class A>
void linked_list<T, A>::clear() {
    while (!this->empty())
        this->pop_back();
}

template <class T, class A>
typename linked_list<T, A>::size_type linked_list<T, A>::size() const {
    int size = 0;
    while (this->m_nHead) {
        ++size;
        this->m_nHead = this->m_nHead->get_next();
    }
    return size;
}













