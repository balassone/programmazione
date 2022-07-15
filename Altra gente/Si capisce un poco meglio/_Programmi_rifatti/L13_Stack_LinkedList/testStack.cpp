//testStack.cpp
#include"Stack.h"
#include<iostream>
using std::cout; using std::endl;

int main() {
    Stack<int> a;
    a.push(2);
    cout<<a.top()<<endl;
    a.push(5);
    cout<<a.top()<<endl;
    a.push(8);
    cout<<a.top()<<endl;
    a.pop();
    cout<<a.top()<<endl;
    a.pop();
    cout<<a.top()<<endl;
    a.pop();
    try{
        cout<<a.top()<<endl;
    }
    catch (const std::invalid_argument& e){
        cout<<e.what();
    };
}