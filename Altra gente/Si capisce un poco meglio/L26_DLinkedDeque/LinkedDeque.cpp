//LinkedDeque.cpp

#include"LinkedDeque.h"

template<typename T>
LinkedDeque<T>::LinkedDeque() : D(), n{0} {}

template<typename T>
int LinkedDeque<T>::size() const {
    return n;
}

template<typename T>
bool LinkedDeque<T>::empty() const {
    return n==0;
}

template<typename T>
const T& LinkedDeque<T>::front() {
    return (D.front());
}

template<typename T>
const T& LinkedDeque<T>::back() {
    return (D.back);
}

template<typename T>
void LinkedDeque<T>:: insertFront(const T& e) {
    return D.addFront(e);
    n++;
}

template<typename T>
void LinkedDeque<T>:: insertBack(const T& e){
    return D.addBack(e);
    n++;
}

template<typename T>
void LinkedDeque<T>:: removeFront(){
    if (empty()){
        throw std::runtime_error("deque empty");
    }
    return D.removeFront();
    n--;
}

template<typename T>
void LinkedDeque<T>:: removeBack(){
     if (empty()){
        throw std::runtime_error("deque empty");
    }
    return D.removeBack();
    n--;
}