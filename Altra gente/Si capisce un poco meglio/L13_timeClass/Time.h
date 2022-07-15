//Time.h
//Time class definition
#include<string>

//evitare inclusioni multiple dell'header
#ifndef TIME_H
#define TIME_H

//Time class definition
class Time {
    public:
        void setTime(int, int, int);    //setta ore, minuti, secondi
        std::string toUniversalString() const; //stringa contenente l'ora in formato 24h
        std::string toStandardString() const; //stringa contenente l'ora in formato 12h
    private:
        unsigned int hour{0};
        unsigned int minute{0};
        unsigned int second{0};
};

#endif