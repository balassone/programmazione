//LStaack.h

#ifndef LSTACK_H
#define LSTACK_H
#include<stdexcept>
#include"LinkedList.h"

template<typename E>
class LinkedStack{
    public:
        LinkedStack();                      //constructor
        void push(const E&);                //push
        void pop();                         //pop
        bool empty() const;                 //is stack empty?
        int size() const;                   //number of items in the stack
        const E& top();                     //top element of stack

    private:
        LinkedList<E> S;                   //linked list of elements
        int n;                              //number of elements
};


template<typename E>
void LinkedStack<E>::push(const E& e){
    ++n;
    S.addFront(e);
}

template<typename E>
void LinkedStack<E>::pop() {
    if (empty()){
        throw std::runtime_error("Stack is empty");
    }
    S.removeFront();
}

template<typename E>
LinkedStack<E>::LinkedStack(): S(), n{0} {}                 //chiama il costruttore di default della classe LinkedList per S

template<typename E>
const E& LinkedStack<E>::top(){
    if (empty()){
        throw std::runtime_error("Top of empty stack");
    }
    return S.front();
}

template<typename E>
int LinkedStack<E>::size() const {
    return n;
}

template<typename E>
bool LinkedStack<E>::empty() const {
    return n==0;
}

#endif
