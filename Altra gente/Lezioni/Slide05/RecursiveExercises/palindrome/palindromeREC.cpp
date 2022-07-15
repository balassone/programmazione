//palindromeREC.cpp
//given a sequence, check if it's palindrome or not

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin; 

bool isPalindrome(int* array, int num1, int num2);

int main(){
	
	int numbers[6];
	cout<<"insert the number sequence";
	for(int i = 0;i<5;i++){
		cin>>numbers[i];
	} 
	if(isPalindrome(numbers, 0, 5))
	{
		cout<<"\nis a palindrome ";
	}
	else 
	{
		cout<<"\n is not even close";
	}
	
}
bool isPalindrome(int* array, int num1, int num2){ //recursion
	if(num1 == num2 || (num1+1 == num2 && (array[num1]==array[num2]))){//base case 1: the array is ended and the final numbers are equal
		return true; 
	}
	else if((array[num1] != array [num2])&&(num1+1 == num2)){//base case 2: the array is ended and the final numbers are not equal
		return false;
		
	}
	else{
		return true && isPalindrome(array, num1+1, num2-1); // recursion step
	}
	

}