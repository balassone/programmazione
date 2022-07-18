#include "Date.h"
#include <iostream>
#include <string>
#include <sstream>

const std::array<int, 13> Date::days{0,31,28,31,30,31,30,31,31,30,30,30,31};

Date::Date(int day, int month, int year){
	setDate(day,month,year);
}

void Date::setDate(int dd, int mm, int yy){
	if(mm>=1 && mm<=12)
		month=mm;
	else throw std::invalid_argument("Month 1-12");	
	
	if(yy>=1900 && yy<=2100) year=yy;
	else throw std::invalid_argument("Year");

	if((month==2&&leapYear(year) && dd>=1 && dd<=29) || (dd>=1&&dd<=days[month])) day=dd;
	else throw std::invalid_argument("Day OOR");
}

bool Date::operator<(const Date& second) const {
	if(year<second.year) return true;
	if(year==second.year && month < second.month) return true;
	if(year==second.year&&month==second.month&&day<second.day) return true;
	return false;
}



bool Date::leapYear(int testYear){
	return (testYear % 400 ==0 || (testYear % 100 != 0 && testYear % 4 ==0));
}

std::ostream& operator<<(std::ostream& out, const Date& d){
	out << (d.day<10?"0":"") << d.day << "/" << (d.month<10?"0":"") << d.month << "/" << d.year;
	return out;
}