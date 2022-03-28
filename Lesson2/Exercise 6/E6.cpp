#include<iostream>
#include"E6.h"

using std::cout;
using std::endl;

int main(){

	HeartRates io{"Francesco","Balassone",23,4,2001};

	cout << "Maximum Heart Rate: " << io.maxHR() << endl;;
	cout << "Target Heart Rate between " << io.target1() << " and " << io.target2() << endl;


	return 0;
}

