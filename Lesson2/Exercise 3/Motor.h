#include <string>

class MotorVehicle{
	public:
		MotorVehicle(std::string, std::string,int, std::string, int);
		MotorVehicle& setMake(std::string);
		std::string getMake() const;
		MotorVehicle& setFuel(std::string);
		std::string getFuel() const;
		MotorVehicle& setYear(int);
		int getYear() const;
		MotorVehicle& setColor(std::string);
		std::string getColor() const;
		MotorVehicle& setCapacity(int);
		int getCapacity() const;
		void displayCarDetails();
	private:
		std::string make;
		std::string fuelType;
		int yearOfManifacture;
		std::string color;
		int engineCapacity;
};