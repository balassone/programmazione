#include <iostream>
#include "WWW.h"

using std::cout;

int main(){
	WWW w(6);
	w.printRanks();
	std::cout << "Updating ranks ..." << std::endl;
	w.addLink(0,3);
	w.addLink(0,5);
	w.addLink(1,2);
	w.addLink(2,0);
	w.addLink(2,1);
	w.addLink(2,3);
	w.pageRank();
	w.printRanks();
	return 0;
}
