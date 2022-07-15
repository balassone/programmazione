#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <iostream>
#include <exception>

template <typename T>
class ArrayStack{

public:
    ArrayStack(int = 10); //costruttore di default
    void push(const T&);
    void pop();
    int size() const;
    bool empty() const;
    const T& top() const;

private:
    T* S; //definisco un puntatore a T di nome array;
    int capacity; //la dimensione dell'array deve essere definita a priori 
    int t; //mi indica la posizione dell'ultimo elemento inserito
};

template <typename T>
ArrayStack<T>::ArrayStack(int cap)
    : S{new T[cap]}, capacity{cap}, t{-1} {} //alloco spazio in memoria per contenere un certo numero (cap) di tipo T
    //la posizione iniziale è -1; perchè il prossimo elemento deve essere inserito in posizione 0

template <typename T>
bool ArrayStack<T>::empty() const{
    return (t==-1);
}

template <typename T>
int ArrayStack<T>::size() const{
    return (t+1);
}

template <typename T>
const T& ArrayStack<T>::top() const{
    if(empty()){
        throw std::runtime_error("Lo stack è vuoto");
    }
    else{
        return S[t];
    }
}

template <typename T>
void ArrayStack<T>::push(const T& ele){
    if(size()<capacity){
        ++t; //pre-incremento t
        S[t]=ele;
    }
    else
        throw std::runtime_error("Lo stack è pieno");
}

template <typename T>
void ArrayStack<T>::pop(){
    if(!empty()){
        --t;
    }
    else{
        throw std::runtime_error("Lo stack è vuoto");
    }
}




#endif