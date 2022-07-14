#ifndef LINKEDDEQUE_H
#define LINKEDDEQUE_H
#include "DLinkedList.h"
template <typename T>
class LinkedDeque{
public:
    LinkedDeque();
    //~LinkedDeque();
    int size() const;
    bool empty() const;
    const T& front() const;
    const T& back() const;
    LinkedDeque<T>& insertFront(const T& e);
    LinkedDeque<T>& insertBack(const T& e);
    LinkedDeque<T>& removeFront();
    LinkedDeque<T>& removeBack();
    LinkedDeque<T>& bubbleSort();
    LinkedDeque<T>& swap(int i, int j);
    //std::string toString() const;
private:
    DLinkedList<T> D;
    int n;    
};

template <typename T>
LinkedDeque<T>::LinkedDeque() : D(), n(0) {}
template <typename T>
int LinkedDeque<T>::size() const{
    return n;
}
template <typename T>
bool LinkedDeque<T>::empty() const{
    return n == 0;
}
template <typename T>
const T& LinkedDeque<T>::front() const{
    return D.front();
}
template <typename T>
const T& LinkedDeque<T>::back() const{
    return D.back();
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::insertFront(const T& e){
    D.addFront(e);
    n++;
    return *this;
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::insertBack(const T& e){
    D.addBack(e);
    n++;
    return *this;
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::removeFront(){
    if(empty()){
        throw std::runtime_error("DLinkedList is empty");
    } else{
        D.removeFront();
        n--;
    }
    return *this;
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::removeBack(){
    if(empty()){
        throw std::runtime_error("DLinkedList is empty");
    } else{
        D.removeBack();
        n--;
    }
    return *this;
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::bubbleSort(){
    D.bubbleSort();
    return *this;
}
template <typename T>
LinkedDeque<T>& LinkedDeque<T>::swap(int i, int j){
    D.swap(i, j);
    return *this;
}
#endif