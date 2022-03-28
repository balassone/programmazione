#include<string>
#include<iostream>

class MotorVehicle {

public:

	MotorVehicle(std::string vMake, std::string vFuel, int year, std::string vColor, int CV)
	: make{vMake}, fuelType{vFuel}, yearOfManufacture{year}, color{vColor}, engineCapacity{CV} {}

	void setMake(std::string vMake){
		make = vMake;
	}

	std::string getMake() const{
		return make;
	}

	void setFuel(std::string vFuel){
		fuelType=vFuel;
	}

	std::string getFuel() const{
		return fuelType;
	}

	void setYear(int year){
		yearOfManufacture=year;
	}

	int getYear() const{
		return yearOfManufacture;
	}

	void setColor(std::string vColor){
		color=vColor;
	}

	std::string getColor() const{
		return color;
	}

	void setCV(int CV){
		engineCapacity=CV;
	}

	int getCV() const{
		return engineCapacity;
	}
	
	void displayCarDetails() const{
		std::cout << "Make: " << getMake() << std::endl;
		std::cout << "Fuel Type: " << getFuel() << std::endl;
		std::cout << "Year of Manifacture: " << getYear() << std::endl;
		std::cout << "Color: " << getColor() << std::endl;
		std::cout << "Engine Capacity: " << getCV() << " CV" << std::endl;
	}

private:

	std::string make;
	std::string fuelType;
	int yearOfManufacture;
	std::string color;
	int engineCapacity;

};
