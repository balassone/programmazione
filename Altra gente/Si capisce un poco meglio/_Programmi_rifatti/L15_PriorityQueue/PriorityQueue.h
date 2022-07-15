#include"Heap.h"
#ifndef PQUEUE_H
#define PQUEUE_H

template<typename T>
class PriorityQueue {
    public:
        PriorityQueue();
        PriorityQueue(Heap<T>);                                 //constructor
        int size() const;                                       //size
        bool empty() const;                                     //is priority queue empty?

        T top() const;                                   //top element (max)
        void push(const T&);                                    //push
        void pop();                                             //pop (element with key max)

    private:
        Heap<T> h;
};

#include"PriorityQueue.cpp"

#endif