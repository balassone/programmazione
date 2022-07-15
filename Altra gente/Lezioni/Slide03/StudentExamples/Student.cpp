//ifElse.cpp
//Create and test Student object for the example
#include <iostream>
#include "ifElse.h"
using std::string;
using std::cout;
using std::cin;

int main(){
	Student account1{"Jane Green", 93};
	Student account2{"John Blue", 72};

	cout << account1.getName() << "'s letter grade equivalent of " << account1.getAverage() << "is: "<< account1.getLetterGrade() << "\n";
	cout << account2.getName() << "'s letter grade equivalent of " << account2.getAverage() << "is: "<< account2.getLetterGrade() << std::endl;
	
}
