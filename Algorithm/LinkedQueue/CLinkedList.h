#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H
#include <iostream>
#include "CNode.h"
template <typename T>
class CLinkedList{
    public:
        CLinkedList();
        ~CLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        CLinkedList<T>& advance();
        CLinkedList<T>& add(const T& e);
        CLinkedList<T>& remove();
        std::string toString() const;
    private:
        CNode<T> *cursor;
};

#include "CLinkedList.cpp"

#endif