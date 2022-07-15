//Time.h
//Time class containing a constructor with default arguments
#include<string>

#ifndef TIME_H
#define TIME_H

class Time {
    public:
        explicit Time(int = 0, int = 0, int = 0); //costruttore di default

        //set functions
        void setTime (int,int,int); //setta ore, minuti e secondi
        void setHour (int); //setta l'ora (dopo la validazione)
        void setMinute (int); //setta i minuti (dopo la validazione)
        void setSecond (int); //setta i secondi (dopo la validazione)

        //get functions
        std::string toUniversalString() const; //24h
        std::string toStandardString() const; //12h

        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

    private:
        unsigned int hour{0}; // 0 - 23
        unsigned int minute{0}; // 0 - 59
        unsigned int second{0}; // 0 - 59   
};

#endif