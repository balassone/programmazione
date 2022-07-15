// Motorvehicle.cpp
// Function definition for class Motorvehicle


#include <string>
#include <iostream>
#include "Motorvehicle.h"

using std::string;

Motorvehicle::Motorvehicle() {}
		
Motorvehicle::Motorvehicle(std::string brand, std::string fuel, int year, std::string color, int capacity){
	make=brand;
	fuelType=fuel;
	vehicleColor=color;
	if(year > 1899){
		yearOfManufacture=year;
}	
	if(capacity > 0){
		engineCapacity=capacity;
	}
}
void Motorvehicle::setYearOfManufacture(int year){
	if(year > 1899){
		yearOfManufacture=year;
	}
}

void Motorvehicle::setEngineCapacity(int capacity){
	if(capacity > 0){
		engineCapacity=capacity;
	}
}
void Motorvehicle::setColor(std::string color){
	vehicleColor=color;
}
void Motorvehicle::setMake(std::string brand){
	make=brand;
}
void Motorvehicle::setFuelType(std::string fuel){
	fuelType=fuel;
}
int Motorvehicle::getYearOfManufacture()const{
	return yearOfManufacture;
}
int Motorvehicle::getEngineCapacity()const{
	return engineCapacity;
}
std::string Motorvehicle::getMake()const{
	return make;
}
std::string Motorvehicle::getColor()const{
	return color;
}
std::string Motorvehicle::getFuelType()const{
	return fuelType;
}
void Motorvehicle::displayVehicleDetails(){
	std::cout<<"-------------------------------------"
	<<"\nMake: "<<make
		<<"\nFuelType: "<<fuelType
			<<"\nColor: "<<vehicleColor
				<<"\nYear Of Manufacture "<<yearOfManufacture
					<<"\nEngine capacity: "<<engineCapacity<<std::endl;
}
