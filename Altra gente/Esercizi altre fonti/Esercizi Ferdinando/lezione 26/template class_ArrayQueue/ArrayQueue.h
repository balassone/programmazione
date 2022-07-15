#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
#include <exception>

template <typename T>
class ArrayQueue{

public:
    ArrayQueue(int = 10);
    bool empty() const;
    int size() const;
    const T& front () const;
    void enqueue(const T&);
    void dequeue();

private:
    T* array;
    int capacity;
    int head;
    int tail;
    int n;
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int cap)
    : array{new T[cap]}, capacity{cap}, head{0}, tail{0}, n{0} {}

template <typename T>
bool ArrayQueue<T>::empty() const{
    return n==0;
}

template <typename T>
int ArrayQueue<T>::size() const {
    return n;
}

template <typename T>
const T& ArrayQueue<T>::front() const{
    if(empty()) throw std::runtime_error("La coda è vuota");
    return array[head];
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& ele){
    if(head==(tail+1)%capacity) throw std::runtime_error("La coda è piena");
    array[tail]=ele;
    tail=(tail+1)%capacity;
    n++;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if(empty()) throw std::runtime_error("La coda è vuota");
    head=(head+1)%capacity;
    n--;
}







#endif