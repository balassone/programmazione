//Queue.h
//Queue implemented using a circular linked list
#include"CLinkedList.h"

#ifndef QUEUE_H
#define QUEUE_H

template<typename E>
class Queue {
    public:
        Queue();                                        //constructor
        int size() const;                               //number of elements in queue
        bool empty() const;                             //is queue empty?
        E front() const;                         //front element
        void enqueue(const E&);                         //enqueue element at rear
        void dequeue();                                 //dequeue element at front

        const E& operator[](int i) const;

    private:
        CLinkedList<E> C;
        int n;
};

#include"Queue.cpp"

#endif