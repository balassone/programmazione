#ifndef NODE_H
#define NODE_H

template <typename NODETYPE> class DLinkedList;

template <typename NODETYPE>
class Node{
    
private:
    NODETYPE element;
    Node<NODETYPE>* next;
    Node<NODETYPE>* prev;

    friend class DLinkedList<NODETYPE>;
};

#endif