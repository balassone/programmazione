// Fibonacci, loop infinito

#include <iostream>

using std::cout;

int main(){

	unsigned long long int a{0}, b{1},c{a+b};
	cout << a << ", " << b << ", ";
	while (true){

		cout << c << ", ";
		a=b;
		b=c;
		c=a+b;

	}

	return 0;
}
