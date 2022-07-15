//testDeque.cpp
#include"Deque.h"
#include<iostream>
using std::cout;
using std::endl;

int main() {
    Deque<int> d;
    d.insertFront(3);
    cout<<"d front: "<<d.front()<<endl;
    d.insertBack(5);
    cout<<"d back:  "<<d.back()<<endl;
    d.insertBack(4);
    cout<<"d back:  "<<d.back()<<endl;
    cout<<"erase front . . ."<<endl;
    d.eraseFront();
    cout<<"d front: "<<d.front()<<endl;
    cout<<"erase front . . ."<<endl;
    d.eraseFront();
    cout<<"d front: "<<d.front()<<endl;
    cout<<"Number of elments: "<<d.size()<<endl;
    cout<<"erase front . . ."<<endl;
    d.eraseFront();
    cout<<"erase front . . .\t-->\t";
    try{
        d.eraseFront();
    } catch(std::invalid_argument &E){
        cout<<E.what()<<endl;
    }

}