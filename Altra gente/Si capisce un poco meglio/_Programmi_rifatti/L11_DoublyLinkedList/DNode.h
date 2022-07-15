//DNode.h
//Node for doubly linked list

#ifndef DNODE_H
#define DNODE_H

template<typename T> class DLinkedList;

template<typename T>
class DNode {
    private:
        T elem;
        DNode<T>* next;
        DNode<T>* prev;
        friend class DLinkedList<T>;
};
#endif