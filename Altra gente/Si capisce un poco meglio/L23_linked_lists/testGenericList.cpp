//testGenericList.cpp
#include<iostream>
#include<string>
#include"LinkedList.h"

using std::string;
using std::cout;

int main(){
    LinkedList<string> L;
    L.addFront("FCO");
    L.addFront("LAX");
    cout<<"L front: " << L.front()<<"\n";
    L.removeFront();
    cout<<"L front after remove: "<<L.front()<<"\n";
    LinkedList<int> L2;
    L2.addFront(10);
    L2.addFront(20);
    cout<<"L2 front: "<<L2.front()<<"\n";
    
}