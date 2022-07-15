//Deque.h
//Deque implemented with doubly linked list

#include"DLinkedList.h"

#ifndef DEQUE_H
#define DEQUE_H

template<typename E>
class Deque {
    public:
        Deque();                                    //constructor
        int size() const;                           //size of deque
        bool empty() const;                         //is deque empty?
        const E& front();                           //element at beginning of deque
        const E& back();                            //element at end of deque
        void insertFront(const E&);                 //add element at beginning of the deque
        void insertBack(const E&);                  //add element at end of deque
        void eraseFront();                         //remove first element of deque
        void eraseBack();                          //remove last element of deque

    private:
        DLinkedList<E> D;
        int n;
};

#include"Deque.cpp"
#endif