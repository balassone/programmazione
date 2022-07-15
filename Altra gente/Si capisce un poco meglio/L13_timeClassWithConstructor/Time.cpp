//Time.cpp
//Member function definitions for class Time

#include<iomanip>
#include<stdexcept>
#include<sstream>
#include<string>
#include "Time.h"

using std::ostringstream;
using std::invalid_argument;
using std::string;
using std::setw;
using std::setfill;

//Costruttore di Time inizializza ogni dato membro
Time::Time(int hour, int minute, int second) {
    setTime(hour, minute, second);
}
//set new Time using universal time
void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
}
//set hour value
void Time::setHour(int h) {
    if (h>=0 && h<24) {
        hour=h;
    }
    else {
        throw invalid_argument("Hour must be 0-23");
    }
}
//set minute value
void Time::setMinute(int m) {
    if (m>=0 && m<59) {
        minute=m;
    }
    else {
        throw invalid_argument("Minute must be 0-59");
    }
}
//set second value
void Time::setSecond(int s) {
    if (s>=0 && s<59) {
        second=s;
    }
    else {
        throw invalid_argument("Second must be 0-59");
    }
}

//return hour value
unsigned int Time::getHour() const {
    return hour;
}
//return minute value
unsigned int Time::getMinute() const {
    return minute;
}
//return second value
unsigned int Time::getSecond() const {
    return second;
}

//return Time as a string in universal-time format (24h)
string Time::toUniversalString() const {
    ostringstream output;
    output<<setfill('0')<<setw(2)<<getHour()<<":"<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond();
    return output.str();
}

//return Time as a string in standard-time format (12h)
string Time::toStandardString() const {
    ostringstream output;
    output<<((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)<<":"<<setfill('0')<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond()<<(hour<12 ? " AM" : " PM");
    return output.str();
}