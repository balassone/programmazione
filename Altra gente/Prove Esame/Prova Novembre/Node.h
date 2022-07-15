#ifndef NODE_H
#define NODE_H


#include"Task.h"

class LinkedList;

class Node{
    public:

    private:
    Task elemento;
    Node* next;

    Node& operator=(const Node& n){
        this->elemento=n.elemento;
        this->next=n.next;
        return *this;
    }

    friend class LinkedList;
    friend class Progetto;
};

#endif