//DLinkedList.cpp

/****   header--front-------------------back--trailer     ****/

#include <sstream>
#include<stdexcept>

template<typename T>
DLinkedList<T>::DLinkedList() {                     //constructor creating an empty list, with only sentinels
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->next = nullptr;
    trailer->prev = header;
}

template<typename T>                        
DLinkedList<T>::~DLinkedList(){                     //destructor
    while (!empty()){   
        removeFront();
    }
    delete header;
    delete trailer;
}

template<typename T>
bool DLinkedList<T>::empty() const{
    return ((header->next)==trailer);
}

template<typename T>
const T& DLinkedList<T>::front()const{
    return (header->next->elem);
}

template<typename T>
const T& DLinkedList<T>::back()const{
    return (trailer->prev->elem);
}

template<typename T>
void DLinkedList<T>::add(DNode<T>* v, const T& e) {             //adding new node, containing element e, before v
    DNode<T>* newNode = new DNode<T>;
    newNode->elem = e;

    newNode->next= v;
    newNode->prev=v->prev;
    v->prev->next=newNode;
    v->prev=newNode;
}

template<typename T>
void DLinkedList<T>::addFront(const T& e){
    add(header->next, e);
}

template<typename T>
void DLinkedList<T>::addBack(const T& e){
    add(trailer, e);
}

template<typename T>
void DLinkedList<T>::remove (DNode<T>* v){
    if (empty()) {
        throw std::runtime_error("list empty, cannot remove any element");
    }
    DNode<T>* u = v->prev;
    DNode<T>* w = v->next;

    u->next = w;
    w->prev = u;

    delete v;
}

template<typename T>
void DLinkedList<T>::removeFront(){
    remove(header->next);
}

template<typename T>
void DLinkedList<T>::removeBack(){
    remove(trailer->prev);
}

template<typename T>
void DLinkedList<T>:: addOrder(const T& e){
    DNode<T>* u = header->next;
    while(u != trailer){
        if (e < u->elem){
            break;
        }
        u= u->next;
    }
    add(u,e);
}

template<typename T>
void DLinkedList<T>::listReverse(){
    DLinkedList<T> D;
    while (!(empty())){
        T e = front();
        removeFront();
        D.addFront(e);
    }
    while (!D.empty()){
        T e = D.front();
        D.removeFront();
        addBack(e);
    }
}

template<typename T>
T& DLinkedList<T>::operator[](int i){
    DNode<T>* u= header->next;
    int cont = 0;
    if (i<size()){
        while (cont != i) {
            u->next = u->next->next;
            cont++;
        }
        return u->elem;
    }
    else throw std::out_of_range("out of range");
}

template<typename T>
int DLinkedList<T>::size(){
    DNode<T>* u = header->next;
    int cont=0;
    while (header->next != trailer){
        cont++;
        header->next = header->next->next;
    }
    return cont;
}

template<typename T>
std::string DLinkedList<T>::toString(){
    std::ostringstream out;
    DNode<T>* u = header->next;
    out<<"Header <--> ";
    while (u!=trailer){
        out<<u->elem<<"<-->";
        u=u->next;
    }
    out<<"Trailer";
    return out.str();
}