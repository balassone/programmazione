//testLinkedList.cpp
//main program to test LinkedList

#include"LinkedList.h"
#include<iostream>
using std::cout; using std::endl;

int main() {
    LinkedList<int> list;
    list.addFront(3);
    cout<<"Front:" <<list.front()<<endl;
    list.addFront(5);
    cout<<"Front:" <<list.front()<<endl;
    list.addFront(6);
    cout<<"Front:" <<list.front()<<endl;
    list.addFront(9);
    cout<<"Front:" <<list.front()<<endl;
    list.addFront(2);
    list.addFront(5);
    cout<<"Front:" <<list.front()<<endl;
    cout<<"Size of list: "<<list.size()<<endl;
    cout<<"Elements in the list: "<<list.toString()<<endl;
    cout<<"Element in position 1 (2nd element): "<<list[1]<<endl;
    cout<<"Element in position 4 (5th element): "<<list[4]<<endl;
    cout<<"Element in position 0 (1st element): "<<list[0]<<endl;
    cout<<"Element in position 2 (3rd element): "<<list[2]<<endl;
    cout<<"Hai ricercato l'elemento 3 . . .\nPosizione: "<<list.search(3)<<endl;
    cout<<"Hai ricercato l'elemento 5 . . .\nPosizione: "<<list.search(5)<<endl;
    cout<<"Hai ricercato l'elemento 10 . . .\nPosizione: "<<list.search(10)<<endl;
    list.deleteElement(6);
    cout<<"Dopo l'eliminazione dell'elemento '6' : "<<list.toString()<<endl;
    list.deleteElement(9);
    cout<<"Dopo l'eliminazione dell'elemento '9' : "<<list.toString()<<endl;
    list.deleteElement(2);
    cout<<"Dopo l'eliminazione dell'elemento '2' : "<<list.toString()<<endl;
    list.deleteElement(3);
    cout<<"Dopo l'eliminazione dell'elemento '3' : "<<list.toString()<<endl;
    LinkedList<int> list2{list};
    cout<<"List 'list2', copy of 'list', is: "<<list2.toString()<<endl;
    LinkedList<int> list3=list2;
    cout<<"List 'list3' = 'list', is: "<<list3.toString()<<endl;
}