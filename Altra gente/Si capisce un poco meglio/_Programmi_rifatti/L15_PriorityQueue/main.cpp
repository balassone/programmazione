#include<iostream>
#include"PriorityQueue.h"
using std::cout; using std::endl;
using std::vector;

int main() {
    PriorityQueue<int> p;
    p.push(3);
    cout<<p.top()<<endl;
    p.push(5);
    cout<<p.top()<<endl;
    p.push(9);
    cout<<p.top()<<endl;
    p.push(2);
    cout<<p.top()<<endl;
    cout<<p.size()<<endl;
    cout<<"Is priority queue empty? (1 yes, 0 no): "<<p.empty()<<endl;
    p.pop();
    cout<<"Removing 9 (top element). . ."<<endl;
    cout<<"New top: "<<p.top()<<endl;
    cout<<"Size of queue: "<<p.size()<<endl;
}