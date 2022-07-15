//Time.h
//Time class modified to enable cascade member-function calls.
#include<string>

#ifndef TIME_H
#define TIME_H

class Time {
    public:
        explicit Time (int=0, int=0, int=0); //default constructor

        //set functions (Time& return types enable cascading)
        Time& setTime(int, int, int);
        Time& setHour(int);
        Time& setMinute(int);
        Time& setSecond(int);

        //other functions (get and others)
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        std::string toUniversalString() const; //24h format
        std::string toStandardString() const; //12h format
    
    private:
        unsigned int hour{0};
        unsigned int minute{0};
        unsigned int second{0};
};

#endif