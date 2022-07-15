//Iterator.cpp
#include"DNode.h"

//private constructor
template<typename T>
Iterator<T>::Iterator(DNode<T>* u){
    v = u;    
}

template<typename T>
T& Iterator<T>::operator*() {
    return v->elem;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& u) const {
    return (v == u.v);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& u) const {
    return (v != u.v);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++() {
    v = v->next;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--() {
    v = v->prev;
    return *this;
}