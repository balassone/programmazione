//CLinkedList.cpp
#include"CLinkedList.h"
#include<stdexcept>
#include<sstream>
#include<iostream>

//constructor
template<typename T>
CLinkedList<T>::CLinkedList() : cursor{nullptr} {}

//destructor
template<typename T>
CLinkedList<T>::~CLinkedList(){
    while ((!empty())){
        remove();
    }
    delete cursor;
}

//copy constructor
template<typename T>
CLinkedList<T>::CLinkedList(const CLinkedList<T>& list){
    if (list.empty()){
        cursor = nullptr;
    }
    else {
        cursor = new CNode<T>;
        cursor->next = cursor;
        cursor->elem = list[0];
        if (list.size() > 1){
            for (int i=1; i<list.size(); i++){
            add(list[i]);
        }
        }
    }
}

//overloading =
template<typename T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList<T>& list) { 
    if (this == &list){
        return *this;
    }
    ~CLinkedList();
    if (list.empty()){
        cursor = nullptr;
    } else {
        cursor = new CNode<T>;
        if (list.size() == 1){
            cursor->elem = list.cursor->elem;
            cursor->next = cursor;
        } else {
            for (int i=0; i<list.size(); i++){
                this[i] = list[i];
            }
        }
    }
}

//is list empty?
template<typename T>
bool CLinkedList<T>::empty() const {
    return cursor == nullptr;
}

//size
template<typename T>
int CLinkedList<T>::size() const {
    int i = 0;
    if (cursor != nullptr){
        CNode<T>* ptr = cursor;
        while (ptr->next != cursor){
            i++;
            ptr = ptr->next;
        }
        i++;
        return i;
    }
    else {
        std::cerr<<"Lista vuota\n";
        return -1;
    }
}

//front of the list (after cursor element)
template<typename T>
const T& CLinkedList<T>::front() const {
    return cursor->next->elem;
}

//back of the list (cursor element)
template<typename T>
const T& CLinkedList<T>::back() const {
    return cursor->elem;
}

//advance cursor
template<typename T>
void CLinkedList<T>::advance() {
    cursor = cursor->next;
}

//add after cursor
template<typename T>
void CLinkedList<T>::add(const T& e){
    CNode<T>* newNode = new CNode<T>;
    newNode->elem = e;
    if (cursor == nullptr){
        newNode->next = newNode;
        cursor = newNode;
    }
    else {
        newNode->next = cursor->next;
        cursor->next = newNode;
    }
}

//remove after cursor
template<typename T>
void CLinkedList<T>::remove() {
    if (empty()) {
        throw std::invalid_argument("List empty, can't remove elements.");
    }
    CNode<T>* old = cursor->next;
    if (old == cursor){                 //only 1 element
        cursor = nullptr;
    }
    else {                              //more than 1 element
        cursor->next = old->next;
        delete old;
    }
}

//operator[] to access to an element of the list
template<typename T>
const T& CLinkedList<T>::operator[](int i) const{
    if (cursor == nullptr){
        throw std::invalid_argument("List is empty. You can not access to any element.");
    }
    if (i<size()){
        CNode<T>* ptr = cursor;
        int j=0;
        while (j<i){
            ptr = ptr->next;
            j++;
        }
        return ptr->elem;
    }
    else {
        throw std::invalid_argument("You tried to access to a nonexistent element.");
    }

}


//toString() shows elements in the list
template<typename T>
std::string CLinkedList<T>::toString() const {
    std::ostringstream out;
    CNode<T>* ptr = cursor;
    if (empty()){
        out<<"String is empty\n";
        return out.str();
    }
    out<<"Cursor --> "<<ptr->elem<<" --> ";
    ptr = ptr->next;
    while (ptr != cursor){
        out<<ptr->elem<<" --> ";
        ptr = ptr->next;
    }
    out<<" Cursor";
    return out.str();
}





