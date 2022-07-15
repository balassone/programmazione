#ifndef DLINKEDDEQUE_H
#define DLINKEDDEQUE_H

#include "DLinkedList.h"
#include <iostream>
#include <exception>

template <typename T>
class DLinkedDeque{

public:
    DLinkedDeque();
    int size() const;
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void enqueueFront(const T&);
    void enqueueBack(const T&);
    void dequeueFront();
    void dequeueBack();

private:
    DLinkedList<T> C;
    int n;
};


template <typename T>
DLinkedDeque<T>::DLinkedDeque()
    : C(), n{0} {}

template <typename T>
int DLinkedDeque<T>::size() const{
    return n;
}

template <typename T>
bool DLinkedDeque<T>::empty() const{
    return n==0;
}

template <typename T>
const T& DLinkedDeque<T>::front() const{
    return C.front();
}

template <typename T>
const T& DLinkedDeque<T>::back() const{
    return C.back();
}

template <typename T>
void DLinkedDeque<T>::enqueueFront(const T& ele){
    C.addFront(ele);
    n++;
}

template <typename T>
void DLinkedDeque<T>::enqueueBack(const T& ele){
    C.addBack(ele);
    n++;
}

template <typename T>
void DLinkedDeque<T>::dequeueFront() {
    if(empty()) throw std::runtime_error("La coda è vuota");
    C.removeFront();
    n--;
}

template <typename T>
void DLinkedDeque<T>::dequeueBack() {
    if(empty()) throw std::runtime_error("La coda è vuota");
    C.removeBack();
    n--;
}





#endif