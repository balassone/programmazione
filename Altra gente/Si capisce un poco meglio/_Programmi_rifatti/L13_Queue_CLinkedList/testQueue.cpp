//testQueue.cpp
#include"Queue.h"
#include<iostream>
#include<string>
using std::cout; using std::endl;


int main() {
    Queue<int> a;
    cout<<"\nEnqueue 2. . .\nEnqueue 3. . .\nEnqueue 4. . .\n\n";
    a.enqueue(2);
    a.enqueue(3);
    a.enqueue(4);
    cout<<"front: "<<a.front()<<endl;
    cout<<"Dequeue. . ."<<endl;
    a.dequeue();
    cout<<"front: "<<a.front()<<endl;
    cout<<"Dequeue. . ."<<endl;
    a.dequeue();
    cout<<"front: "<<a.front()<<endl;;
    cout<<"size: "<<a.size()<<endl;
    std::string empty = (a.empty()) ? "TRUE" : "FALSE";
    cout<<"queue empty? "<<empty<<endl;
    cout<<"Dequeue. . ."<<endl;
    a.dequeue();
    empty = (a.empty()) ? "TRUE" : "FALSE";
    cout<<"queue empty? "<<empty<<endl;
    cout<<"Size: "<<a.size()<<endl;


}