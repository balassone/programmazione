#ifndef NODE_H
#define NODE_H

template<typename T> class CLinkedList;

template<typename T>
class Node{

private:
    T element;
    Node<T>* next;

    friend class CLinkedList<T>;
};

#endif