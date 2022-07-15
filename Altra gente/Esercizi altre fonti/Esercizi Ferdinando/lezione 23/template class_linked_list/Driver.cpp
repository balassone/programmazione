#include "LinkedList.h"
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

int main(){
    LinkedList<string> l1;
    l1.addFront("Napoli");
    l1.addFront("Roma");
    cout<<l1.front()<<endl;
    LinkedList<int> l2;
    l2.addFront(2);
    l2.addFront(5);
    cout<<l2.front()<<endl;
}