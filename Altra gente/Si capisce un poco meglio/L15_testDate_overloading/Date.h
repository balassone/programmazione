//Date.h

#ifndef DATE_H
#define DATE_H

#include<array>
#include<iostream>

class Date {
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator+(int, const Date&);
    friend Date operator+(const Date&, int);
    public:
        Date(int d=1, int m=1, int y=1900); //default constructor
        void setDate(int, int, int); //set month, day, year
        Date& operator++(); //prefix increment operator
        Date operator++(int); //postfix increment operator
        Date& operator+=(unsigned int); //add days, modify object
        static bool leapYear(int); //control if year is a leap (bisestile) year
        bool endOfMonth(unsigned int) const; //control if day is the end day of the month
        bool operator<(const Date&) const;
    private:
        unsigned int day;
        unsigned int month;
        unsigned int year;
        static const std::array<unsigned int, 13> days; //days per month
        void helpIncrement(); //utility function for incrementing date
};
#endif