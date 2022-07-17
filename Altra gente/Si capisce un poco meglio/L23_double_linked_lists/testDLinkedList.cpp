//testDLinkedList.cpp
#include<iostream>
#include"DLinkedList.h"
using std::cout;

int main(){
    DLinkedList<int> lista;
    lista.addFront(1);
    lista.addBack(2);
    lista.addBack(3);
    lista.addFront(5);
    lista.addOrder(4);
    lista.addFront(6);
    cout<<lista.toString()<<"\n\n";
    lista.removeBack();
    cout<<lista.toString()<<"\n\n";
    lista.removeFront();
    cout<<lista.toString()<<"\n\n";
    lista.listReverse();
    cout<<"Reverse list : "<<lista.toString()<<"\n\n";
}