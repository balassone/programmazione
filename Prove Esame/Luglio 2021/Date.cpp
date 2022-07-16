#include "Date.h"

Date::Date(const int& d, const int& m, const int& y){
    if(y>=1900 && y<2023) year=y;
    if(m>0 && m<13) month=m;
    if(d>0 && d<=days[m-1]) day=d;
}

Date::Date(const Date& d){
    day=d.day;
    month=d.month;
    year=d.year;
}

Date& Date::operator=(const Date& d){
    day=d.day;
    month=d.month;
    year=d.year;
    return *this;
}

const int& Date::getDay() const{
    return day;
}
Date& Date::setDay(const int& d){
    if(d>0 && d<=days[month-1]) day=d;
    return *this;
}
const int& Date::getMonth() const{
    return month;
}
Date& Date::setMonth(const int& m){
    if(m>0 && m<13) month=m;
    return *this;
}
const int& Date::getYear() const{
    return year;
}
Date& Date::setYear(const int& y){
    if(y>=1900 && y<2023) year=y;
    return *this;
}

bool Date::operator==(const Date& d) const{
    if(year!=d.year) return false;
    if(month != d.month) return false;
    if(day != d.day) return false;
    return true;
}
bool Date::operator<(const Date& d) const{
    if(year>=d.year) return false;
    if (month>=d.month) return false;
    if (day>d.day) return false;
    return true;
}

std::string Date::toString() const{
   std::ostringstream out;
   out << (day<9?"0":"") << day << "/" << (month<9?"0":"") << month <<"/"<<year;
   return out.str();
}

std::ostream& operator<<(std::ostream& out, const Date& d){
    out << d.toString();
    return out;
}