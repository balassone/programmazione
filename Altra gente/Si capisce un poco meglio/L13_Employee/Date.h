//Date.h

#include<string>

#ifndef DATE_H
#define DATE_H

class Date {
    public:
        static const unsigned int monthsPerYear{12}; //months in a year
        explicit Date (unsigned int = 1, unsigned int = 1, unsigned int =1900);
        std::string toString() const; //date string in format month/day/year
        ~Date();
    private:
        unsigned int month; //1-12
        unsigned int day; //1-31 based on month
        unsigned int year; //any year

        //utility function to check if day is proper for month and year
        unsigned int checkDay(int) const;
};

#endif