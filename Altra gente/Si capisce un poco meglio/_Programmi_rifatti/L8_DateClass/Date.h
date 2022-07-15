//Date.h
#include<array>
#include<iostream>

#ifndef DATE_H
#define DATE_H


class Date {
    
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator+(const Date&, int);
    friend Date operator+(int, const Date&);


    public:
        Date(int=1, int=1, int=1900);   //constructor
        
        void setDate(int,int,int);

        bool operator<(const Date&) const;
        Date& operator++();              //prefix increment operator
        Date operator++(int);     //postfix increment operator
        Date& operator +=(unsigned int);
        static bool leapYear(int);
        bool endOfMonth(int) const;
        bool operator!=(const Date&) const;

    private:
        int day;
        int month;
        int year;
        static const std::array<unsigned int, 13> days;     //days per month
        void helpIncrement();
};

#endif