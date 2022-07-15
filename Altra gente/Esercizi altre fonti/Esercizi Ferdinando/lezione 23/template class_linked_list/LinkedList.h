#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <exception>
using std::runtime_error;


template <typename NODETYPE>
class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    const NODETYPE& front() const;
    void addFront(const NODETYPE&);
    void removeFront();

private:
    Node<NODETYPE>* head;
};

template <typename NODETYPE>
LinkedList<NODETYPE>::LinkedList()
    : head{nullptr} {}

template <typename NODETYPE>
LinkedList<NODETYPE>::~LinkedList(){
    while(!empty()){
        removeFront();
    }
}

template <typename NODETYPE>
bool LinkedList<NODETYPE>::empty() const{
    if(head==nullptr){
        return true;
    }
    return false;
}

template <typename NODETYPE>
const NODETYPE& LinkedList<NODETYPE>::front() const{
    if(!empty()){
        return head->elemento;
    }
    else
        throw runtime_error("La lista è vuota");
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::addFront(const NODETYPE& ele){
    Node<NODETYPE>* v=new Node<NODETYPE>;
    v->elemento=ele;
    v->next=head;
    head=v;
}

template <typename NODETYPE>
void LinkedList<NODETYPE>::removeFront(){
    if(!empty()){
        Node<NODETYPE>* old=head;
        head=head->next;
        delete old;
    }
    else 
        throw runtime_error("La lista è vuota");
}

#endif
