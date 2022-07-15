// bintodec.cpp
//converts a binary number to a decimal

#include <iostream>

using std::cin;
using std::cout;

int pow(int func, int exp); // function prototype

int main(){
	int binaryNumber; // stores the binary 
	int decimalConversion{0}; // stores its decimal conversion
	int digitPosition{0};	 // scans how many digits has the binary number
	cout <<"Inserire numero in binario \n"; // insert the value
	cin >> binaryNumber;
	
	while(binaryNumber != 0){ 	 // scans the binary number until his value are over
		decimalConversion += pow(2*(binaryNumber % 2), digitPosition); 	  	// the decimal value is based on the position 
																			// and the fact that there is a 1 or a 0
		binaryNumber /= 10; 		// truncate the last digit of the binary number
		digitPosition++;		// passes to the next digit
	}
	
	
	
	cout <<"valore finale " << decimalConversion;
	
	
}

// calculates the power of a binary number recursively based on the base and the exponential
int pow(int func, int exp){
	if (exp == 0 && func != 0) 	 // default value if the exponential is 0 and the base is different than zero
		return 1;
	else if (func == 0)		// returns zero if the base equals to zero
		return 0;
	else 
	return func * pow(func, exp -1);
}

