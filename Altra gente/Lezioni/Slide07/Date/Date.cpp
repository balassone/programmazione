// Date.cpp
//Date class member-function definitions
#include <sstream>
#include <string>
#include <iostream>
#include <array>
#include <stdexcept>
#include "Date.h"

using std::string;
using std::ostringstream;
using std::endl;
using std::array;
using std::cout;
using std::invalid_argument;

//Date consructor: confirms propervalue for month…
//calls utility function checkDay to confirm proper value for day
Date::Date(unsigned int mn, unsigned int dy, unsigned int yr)
: month{mn}, day{checkDay(dy)}, year{yr} {
	if((mn < 1) || (mn>monthsPerYear)) { // validate the month
		throw invalid_argument("month must be 1-12");
	}
	
	//output Date object to show when its constructor is called
	cout <<"Date object constructor for date " << toString() << endl;
}

//print Date object in form month/day/year

string Date::toString() const {
	ostringstream output;
	output << day << '/' << month << '/' << year;
	return output.str();
}
//output Date object to show when its destructor is called
Date::~Date() {
	cout << "Date object destructor for date " << toString() <<endl;
}

//utility function to confirm proper day value based on
//month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const {
	static const array<int, monthsPerYear + 1> daysPerMonth{
	0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// determine wheter testDay is valid for specified month
	if ((testDay > 0) && (testDay <= daysPerMonth[month])) {
		return testDay;
		} 
	
	// February 29 check for leap year
	if((month == 2) && (testDay == 29) && (year % 400 == 0 || ((year % 4 == 0) && (year % 100 != 0)))){
			return testDay;
		}
		
	throw invalid_argument("Invalid day for current month and year");
}
