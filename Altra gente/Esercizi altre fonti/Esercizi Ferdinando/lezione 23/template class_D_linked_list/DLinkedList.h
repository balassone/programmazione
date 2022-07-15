#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "Node.h"
#include <string>
#include <iostream>
#include <exception>
#include <sstream>

template <typename NODETYPE>
class DLinkedList{

public:
    DLinkedList(); //costruttore
    ~DLinkedList(); //distruttore
    bool empty() const;
    const NODETYPE& front() const;
    const NODETYPE& back() const;
    void addFront(const NODETYPE&);
    void addBack(const NODETYPE&);
    void removeFront();
    void removeBack();
    std::string toString();
    void insertOrder(const NODETYPE&);
    void reverse();

private:
    Node<NODETYPE>* header;
    Node<NODETYPE>* trailer;

protected:
    void add(Node<NODETYPE>*,const NODETYPE& ele);
    void remove(Node<NODETYPE>*);
};

template<typename NODETYPE>
DLinkedList<NODETYPE>::DLinkedList(){
    header=new Node<NODETYPE>;
    trailer=new Node<NODETYPE>;
    header->next=trailer;
    trailer->prev=header;
    trailer->next=nullptr;
    header->prev=nullptr;
}

template<typename NODETYPE>
DLinkedList<NODETYPE>::~DLinkedList(){
    while(!empty()){
        removeFront();
    }
    delete header;
    delete trailer;
}

template<typename NODETYPE>
bool DLinkedList<NODETYPE>::empty() const{
    return (header->next==trailer);
}

template<typename NODETYPE>
const NODETYPE& DLinkedList<NODETYPE>::front() const{
    return header->next->element;
}

template<typename NODETYPE>
const NODETYPE& DLinkedList<NODETYPE>::back() const{
    return trailer->prev->element;
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::add(Node<NODETYPE>* v,const NODETYPE& ele){
    Node<NODETYPE>* u=new Node<NODETYPE>;
    u->element=ele;
    u->next=v;
    u->prev=v->prev;
    v->prev->next=u;
    v->prev=u;
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::remove(Node<NODETYPE>* v){
    if(!empty()){
        Node<NODETYPE>* u=v->prev;
        Node<NODETYPE>* w=v->next;
        u->next=w;
        w->prev=u;
        delete v;
    }
    else{
        throw std::runtime_error("La lista è vuota");
    }
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::addFront(const NODETYPE& ele){
    add(header->next,ele);
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::addBack(const NODETYPE& ele){
    add(trailer,ele);
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::removeFront(){
    remove(header->next);
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::removeBack(){
    remove(trailer->prev);
}

template<typename NODETYPE>
std::string DLinkedList<NODETYPE>::toString(){
    std::ostringstream out;
    out<<"Header <--->";
    Node<NODETYPE>* v=header->next;
    while(v!=trailer){
        out<<(v->element)<<"<--->";
        v=v->next;
    }
    out<<"Trailer";
    return out.str();
}

template<typename NODETYPE>
void DLinkedList<NODETYPE>::insertOrder(const NODETYPE& ele){
    Node<NODETYPE>* v=header->next;
    while(v!=trailer){
        if(v->element > ele){
            break;
        }
        else v=v->next;
    }
    add(v,ele);
}

template <typename NODETYPE>
void DLinkedList<NODETYPE>::reverse() {
    DLinkedList<NODETYPE> T;
    while(!(this->empty())){
        NODETYPE x=(this->front());
        (this->removeFront());
        T.addFront(x);
    }
    while(!T.empty()){
        NODETYPE x=T.front();
        T.removeFront();
        (this->addBack(x));
    }
}




#endif
