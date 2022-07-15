#include "DLinkedList.h"
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(){

    DLinkedList<string> l1;
    l1.insertOrder("Napoli");
    l1.insertOrder("Roma");
    l1.insertOrder("Bari");
    l1.insertOrder("Milano");
    l1.insertOrder("Venezia");
    cout<<l1.toString();
    l1.reverse();
    cout<<endl;
    cout<<l1.toString();

}