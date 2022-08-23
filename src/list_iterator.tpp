#include "../include/list_iterator.h"

template<class T>
list_iterator<T>::list_iterator(list_iterator<T>::pointer p) {
    this->m_Ptr = p;
}

template<class T>
T list_iterator<T>::operator*() const {
    return this->m_Ptr->get_data();
}

template<class T>
T* list_iterator<T>::operator->() const {
    return &(this->m_Ptr->get_data());
}

template<class T>
typename list_iterator<T>::iterator& list_iterator<T>::operator=(typename list_iterator<T>::iterator* p){
    this->m_ptr = p;
    return (*this);
}
template<class T>
bool list_iterator<T>::operator==(const typename list_iterator<T>::iterator& rawIterator) const{
        return (this->m_Ptr == rawIterator.m_Ptr);
}

template<class T>
bool list_iterator<T>::operator!=(const typename list_iterator<T>::iterator& rawIterator)const{
    return (this->m_Ptr != rawIterator.m_Ptr);
}

template<class T>
typename list_iterator<T>::iterator& list_iterator<T>::operator++(){
    this->m_Ptr = m_Ptr->get_next();
    return (*this);
}
template<class T>
typename list_iterator<T>::iterator list_iterator<T>::operator++(int) {
    list_iterator<T> tmp(*this);
    ++(*this);
    return tmp;
}

template<class T>
typename list_iterator<T>::iterator& list_iterator<T>::operator--(){
    this->m_Ptr = m_Ptr->get_prev();
    return (*this);
}
template<class T>
typename list_iterator<T>::iterator list_iterator<T>::operator--(int) {
    list_iterator<T> tmp(*this);
    --(*this);
    return tmp;
}


