//DLinkedList.h

/****   header--front-------------------back--trailer     ****/

#ifndef DLINKED_H
#define DLINKED_H

#include"DNode.h"
#include<string>

template<typename T>
class DLinkedList {
    public :
        DLinkedList();                          //constructor
        ~DLinkedList();                         //destructor

        bool empty() const;                     //is list empty?
        const T& front() const;                 //get front element
        const T& back() const;                  //get bak element

        void addFront(const T& e);              //add element to the front of the list
        void addBack(const T& e);               //add element to the back of the list
        void removeFront();                     //remove element from the front of the list
        void removeBack();                      //remove element from the back of the list

        std::string toString();                 //print list

    private:
        DNode<T>* header;
        DNode<T>* trailer;
    
    protected:
        void add(DNode<T>* v, const T& e);      //insert new node, containing element e, before v
        void remove(DNode<T>* v);               //remove node v
};

#include"DLinkedList.cpp"

#endif