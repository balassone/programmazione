#include <iostream>
using std::cin;
using std::cout;

int main()
{
	int age = 0;
	std::string message;
	cout<< "What's your age? ";
	cin >> age;
	message = (age <= 25 ) ? "Youth is wonderful, enjoy it!": "Age is a mental state";
	cout << message << "\n";
	
	return 0;
	
}