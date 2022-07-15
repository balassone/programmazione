// bintodec.cpp
//converts a binary number to a decimal

#include <iostream>

using std::cin;
using std::cout;

int pow(int func, int exp);//power function prototype

int main(){
	int binaryNumber[10]; // stores binary number to insert
	int decimalConversion = 0; // stores the decimal number converted from the binary digits
	int i{0}; // counter that stores the digit used 
	cout <<"Inserire numero in binario \n inserire qualsiasi numero diverso da 0 e 1 per terminare \n";
	for (; i<10; i++){//allows to insert the binary digits
		cin >> binaryNumber[i];
		if(binaryNumber[i] != 0 && binaryNumber[i] != 1){ // input stops when a value different from the binary digits is inserted
			break;
		}
	};
	//second for cycle: converting the binary digits to a decimal Number
	for(int j = 0; j<i; j++){//the j index visits as much digits as the given in input
		if(binaryNumber[j] == 0 || binaryNumber[j] == 1){	//Ignores numbers other than 0 or 1
			decimalConversion += binaryNumber[j] * pow (2,j); 
		}
	}
	cout <<"valore finale " << decimalConversion; //final output
	
	
}


int pow(int func, int exp){
	if (exp == 0)
		return 1;
	else 
	return func * pow(func, exp -1);
}
