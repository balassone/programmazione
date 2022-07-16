#include "Date.h"
#include <iostream>
#include <string>

const std::array<int, 13> Date::days{0,31,28,31,30,31,30,31,31,30,30,30,31};

Date::Date(int day, int month, int year){
	if(day>0 && day<=days[month]) this->day=day;
	if(month>0 && month<13) this->month=month;
	if(year>1900 && year<2023) this->year=year;
}

bool Date::operator<(const Date& second) const {
	if(year<second.year) return true;
	if(year==second.year && month < second.month) return true;
	if(year==second.year&&month==second.month&&day<second.day) return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& d){
	out << (d.day<9?"0":"") << d.day << "/" <<(d.month<9?"0":"") << d.month << "/" <<d.year;
	return out;
}


