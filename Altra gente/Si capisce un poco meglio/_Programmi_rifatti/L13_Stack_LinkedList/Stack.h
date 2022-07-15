//Stack.h
#include"LinkedList.h"

#ifndef STACK_H
#define STACK_H

template<typename E>
class Stack {
    public:
        Stack();                                //constructor
        int size() const;                       //size of stack
        bool empty() const;                     //is stack empty?
        const E& top() ;                        //top of the stack
        void push(const E&);                    //push an element on top of the stack
        void pop();                             //pop an element from the top of the stack

    private:
    LinkedList<E> S;
    int n;
};

#include"Stack.cpp"

#endif