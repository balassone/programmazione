//Deque.cpp
//implementation of Deque class functions

#include<stdexcept>

//empty constructor
template<typename E>
Deque<E>::Deque() : D(), n{0} {}

//number of elements in deque
template<typename E>
int Deque<E>::size() const {
    return n;
}

//is deque empty?
template<typename E>
bool Deque<E>::empty() const {
    return n==0;
}

//first element of deque
template<typename E>
const E& Deque<E>::front() {
    return D.front();
}

//last element of deque
template<typename E>
const E& Deque<E>::back() {
    return D.back();
}

//add element at beginning
template<typename E>
void Deque<E>::insertFront(const E& e) {
    D.addFront(e);
    n++;
}

template<typename E>
void Deque<E>::insertBack(const E& e){
    D.addBack(e);
    n++;
}

template<typename E>
void Deque<E>::eraseFront(){
    if (empty()){  
        throw std::invalid_argument("Deque is empty. Can't remove elements.");
    }
    D.removeFront();
    n--;
}

template<typename E>
void Deque<E>::eraseBack(){
    if (empty()){  
        throw std::invalid_argument("Deque is empty. Can't remove elements.");
    }
    D.removeBack();
    n--;
}

