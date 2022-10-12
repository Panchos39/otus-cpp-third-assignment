#include "../include/node.h"

template<class T>
node<T>::node() {
    this->m_nNext = nullptr;
    this->m_nPrev = nullptr;
}

template<class T>
node<T>::node(T data) {
    this->m_tData = data;
    this->m_nNext = nullptr;
    this->m_nPrev = nullptr;
}

//-------------------------------------------------------------------
template<class T>
typename node<T>::pointer node<T>::get_next(){
    return this->m_nNext;
}

template<class T>
typename node<T>::pointer node<T>::get_prev(){
    return this->m_nPrev;
}

template<class T>
typename node<T>::value_type node<T>::get_data(){
    return this->m_tData;
}
//-----------------------------------------------------------------------------
template<class T>
void node<T>::set_next(typename node<T>::pointer p) {
    this->m_nNext = p;
}

template<class T>
void node<T>::set_prev(typename node<T>::pointer p) {
    this->m_nPrev = p;
}

template<class T>
void node<T>::set_data(typename node<T>::value_type data) {
    this->m_tData = data;
}



//----------------------------------------------------------------------------
template<class T>
bool node<T>::operator==(const node& b) const {
    return this->m_tData == b->m_tData;
}
template<class T>
bool node<T>::operator!=(const node& b) const {
    return this->m_tData != b.m_tData;
}
template<class T>
bool node<T>::operator>(const node& b) const {
    return this->m_tData > b.m_tData;
}
template<class T>
bool node<T>::operator>=(const node& b) const {
    return this->m_tData >= b.m_tData;
}
template<class T>
bool node<T>::operator<(const node& b) const {
    return this->m_tData < b.m_tData;
}
template<class T>
bool node<T>::operator<=(const node& b) const {
    return this->m_tData <= b.m_tData;
}
