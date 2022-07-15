//DNode.h

#ifndef DNODE_H
#define DNODE_H

template<typename T> class DLinkedList;         //forward declaration

template<typename T>
class DNode{                                    //Doubly linked list node
    private:
    T elem;                                     //node element value
    DNode* next;                                //pointer to next node
    DNode* prev;                                //pointer to previous node
    friend class DLinkedList<T>;                //DLinkedList decladed as friend class so it can have access to members of this class
};

#endif