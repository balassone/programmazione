#include <iostream>
#include <string>
#include"Motor.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	MotorVehicle car{"Fiat","Diesel",2003,"Grey",140};

	car.displayCarDetails();

	cout << "New color? ";
	string newColor;
	getline(cin,newColor);
	car.setColor(newColor);

	car.displayCarDetails();



	return 0;
}
