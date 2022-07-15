//LinkedDeque.h
#ifndef LINKED_DEQUE_H
#define LINKED_DEQUE_H

#include"DLinkedList.h"

template<typename T>
class LinkedDeque {
    public:
        LinkedDeque();                      //constructor
        int size() const;                   //number of elements in deque
        bool empty() const;                 //is deque empty?

        const T& front();                   //first element
        const T& back();                    //last element

        void insertFront(const T& e);       //insert new first element
        void insertBack(const T& e);        //insert new last element
        void removeFront();                 //remove first element
        void removeBack();                  //remove last element


    private:
        DLinkedList<T> D;                   //deque implemented with a doubly linked list
        int n;                              //number of elements in deque
};

#include"LinkedDeque.cpp"

#endif