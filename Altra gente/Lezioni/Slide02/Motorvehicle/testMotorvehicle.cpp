#include <iostream>
#include <string>

#include "Motorvehicle.h"
using std::cin;
using std::cout;
using std::endl;

int main(){
	Motorvehicle automobile{"Audi", "Electric", 2020, "Bianco", 60};
	Motorvehicle moto;/*"Kawasaki", "Diesel", 1996, "Verde", 2200*/
	
	automobile.displayVehicleDetails();
	
	moto.displayVehicleDetails();
	moto.setColor("Verde");
	moto.setYearOfManufacture(1700);
	moto.setYearOfManufacture(1996);
	moto.setEngineCapacity(1700);
	moto.setMake("Kawasaki");
	moto.setFuelType("Diesel");
	moto.displayVehicleDetails();
	Motorvehicle autoclone;
	autoclone.displayVehicleDetails();
	autoclone.setColor(automobile.getColor());;
	autoclone.setYearOfManufacture(automobile.getYearOfManufacture());
	autoclone.setEngineCapacity(automobile.getEngineCapacity());
	autoclone.setMake(automobile.getMake());
	autoclone.setFuelType(automobile.getFuelType());
	autoclone.displayVehicleDetails();
}