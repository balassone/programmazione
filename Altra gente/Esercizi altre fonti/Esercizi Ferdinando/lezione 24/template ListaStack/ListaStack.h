#ifndef LISTASTACK_H
#define LISTASTACK_H

#include "LinkedList.h"

template <typename T>
class ListaStack{

public:
    ListaStack();
    int size() const;
    const T& top() const;
    bool empty() const;
    void push(const T&);
    void pop();

private:
    LinkedList<T> S; //definisco una lsta di nome S e di tipo T
    int n; //n è il supporto a size
    //se non avessimo questo supporto, per ottenere size dovremmo scorrere tutta la lista e questo richiede un tempo o(n).
    //In questo modo possiamo ottenere size in un tempo costante a svantaggio di dover allocare in memoria una variabile di tipo int
};

template <typename T>
ListaStack<T>::ListaStack()
    : S(), n{0} {}

template <typename T>
int ListaStack<T>::size() const{
    return n; //non devo scorrere tutta la lista. n lo incremento ad ogni inserimento
}

template <typename T>
bool ListaStack<T>::empty() const{
    return n==0;
}

template <typename T>
const T& ListaStack<T>::top() const{
    if(empty()) throw runtime_error("Lo stack è vuoto");
    return S.front();
}

template <typename T>
void ListaStack<T>::push(const T& ele){
    S.addFront(ele);
    n++;
}

template <typename T>
void ListaStack<T>::pop(){
    if(empty()) throw runtime_error("Lo stack è vuoto");
    S.removeFront();
    n--;
}

#endif