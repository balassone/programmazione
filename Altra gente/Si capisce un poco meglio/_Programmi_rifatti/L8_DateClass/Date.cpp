//Date.cpp
#include"Date.h"
#include<stdexcept>
#include<string>
using std::array;
using std::ostream;
using std::string;

//initialize static member
const array<unsigned int, 13> Date::days {
    0,31,28,31,30,31,30,31,31,30,31,30,31
};

//Date constructor
Date::Date(int d, int m, int y) {
    setDate(d,m,y);
}

//set day, month, year
void Date::setDate(int d, int m, int y){
    if (m>=1 && m<=12){
        month=m;
    }
    else throw std::invalid_argument("Month must be between 1 and 12");
    
    if ((month==2 && leapYear(year) && d>=1 && d<=29) || (d>=1 && d<=days[month]) ){
        day=d;
    }
    else throw std::invalid_argument("Day out of range for this month and this year");
    year=y;
}

//overloading operator <

bool Date::operator<(const Date& date) const{
    if (year != date.year) {
        return year<date.year;
    }
    else if (month!= date.month){
        return month<date.month;
    }
    else return day<date.day;
}

//overloading operator !=
bool Date::operator!=(const Date& date) const {
    if (year==date.year && month==date.month && day==date.day){
        return false;
    }
    return true;

}

//adding number of days 
Date operator+(int numdays, const Date& d) {
    Date newDate = d;
    for (int i=1; i <= numdays; i++){
        newDate.helpIncrement();
    }
    return newDate;
}

Date operator+ (const Date& d, int numdays){
    Date newDate = d;
    for (int i=1; i<= numdays; i++){
        newDate.helpIncrement();
    }
    return newDate;
}

//prefix increment
Date& Date::operator++() {
    helpIncrement();
    return *this;
}

//postfix increment
Date Date::operator++(int) {
    Date temp{*this};
    helpIncrement();

    return temp;
}

//add specified number of days to date
Date& Date::operator+=(unsigned int additionalDays){
    for (int i=1; i<=additionalDays; i++){
        helpIncrement();
    }
    return *this;
}

ostream& operator<<(ostream& out, const Date& d){
    static string monthName[13] { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    out<<d.day<<' '<<monthName[d.month]<<' '<<d.year;
    return out;
}

void Date::helpIncrement(){
    if (!endOfMonth(day)){
        ++day;
    }
    else {
        if (month!= 12){
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

bool Date::endOfMonth(int testDay) const{
    if (month == 2 && leapYear(year)) {
        return testDay==29;
    }
    else return (testDay==days[month]);
}

bool Date::leapYear(int testYear){
    if ((testYear % 100 !=0 && testYear % 4 ==0) || testYear %400 == 0 ) {
        return true;
    }
    else return false;
}