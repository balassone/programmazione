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
    ciao.deleteElem(4);
    ciao[3]=8;
    ciao.addPosition(3,12);
    cout << ciao[3] << endl;
    cout << ciao.toString();
    return 0;
}
