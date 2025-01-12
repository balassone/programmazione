#include <iostream>
#include <sstream>
template <typename T>
DLinkedList<T>::DLinkedList(){
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    header->prev = nullptr;
    trailer->prev = header;
    trailer ->next = nullptr;
}

template <typename T>
DLinkedList<T>::~DLinkedList(){
    while(!empty()){
        removeFront();
    }
    delete[] header;
    delete[] trailer;
}

template <typename T>
bool DLinkedList<T>::empty() const{
    return header->next == trailer;
}

template <typename T>
const T& DLinkedList<T>::front() const{
    return header->next->elem;
}

template <typename T>
const T& DLinkedList<T>::back() const{
    return trailer->prev->elem;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::add(DNode<T>* v, const T& e){
    DNode<T> *u = new DNode<T>;
    u->elem = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::addFront(const T& e){
    add(header->next, e);
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::addBack(const T& e){
    add(trailer, e);
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::remove(DNode<T>* v){
    if(empty()){
        throw std::runtime_error("DLinkedList is empty");
    }
    else{
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete[] v;
    }
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::removeFront(){
    remove(header->next);
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::removeBack(){
    remove(trailer->prev);
    return *this;
}

template <typename T>
std::string DLinkedList<T>::toString() const{
    std::ostringstream out;
    DNode<T> *u = header->next;
    out << "Header <--> ";
    while(u != trailer){
        out << u->elem << " <--> ";
        u = u->next;
    }
    out << "Trailer";
    return out.str();
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::addOrder(const T& e){
    DNode<T> *p = header->next;
    while(p != trailer){
        if(e<p->elem){
            break;
        }
        p = p->next;
    }
    add(p, e);
    return *this;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::bubbleSort(){
    DNode<T> *p = header->next;
    while(p != trailer){
        DNode<T> *q = p->next;
        while(q != trailer){
            if(p->elem > q->elem){
                T temp = p->elem;
                p->elem = q->elem;
                q->elem = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return *this;
}
template <typename T>
DLinkedList<T>& DLinkedList<T>::swap(int i, int j){
    if(!empty()){
        DNode<T> *p = header->next;
        int k = 0;
        while(p != trailer){
            if(k == i){
                T temp = p->elem;
                p->elem = p->next->elem;
                p->next->elem = temp;
            }
            p = p->next;
            k++;
        }
        p = header->next;
        k = 0;
        while(p != trailer){
            if(k == j){
                T temp = p->elem;
                p->elem = p->next->elem;
                p->next->elem = temp;
            }
            p = p->next;
            k++;
        }
    }
    return *this;
}
template <typename T>
int DLinkedList<T>::size() const{
    int count = 0;
    DNode<T> *p = header->next;
    while(p != trailer){
        count++;
        p = p->next;
    }
    return count;
}
template <typename T>
DLinkedList<T>& DLinkedList<T>::swapOddEven(){
    if(!empty()){
        DNode<T> *p = header->next;
        DNode<T> *q = header->next->next;
        if(size()%2 == 0){
            while(p != trailer){
                T temp = p->elem;
                p->elem = q->elem;
                q->elem = temp;
                p = p->next;
                q = q->next->next;
            }
        }
        else{
            while(q != trailer){
                T temp = p->elem;
                p->elem = q->elem;
                q->elem = temp;
                p = p->next;
                q = q->next->next;
            }
        }
    }
}