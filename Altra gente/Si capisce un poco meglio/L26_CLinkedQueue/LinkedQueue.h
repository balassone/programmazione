//LinkedQueue.h

/******     front--------------------------rear    *****/

#include"CircleLinkedList.h"
#include<stdexcept>
#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename E>
class LinkedQueue {
    public:
        LinkedQueue();                      //constructor
        int size() const;                   //returns number of items in the queue
        bool empty() const;                 //is queue empty?
        const E& front();                   //returns front element of queue
        void enqueue(const E& e);           //enqueue element at rear
        void dequeue();                     //dequeue element at front


    private:
        CircleList<E> C;                    //circular list of elements
        int n;                              //number of elements in the queue
};

#include"LinkedQueue.cpp"

#endif

