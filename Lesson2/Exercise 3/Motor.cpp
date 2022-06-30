#include <iostream>
#include "Motor.h"
#include <string>

MotorVehicle::MotorVehicle(std::string m, std::string f, int y, std::string c, int e)
: make(m), fuelType(f), yearOfManifacture(y), color(c), engineCapacity(e) {}

MotorVehicle& MotorVehicle::setMake(std::string m){
	make=m;
	return *this;
}

std::string MotorVehicle::getMake() const {return make;}

MotorVehicle& MotorVehicle::setFuel(std::string f) {
	fuelType=f;
	return *this;
}

std::string MotorVehicle::getFuel() const {return fuelType;}

MotorVehicle& MotorVehicle::setYear(int y){
	yearOfManifacture=y;
	return *this;
}

int MotorVehicle::getYear() const {return yearOfManifacture;}

MotorVehicle& MotorVehicle::setColor(std::string c){
	color=c;
	return *this;
}

std::string MotorVehicle::getColor() const {return color;}

MotorVehicle& MotorVehicle::setCapacity(int c){
	engineCapacity=c;
	return *this;
}

int MotorVehicle::getCapacity() const {return engineCapacity;}

void MotorVehicle::displayCarDetails(){
	std::cout << make << " " << fuelType << " " << yearOfManifacture << " " << color << " " << engineCapacity << std::endl;
}