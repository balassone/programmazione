#include <iostream>

using std::cout;
using std::cin; 

int main(){
	int number{0};				// user input number
	int digits[5]; 			// digits of the number
	cout<<"insert the number sequence: Number should have 5 digits\n";
	
	
	//user input: looping untile the value inserted is correct
	cin >> number ; 
	
	while(!(number > 9999 && number < 100000)){
		cout << "the given value is not correct: try again\n" ;
		
		cin >> number;
	}
	
	
	// extracts the digits based on their position
	digits[0] = (number /10000);
	digits[1] = (number % 10000 / 1000);
	digits[2] = (number % 10000 % 1000 / 100);
	digits[3] = (number % 10000 % 1000 % 100 / 10);
	digits[4] = (number % 10000 % 1000 % 100 % 10);	
	
	bool isPalindrome = ((digits[0]==digits[4]) && (digits[1]==digits[3]));// checks whether the number is a palindrome
	if(isPalindrome)
	{
		cout<<"\nis a palindrome ";
	}
	else 
	{
		cout<<"\n is not a palindrome";
	}
	
}