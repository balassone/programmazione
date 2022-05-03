#include "Date.h"
#include <iostream>
#include <string>

const std::array<unsigned int, 13> Date::days{0,31,28,31,30,31,30,31,31,30,30,30,31};

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

Date operator+(int numdays, const Date& dd){
	Date newdate=dd;
	for(int i=1; i<=numdays; ++i){newdate.helpIncrement();}
	return newdate;
}

Date operator+(const Date&dd, int numdays){
	Date newdate=dd;
	for(int i=1; i<=numdays; ++i){newdate.helpIncrement();}
	return newdate;
}

Date& Date::operator++(){
	helpIncrement();
	return *this;
}

Date Date::operator++(int){
	Date temp{*this};
	helpIncrement();
	return temp;
}

Date& Date::operator+=(unsigned int additionalDays){
	for(unsigned int i=0; i<additionalDays; ++i){
		helpIncrement();
	}
	return *this;
}

bool Date::leapYear(int testYear){
	return (testYear % 400 ==0 || (testYear % 100 != 0 && testYear % 4 ==0));
}

bool Date::endOfMonth(int testDay) const {
	if(month == 2 && leapYear(year)){
		return testDay==29;
	}
	else return testDay==days[month];
}


