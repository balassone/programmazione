//Astack.h
#ifndef ASTACK_H
#define ASTACK_H

#include<stdexcept>

template<typename E>
class ArrayStack {
    static const int DEF_CAPACITY{10};          //default stack capacity
    public:
        ArrayStack(int cap=DEF_CAPACITY);       //default constructor  
        int size () const;
        bool empty();                           //is stack empty?
        const E& top () const;                  //returns top element of the stack
        void push(const E& e);
        void pop();

    private:
        E* s;                                   //array of stack elements
        int capacity;                           //capacity of stack
        int t;                                  //index of top of the stack
};
#endif

template<typename E>
void ArrayStack<E>::push(const E& e){
    if (size()==capacity){
        throw std::runtime_error("StackFull");
        S[++t]=e;
    }
}

template<typename E>
void ArrayStack<E>::pop(){
    if (empty()){
        throw std::runtime_error("Stack empty");
    }
    --t;
}

template<typename E>
ArrayStack<E>::ArrayStack(int cap) : S{new E[cap]}, capacity = cap, t{-1} {}

template<typename E>
int ArrayStack<E>::size() const{
    return t+1;
}

template<typename E>
bool ArrayStack<E>::empty(){
    return (t<0);
}

template<typename E>
const E& ArrayStack<E>::top() const{
    if (empty()){
        throw std::runtime_error("Top of empty stack");
    }
    return S[t];
}


