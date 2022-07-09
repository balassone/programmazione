#ifndef LSTACK_H
#define LSTACK_H
#include "LinkedList.h"
#include <stdexcept>
template <typename E>
class LinkedStack{
public:
    LinkedStack();
    int size() const;
    bool empty() const;
    const E& top() const;
    LinkedStack<E>& push(const E& e);
    LinkedStack<E>& pop();
private:
    LinkedList<E> S;
    int n;
};

template <typename E>
LinkedStack<E>::LinkedStack() : S{}, n{0} {}

template <typename E>
const E& LinkedStack<E>::top() const{
    if(empty()){
        throw std::underflow_error("Stack underflow");
    }
    return S.getFront();
}

template <typename E>
LinkedStack<E>& LinkedStack<E>::push(const E& e){
    S.addFront(e);
    ++n;
    return *this;
}

template <typename E>
LinkedStack<E>& LinkedStack<E>::pop(){
    if(empty()){
        throw std::underflow_error("Stack underflow");
    }
    S.removeFront();
    --n;
    return *this;
}

template <typename E>
int LinkedStack<E>::size() const{
    return n;
}

template <typename E>
bool LinkedStack<E>::empty() const{
    return n == 0;
}


#endif