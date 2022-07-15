#include <string>

class Motorvehicle{
public:
	Motorvehicle();
		
	Motorvehicle(std::string brand, std::string fuel, int year, std::string color, int capacity);
	void setYearOfManufacture(int year);
	
	void setEngineCapacity(int capacity);
	void setColor(std::string color);
	void setMake(std::string brand);
	void setFuelType(std::string fuel);
	int getYearOfManufacture()const;
	int getEngineCapacity()const;
	std::string getMake()const;
	std::string getColor()const;
	std::string getFuelType()const;
	void displayVehicleDetails();
private:
	std::string make;
	std::string fuelType;
	std::string vehicleColor;
	std::string color;
	int yearOfManufacture;
	int engineCapacity;
};