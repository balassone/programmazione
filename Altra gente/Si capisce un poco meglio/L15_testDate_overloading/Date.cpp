//Date.cpp
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

//initialize static member; one classwide copy
const array<unsigned int, 13> Date::days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Date constructor
Date::Date(int day, int month, int year) {
    setDate(day, month, year);
}

void Date::setDate(int dd,int mm,int yy){
    if (mm>=1 && mm<=12) {
        month=mm;
    }
    else {
        throw invalid_argument{"month must be 1-12"};
    }
    if (yy>=1900 && yy<=2100) {
        year=yy;
    }
    else {
        throw invalid_argument{"year must be 1900-2100"};
    }
    
    //test for leap year
    if ((month==2 && leapYear(year) && dd>=1 && dd<=29) || (dd >=1 && dd<=days[month])) {
        day=dd;
    }
    else {
        throw invalid_argument{"Day is out of range for current month and year"};
    }
}
bool Date::operator<(const Date& second) const {
    if (year < second.year) {
        return true;
    }
    if (year==second.year && month < second.month) {
        return true;
    }
    if (year==second.year && month==second.month && day<second.day) {
        return true;
    }
    return false;
}

//add a specific number of days
Date operator+(int numdays, const Date& dd){
    Date newdate=dd;
    for (int i=1; i<=numdays; i++) {
        newdate.helpIncrement();
    }
    return newdate;
}

//add the invoking object and a specific number of days
Date operator+(const Date&dd, int numdays) {
    Date newdate=dd;
      for (int i=1; i<=numdays; i++) {
        newdate.helpIncrement();
    }
    return newdate;
}

//overloaded prefix increment operator
Date& Date::operator++() {
    helpIncrement();
    return *this;
}

//overloaded postfix increment operator
Date Date::operator++(int){
    Date temp{*this};
    helpIncrement();

    return temp;
}

Date& Date:: operator+=(unsigned int additionalDays) {
    for (unsigned int i=0; i<additionalDays; ++i){
        helpIncrement();
    }
    return *this;
} 

//un anno è bisestile se è divisibile per 4 e non per 100
bool Date::leapYear(int testYear) {
    return (testYear %400 ==0 ||(testYear%100 !=0 && testYear % 4 ==0));
}

//determine whether the day is the last day of the month
bool Date::endOfMonth(unsigned int testDay) const {
    if (month==2 && leapYear(year)){
        return testDay==29;
    }
    else {
        return (testDay == days[month]);
    }
}

void Date::helpIncrement() {

    if(!endOfMonth(day)) {
        ++day;
    }
    else {
        if(month<12){
            ++month;
            day=1;
        }
        else {
            ++year;
            month=1;
            day=1;
        }
    }
}

//overloaded output operator
ostream& operator<<(ostream&output, const Date& d){
    static string monthName[13]{"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    output<<d.day<<' '<<monthName[d.month]<<' '<<d.year;
    return output; //enable cascading
}