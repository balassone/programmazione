//testDate.cpp
//testing the class Date
#include <iostream>
#include <string>
#include "date.h"

using std::cout;
using std::string;
using std::cin;

int main(){
    Date capodanno{2021, 12, 31};
    Date compleannoDiQualcuno;
    capodanno.displayDate();
    compleannoDiQualcuno.displayDate();
    compleannoDiQualcuno.setDay(20);
    compleannoDiQualcuno.setMonth(8);
    compleannoDiQualcuno.setYear(1999);
    cout<<compleannoDiQualcuno.getYear()<<"/"<<compleannoDiQualcuno.getMonth()<<"/"<<compleannoDiQualcuno.getDay()<<"\n";
}
