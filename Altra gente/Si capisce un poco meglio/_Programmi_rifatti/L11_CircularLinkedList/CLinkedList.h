//CLinkedList.h
#include"CNode.h"
#include<string>
#ifndef CLINKED_H
#define CLINKED_H

template<typename T>
class CLinkedList {
    public:
        CLinkedList();                                          //empty constructor
        ~CLinkedList();                                         //destructor
        CLinkedList(const CLinkedList&);                        //copy constructor
        CLinkedList& operator=(const CLinkedList&);             //overloading =

        bool empty() const;                                     //is list empty?
        int size() const;                                       //size of list
        const T& front() const;                                 //front of the list (element at cursor)
        const T& back() const;                                  //back of the list (element after cursor)
        void advance();                                         //advance cusor
        void add(const T&);                                     //add after cursor
        void remove();                                          //remove after cursor
        
        const T& operator[](int) const;

        std::string toString() const;

    private:
        CNode<T>* cursor;
};

#include"CLinkedList.cpp"

#endif
