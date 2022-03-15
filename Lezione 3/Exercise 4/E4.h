#include<iostream>
class Date{
public:
	Date(int theDay, int theMonth, int theYear)
	: day{theDay}, year{theYear} {

		if(theMonth>0 && theMonth<13){
			month=theMonth;
		}

	}

	void setDay(int theDay){
		day = theDay;
	}

	int getDay() const {
		return day;
	}

	void setMonth(int theMonth){
		if (theMonth>0 && theMonth<13){
			month=theMonth;
		}
		else month=1;
	}

	int getMonth() const{
		return month;
	}

	void setYear(int theYear){
		year=theYear;
	}

	int getYear() const{
		return year;
	}

	void displayDate(){
		std::cout << getMonth() << "/" << getDay() << "/" << getYear() << std::endl;
	}

private:
	int day;
	int month{1};
	int year;
};
