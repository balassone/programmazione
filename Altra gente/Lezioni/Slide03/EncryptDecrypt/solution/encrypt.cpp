// encrypt.cpp

#include <iostream>
using std::cin;
using std::cout; 

int main() {
	int digit{0}; 		//has the digit to encrypt

	cout << " insert the  4-value digit to encrypt ";
	cin >> digit; // input
	
	while (digit < 999 || digit > 10000) { // checks if the input is correct; otherwise it should be repeated
		cout << "the value is wrong, try again";
		cin >> digit;
	}
	// encrypting phase: extracting the digits and encrypting
	unsigned int digit1 = ((digit /1000) + 7)%10 ;
	unsigned int digit2 = (((digit /100) %10) + 7)%10 ;
	unsigned int digit3 = (((digit /10) %100) + 7)%10 ;
	unsigned int digit4 = ((digit %1000) + 7)%10 ;
	//swapping phase
	unsigned int newDigit = (digit3 * 1000) + (digit4 * 100) + ( digit1 * 10) + digit2;
	
	cout << "the encrypted Value is " << newDigit;
}