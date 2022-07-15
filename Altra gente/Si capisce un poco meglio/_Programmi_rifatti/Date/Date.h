//Date.h
#ifndef DATE_H
#define DATE_H
#include<array>
#include<iostream>
class Date{
    
    //overloading <<
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend Date operator+(int, const Date&);
    friend Date operator+(const Date&, int);
    public:
        explicit Date(int=1, int=1, int=2000);                   //constructor

        static const unsigned int MonthsPerYear{12};    //months per year

        //set function for setting date
        void setDate(int,int,int);
        //operator++ (prefix increment)
        Date& operator++();
        //operator++(postfix increment)
        Date operator++(int);
        //operator+=
        Date& operator+=(unsigned int);
        //is year leap-year?
        static bool leapYear(int);
        //end of month
        bool endOfMonth(int) const;
        //overloading <
        bool operator<(const Date&) const;

    private:
        int year;
        int month;
        int day;
        static const std::array<unsigned int,13> days;   //day per month
        void helpIncrement();                   //utility function for incrementing date 
};

#endif