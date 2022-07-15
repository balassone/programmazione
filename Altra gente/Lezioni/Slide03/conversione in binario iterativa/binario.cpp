#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

int main(){
	
	int number;
	cout <<"insert number to convert in binary ";
	cin>>number;
	double value{0};
	double exponent{0};
	for(; number != 0; number/=2){
		int digit = number % 2;
		value += digit * pow(10, exponent++);
	}
	cout<<value;
}