#include <iostream>
#include "LinkedList.h"
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl;

int main(){
    LinkedList<int> ciao;
    ciao.addFront(3);
    ciao.addPosition(0,12);
    cout << ciao.toString();
    return 0;
}
