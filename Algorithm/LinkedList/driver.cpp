#include <iostream>
#include <string>
#include "LinkedList.h"

using std::string;
using std::cout;

int main(){
	LinkedList<string> L;
	L.addFront("FCO");
	L.addFront("LAX");
	L.addFront("JFK");
	L.addFront("FRK");
	cout << L[0] << "\t" << L.size() <<std::endl;
	cout << L.search("JFK") << std::endl;
	L.deleteNode("FRK");
	cout << L[0] << std::endl;
	cout << L.toString() << std::endl;
	L.reverse();
	cout << L.toString() << std::endl;
	LinkedList<string> L2{L};
	//L2.addFront(10);
	//L2.addFront(20);
	cout << L2.front() << "\n";
	return 0;
}
