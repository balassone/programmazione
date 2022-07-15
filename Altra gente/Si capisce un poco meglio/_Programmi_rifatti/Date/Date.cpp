//Date.cpp
#include"Date.h"
#include<string>
#include<stdexcept>
using std::array;
using std::ostream;
using std::string;

const array<unsigned int, 13> Date::days {0,31,29,31,30,31,30,31,31,30,31,30,31};

Date::Date(int d, int m, int y) {
    setDate(d,m,y);
}

void Date::setDate(int d, int m, int y) {
    year = y;
    if (m>=1 && m<=12){
        month = m;
    }
    else throw std::invalid_argument("Month out of range");
    if ((month == 2 && leapYear(year) && d>=1 && d<=29)|| (d>=1 && d<=days[month]))  {
        day = d;
    } else throw std::invalid_argument("Day out of range for current year");
}

//operator+=
Date& Date::operator+=(unsigned int num){
    for(int i=0; i< num; i++) {
        helpIncrement();
    }
    return *this;
}

//prefix increment
Date& Date::operator++() {
    helpIncrement();
    return *this;
}
//postfix increment
Date Date::operator++(int){
    Date temp{*this};
    helpIncrement();
    return temp;
}

//overloading <
bool Date::operator<(const Date& d) const {
    if (year < d.year){
        return true;
    }
    if (year == d.year && month < d.month){
        return true;
    }
    if (year == d.year && month == d.month && day < d.day){
        return true;
    }
    return false;
}

//(friend) overloading <<
ostream& operator<<(ostream& out, const Date& d) {
    static string monthName[13] {"","January", "February", "March", "April", "June", "July", "August", "September", "October", "November", "December"};
    out<<d.day<<" "<<monthName[d.month]<<" "<<d.year;
    return out;
}

//(friend) overloading +
Date operator+(int n, const Date& d) {
    Date newDate{d};
    for (int i=0; i<n; i++){
        newDate.helpIncrement();
    }
    return newDate;
}

//(friend) overloading +
Date operator+(const Date& d, int n) {
    Date newDate{d};
    for (int i=0; i<n; i++){
        newDate.helpIncrement();
    }
    return newDate;
}

//help increment
void Date::helpIncrement() {
    if (!endOfMonth(day)){
        day++;
    }
    else {
        if (month != 12){
            month+=1;
            day=1;
        }
        else {
            day=1;
            month = 1;
            year+=1;
        }
    }
}

bool Date::endOfMonth(int i) const {
    if (month == 2 && leapYear(year)){
        return i == 29;
    }
    else return i==days[month];
}

bool Date::leapYear(int testYear) {
    return (testYear % 400 == 0 || (testYear%100 != 0 && testYear%4 ==0));
}