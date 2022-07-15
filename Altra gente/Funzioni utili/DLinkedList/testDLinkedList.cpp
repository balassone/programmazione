//testDLinkedList.cpp

#include<iostream>
#include"DLinkedList.h"

int main() {
	DLinkedList<std::string> L;
	L.addFront("ORD");
	L.addFront("JFK");
	L.addFront("SCO");
	L.addBack("SFO");
	std::cout << L.toString() <<std::endl;
	std::cout << L.size()<<std::endl;
	std::cout << L[0]<<std::endl;
	DLinkedList<std::string> l3;
	l3.addBack("fofo");
	l3.addBack("fefe");
	std::cout << l3.toString() << std::endl;
	DLinkedList<std::string> L2(L);
	std::cout << L2.toString() << std::endl;
	DLinkedList<std::string> L4 = L;
	std::cout <<L4.toString() << std::endl;
	L4.addBack("Alessia");
	if(L2 == L){
		std::cout << "PEPPEFETISHPEPPEFETISH"<<std::endl;
	}
	if(!(L4==L)){
		std::cout << "DAVIDE VINCENZO"<<std::endl;
	}
	L2.reversal();
	std::cout << L2.toString() << std::endl;
}
