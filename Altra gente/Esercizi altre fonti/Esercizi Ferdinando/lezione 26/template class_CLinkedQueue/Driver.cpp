#include "CLinkedQueue.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;

int main(){

    CLinkedQueue<string> myQueue;
    myQueue.enqueue("uno");
    myQueue.enqueue("due");
    myQueue.enqueue("tre");
    myQueue.enqueue("quattro");
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    cout<<myQueue.front();
    cout<<myQueue.size();
}