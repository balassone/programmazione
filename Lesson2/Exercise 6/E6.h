#include<iostream>
#include<string>

class HeartRates{
public:

	HeartRates(std::string myName, std::string mySurname, int bday, int bmonth, int byear)
	: name{myName}, surname{mySurname}, day{bday}, year{byear} {
		if(bmonth>0 && bmonth<13){
			month=bmonth;
		}
	}

	int getAge(){
		if(month>3){
			return 2022-year-1;
		} else if (month<3){
			return 2022-year;
		} else{
			if(day>14){
				return 2022-year-1;
				}
			else {return 2022-year;}	

			}
		}
	int maxHR(){
		return 220-getAge();
	}	

	int target1(){
		return maxHR()*0.5;
	}

	int target2(){
		return maxHR()*0.85;
	}
	

private:
	std::string name;
	std::string surname;
	int day;
	int month{1};
	int year;
};
