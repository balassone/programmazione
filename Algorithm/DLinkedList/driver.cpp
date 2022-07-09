#include <iostream>
#include "DLinkedList.h"

int main(){
    DLinkedList<std::string> L;
    L.addFront("ORD");
    L.addFront("JFK");
    L.addFront("SCO");
    L.addBack("SFO");
    std::cout << L.toString() << std::endl;
    return 0;
}