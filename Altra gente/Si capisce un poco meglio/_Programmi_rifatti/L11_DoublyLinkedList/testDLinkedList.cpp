//testDLinkedList.cpp
#include"DLinkedList.h"
#include<iostream>
using std::cout; using std::endl;

//appunto: questo addInOrder funziona solo se si ha una lista già ordinata dalla coda alla testa costruita
//con addFront o addBack; perciò l'uso corretto che andrebbe fatto di addInOrder è quello di costruire una
//lista usando SOLO addInOrder

int main() {
    DLinkedList<int> l1;
    l1.addFront(1);
    l1.addFront(2);
    l1.addFront(3);
    l1.addFront(4);
    DLinkedList<int> l2{l1};
    cout<<"l1: "<<l1.toString()<<endl<<"l2, copy of l1: "<<l2.toString()<<endl;
    cout<<"l1 size: "<<l1.size()<<endl;
    DLinkedList<int> l3 = l2;
    cout<<"l3 = l2 : "<<l3.toString()<<endl;
    l1.addInOrder(0);
    l1.addInOrder(5);
    cout<<"l1 after addInOrder of 0 and 5: \n"<<l1.toString()<<endl;
    cout<<"3rd element of l1: "<<l1[2]<<endl;
    cout<<"l1 size: "<<l1.size()<<endl;
    l3.addInOrder(6);
    cout<<"\nl3 after addInOrder of 6: \n"<<l3.toString()<<endl;
    
    l2.addInOrder(0);
    l2.addInOrder(5);
    cout<<"\nl2 after addInOrder of 0 and 5: \n"<<l2.toString()<<endl;
    cout<<"3rd element of l2: "<<l2[2]<<endl;
    cout<<"l2 size: "<<l2.size()<<endl;
    l2.addInOrder(9);
    cout<<"Add in order 9 in l2: "<<l2.toString()<<endl;
    l2.addInOrder(7);
    cout<<"Add in order 7 in l2: "<<l2.toString()<<endl;

    //mostro come NON funziona addInOrder se la lista non è già ordinata dalla coda alla testa
    DLinkedList<int> l4;
    l4.addFront(0);
    l4.addBack(3);
    l4.addBack(2);
    cout<<"\nl4: "<<l4.toString();
    l4.addInOrder(1);
    cout<<"\nl4 after adding 1 in order: "<<endl<<l4.toString()<<endl;
 

}