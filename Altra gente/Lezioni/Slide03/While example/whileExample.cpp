//whileExample.cpp
//example of a class-average using sentinel-controlled iteration by the while

#include <iostream>
#include <iomanip> //parametrized stream manipulatiors

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(){
	//initialization phase
	int total{0}; //initialize sum of grades
	unsigned int gradeCounter {0}; // initialize # of grades entered so far
	cout << "Enter grade or -1 to quit : ";
	int grade;
	cin >> grade;
	//loop until sentinel value read from user
	while(grade != -1){
		total = total + grade; 	//add grade to total
		gradeCounter = gradeCounter + 1; // increment counter
		//prompt for input and read next grade from user
		cout << "Enter grade or -1 to quit : ";
		cin >> grade;
	}
	//termination phase
	//if user entered at leasst one grade ...
	if (gradeCounter != 0 ){
		// use number with decimal poit to calculate average of grades
		double average{static_cast<double>(total) / gradeCounter};
		//display total and average (with two digits of precision)
		cout << "\nTotal of the " << gradeCounter << " grades entered is " << total;
		cout << std::setprecision(2)<<std::fixed;
		cout << "\nClass average is " << average << endl;
	}
	else {// no grades were entered, so output appropiate message
		cout << "No grades were entered"<< endl;
	}
}