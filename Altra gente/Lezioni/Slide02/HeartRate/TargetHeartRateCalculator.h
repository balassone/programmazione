#include <string>
#include <iostream>
class TargetHeartRate{
public:
	TargetHeartRate(std::string name, std::string surname, int birthDate);
	void setFirstName(std::string name);
	std::string getFirstName()const;
	void setSecondName(std::string surname);
	std::string getSecondName()const;	
	void setDateOfBirth(int birthDate);
	int getDateOfBirth()const;
	int personAge();
	int maximumHeartRate();
	std::string heartBeatRange();
private:
	std::string firstName;
	std::string secondName;
	int dateOfBirth;
};
