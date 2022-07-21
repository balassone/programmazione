#include "DNode.h"
#include <iostream>
template <typename T>
class DLinkedList{
    public:
        DLinkedList();
        ~DLinkedList();
        bool empty() const;
        const T& front() const;
        const T& back() const;
        int size() const;
        DLinkedList<T>& addFront(const T&);
        DLinkedList<T>& addBack(const T&);
        DLinkedList<T>& removeFront();
        DLinkedList<T>& removeBack();
        std::string toString() const;
        DLinkedList<T>& addOrder(const T&);
        DLinkedList<T>& bubbleSort();
        DLinkedList<T>& swap(int, int);
        DLinkedList<T>& swapOddEven();
    private:
        DNode<T> *header;
        DNode<T> *trailer;
    protected:
        DLinkedList<T>& add(DNode<T>* v, const T& e);
        DLinkedList<T>& remove(DNode<T>* v);
};

#include "DLinkedList.cpp"