//testCLinkedList.cpp

#include"CLinkedList.h"
#include<iostream>
#include<string>
using std::cout; using std::endl;
using std::string;

int main() {
    CLinkedList<int> l1;
    l1.add(2);
    l1.add(4);
    l1.add(6);
    l1.add(3);
    cout<<"l1: "<<l1.toString()<<endl;
    cout<<"l1 size: "<<l1.size()<<endl;
    cout<<"l1[1] = "<<l1[1]<<endl;
    CLinkedList<int> l2{l1};
    cout<<"l2: "<<l2.toString()<<endl;
    l2.advance();
    l2.remove();
    cout<<"l2 after advancing cursor on 4 and removing element after cursor: "<<endl<<l2.toString()<<endl;
    CLinkedList<int> l3 = l1;
    cout<<"l3 = l1 : "<<l3.toString()<<endl;
    CLinkedList<string> l4;
    l4.add("Barca");
    l4.add("Cappello");
    cout<<l4.toString()<<endl;
    l4.advance();
    cout<<"l4 advance . . .\n"<<l4.toString();
}