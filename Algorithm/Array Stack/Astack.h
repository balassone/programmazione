#ifndef ASTACK_H
#define ASTACK_H
#include <iostream>
#include <stdexcept>
template <typename E>
class ArrayStack{
    static const int DEF_CAPACITY = 10;
    public:
        ArrayStack(int cap = DEF_CAPACITY);
        int size() const;
        bool empty() const;
        const E& top() const;
        ArrayStack<E>& push(const E& e);
        ArrayStack<E>& pop();
    private:
        E* S;
        int capacity;
        int t;    
};

template <typename E>
ArrayStack<E>& ArrayStack<E>::push(const E& e){
    if(size() == capacity){
        throw std::overflow_error("Stack overflow");
    }
    S[++t] = e;
    return *this;
}

template <typename E>
ArrayStack<E>& ArrayStack<E>::pop(){
    if(empty()){
        throw std::underflow_error("Stack underflow");
    }
    --t;
    return *this;
}
template <typename E>
ArrayStack<E>::ArrayStack(int cap): S{new E[cap]}, capacity{cap}, t{-1} {}
template <typename E>
int ArrayStack<E>::size() const{
    return t + 1;
}
template <typename E>
bool ArrayStack<E>::empty() const{
    return t < 0;
}
template <typename E>
const E& ArrayStack<E>::top() const{
    if(empty()){
        throw std::underflow_error("Stack underflow");
    }
    return S[t];
}

#endif