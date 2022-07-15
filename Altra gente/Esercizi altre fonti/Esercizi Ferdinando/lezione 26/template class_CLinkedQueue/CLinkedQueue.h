#ifndef CLINKEDQUEUE_H
#define CLINKEDQUEUE_H

#include "CLinkedList.h"
#include <iostream>
#include <exception>

template <typename T>
class CLinkedQueue{

public:
    CLinkedQueue();
    bool empty() const;
    int size() const;
    const T& front() const;
    void enqueue(const T&);
    void dequeue();

private:
    CLinkedList<T> C;
    int n;
};

template <typename T>
CLinkedQueue<T>::CLinkedQueue()
    : C(), n{0} {}

template <typename T>
bool CLinkedQueue<T>::empty() const{
    return n==0;
}

template <typename T>
int CLinkedQueue<T>::size() const{
    return n;
}

template <typename T>
const T& CLinkedQueue<T>::front() const{
    if(empty()) throw std::runtime_error("La coda è vuota");
    return C.front();
}

template <typename T>
void CLinkedQueue<T>::enqueue(const T& ele){
    C.add(ele);
    C.advance();
    n++;
}

template <typename T>
void CLinkedQueue<T>::dequeue(){
    if(empty()) throw std::runtime_error("La lista è vuota");
    C.remove();
    n--;
}












#endif