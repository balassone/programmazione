//date.cpp
//defining the function for the Date class

#include <iostream>
#include "date.h"


    Date::Date(){}
	Date::Date(int y, int m, int d){
        this->setDay(d);
        this->setMonth(m);
        this->setYear(y);
	}
	void Date::setDay(int d){
		if(d > 0 && d<32){
			day = d;
		}
	}
	void Date::setMonth(int m){
		if(m >0 && m <13){
			month=m;
		}
	}
	void Date::setYear(int y){
		if(y>0){
			year=y;
		}
	}
	int Date::getDay()const{return day;}
    int Date::getMonth()const{return month;}
    int Date::getYear()const{return year;}
	void Date::displayDate(){
		std::cout<<month<<"/"<<day<<"/"<<year<<std::endl;
	}

