//Date.h
//Defining attributes and methods of the class Date

#include <iostream>

class Date{
public:
    Date();
	Date(int y, int m, int d);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay()const;
    int getMonth()const;
    int getYear()const;
	void displayDate();
private:
	int day{1};
	int month{1};
	int year{1900};
};
