//DLinkedList.h
#include"DNode.h"
#include<string>
#ifndef DLINKED_H
#define DLINKED_H

template<typename T>
class DLinkedList {
    public:
        DLinkedList();                              //empty constructor

        ~DLinkedList();                             //destructor
        DLinkedList(const DLinkedList&);            //copy constructor
        DLinkedList& operator=(const DLinkedList&); //overloading assignment operator

        int size() const;                           //size of list
        bool empty() const;                         //is list empty?
        void addFront(const T&);                    //add in front of the list
        void addBack(const T&);                     //add in back of the list
        void removeFront();                         //remove element in front of the list
        void removeBack();                          //remove element back in the list
        const T& front() const;                     //returns element in front of the list
        const T& back() const;                      //returns element back in the list

        void addInOrder(const T&);                  //insert an element in order

        std::string toString() const;               //shows all elements in the list
        const T& operator[] (int) const;            //returns element in position specified

    private:
        DNode<T>* header;
        DNode<T>* trailer;
    
    protected:
        void add(DNode<T>*, const T&);              //insert an element before node specified
        void remove(DNode<T>*);                     //remove element before node specified
};

#include"DLinkedList.cpp"

#endif