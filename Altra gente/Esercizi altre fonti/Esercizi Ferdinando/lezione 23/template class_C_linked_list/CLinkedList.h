#ifndef CLINKEDLIST_H
#define CLINKEDlIST_H

#include "Node.h"
#include <string>
#include <iostream>
#include <exception>
#include <sstream>

template <typename T>
class CLinkedList{

public:
    CLinkedList();
    ~CLinkedList();
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void advance();
    void add(const T& ele);
    void remove();

    std::string toString();

private:
    Node<T>* cursor;

};


template <typename T> 
CLinkedList<T>::CLinkedList(){
    cursor=nullptr;
}

template <typename T>
CLinkedList<T>::~CLinkedList(){
    while(!empty()){
        remove();
    }
}

template <typename T>
bool CLinkedList<T>::empty() const{
    return cursor==nullptr;
}

template <typename T>
const T& CLinkedList<T>::front() const{
    return cursor->next->element;
}

template <typename T>
const T& CLinkedList<T>::back() const{
    return cursor->element;
}

template <typename T>
void CLinkedList<T>::advance() {
    cursor=cursor->next;
}

template <typename T>
void CLinkedList<T>::add(const T& ele){
    Node<T>* v=new Node<T>;
    v->element=ele;
    if(cursor==nullptr){
        v->next=v;
        cursor=v;
    }
    else{
        v->next=cursor->next;
        cursor->next=v;
    }
}

template <typename T>
void CLinkedList<T>::remove(){
    if(empty()){
        throw std::runtime_error("La lista è vuota");
    }
    else{
        Node<T>* old=cursor->next;
        if(old==cursor){
            cursor=nullptr;
        }
        else{
            cursor->next=old->next;
            delete old;
        }
    }
}

template <typename T>
std::string CLinkedList<T>::toString(){
    std::ostringstream out;
    out<<"Cursor <--->";
    out<<cursor->element<<"<--->";
    Node<T>* v=cursor->next;
    while(v!=cursor){
        out<<v->element<<"<--->";
        v=v->next;
    }
    out<<"Cursor";

    return out.str();
}


#endif