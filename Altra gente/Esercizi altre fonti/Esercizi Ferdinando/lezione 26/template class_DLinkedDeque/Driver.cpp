#include "DLinkedDeque.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){

    DLinkedDeque<double> deque;
    deque.enqueueFront(5.5);
    deque.enqueueFront(6.6);
    deque.enqueueFront(7.7);
    deque.enqueueBack(4.4);
    deque.enqueueBack(3.3);
    cout<<deque.front()<<endl;
    cout<<deque.back();
}