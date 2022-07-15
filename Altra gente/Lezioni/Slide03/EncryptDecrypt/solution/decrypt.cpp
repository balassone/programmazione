#include <iostream>
using std::cin;
using std::cout; 

int main() {
	int digit{0}; 		//has the digit to encrypt

	cout << " insert the  4-value digit to decrypt ";
	cin >> digit; // input
	
	while (digit < 999 || digit > 10000) { // checks if the input is correct; otherwise it should be repeated
		cout << "the value is wrong, try again";
		cin >> digit;
	}
	// decrypting phase: extracting the digits and decrypting
	// in order to undo the decryption we need to adding 3 to the number and swap the digits in their original position
	unsigned int digit1 = ((digit /1000) + 3)%10 ;
	unsigned int digit2 = (((digit /100) %10) + 3)%10;
	unsigned int digit3 = (((digit /10) %100) + 3)%10;
	unsigned int digit4 = ((digit %1000) + 3)%10;
	//swapping phase
	unsigned int newDigit = (digit3 * 1000) + (digit4 * 100) + ( digit1 * 10) + digit2;
	
	cout << "the decrypted Value is " << newDigit;
}