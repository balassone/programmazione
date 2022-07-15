//dec2binREC.cpp
// dec2bin exercise implemented recursively
#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

void binaryConvertion(int base); // function2

int main(){
	
	int number;
	cout <<"insert number to convert in binary ";
	cin>>number;
	int exponent{0};

	binaryConvertion(number);
}

void binaryConvertion(int base) // recursion
{
    if(base == 0){
        cout << "" ;
    }
    else{ 
        binaryConvertion(base / 2);
        cout << base %2 << " " ;
    }
}