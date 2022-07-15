//CircularLinkedList
#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include<iostream>
#include"CNode.h"

template<typename T>
class CircleList {
    public:
        CircleList();                       //constructor
        ~CircleList();                      //destructor

        bool empty() const;                 //is list empty?
        const T& front() const;             //element at cursor
        const T& back() const;              //element following cursor
        void advance();                     //advance cursor
        void add(const T& e);               //add element after cursor
        void remove();                      //remove the node after cursor
        std::string toString();
    private:
        CNode<T>* cursor;
};

#include"CircleLinkedList.cpp"


#endif
