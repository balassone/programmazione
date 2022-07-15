#include "CLinkedList.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;

int main(){

    CLinkedList<string> C;
    C.add("A");
    C.add("B");
    C.advance();
    C.add("C");
    C.advance();
    C.advance();
    cout<<C.toString();
}