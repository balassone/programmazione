//Time.cpp
#include<iomanip>
#include<stdexcept>
#include<string>
#include<sstream>
#include"Time.h"

using namespace std;

Time::Time(int hr,int min, int sec) {
    setTime(hr, min, sec);
}
//set values of hour, minute and second
Time& Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
    return *this; //enables cascading
}
//set hour value
Time& Time::setHour(int h){
    if(h>=0 && h<24){
        hour=h;
    }
    else {
        throw invalid_argument("hour must be 0-23");
    }
    return *this; //enables cascading
}

//set minute value
Time& Time::setMinute(int m){
    if (m>=0 && m<60) {
        minute=m;
    }
    else {
        throw invalid_argument("minute must be 0-59");
    }
    return *this; //enables cascading
}

//set second value
Time& Time::setSecond(int s){
    if(s>=0 && s<60) {
        second=s;
    }
    else {
        throw invalid_argument("second must be 0-59");
    }
    return *this; //enables cascading
}

//get hour value
unsigned int Time::getHour() const{
    return hour;
}
//get minute value
unsigned int Time::getMinute() const{
    return minute;
}
//get second value
unsigned int Time::getSecond() const{
    return second;
}

//return Time as a string in universal format (24h)
string Time::toUniversalString() const {
    ostringstream output;
    output<<setfill('0')<<setw(2)<<getHour()<<":"<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond();
    return output.str();
}

//return Time as a string in standard format (12h)
string Time::toStandardString() const {
    ostringstream output;
    output<<((getHour()==0 || getHour()==12) ? 12 : getHour() % 12)<<":"<<setfill('0')<<setw(2)<<getMinute()<<":"<<setw(2)<<getSecond()<<(getHour()<12 ? " AM" : " PM");
    return output.str();
}
