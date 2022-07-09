#include <iostream>
#include "LinkedList.h"
#include <string>
using std::string;
using std::cin; using std::cout; using std::endl;

int main(){
    LinkedList<int> ciao;
    ciao.addFront(3);
    ciao.addOrder(4);
    ciao.addOrder(5);
    ciao.addOrder(6);
    //ciao[3]=7;
    ciao.addOrder(8);
    cout << ciao.toString() << endl;
    return 0;
}
