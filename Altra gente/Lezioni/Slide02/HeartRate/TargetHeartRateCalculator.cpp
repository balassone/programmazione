//TargetHeartRate.cpp
//Define functions for the class TargetHeartRate

#include <iostream>
#include <string>
#include "TargetHeartRateCalculator.h"

using std::string;


TargetHeartRate::TargetHeartRate(std::string name, std::string surname, int birthDate){ //da vedere se si chiede la data o solo l'anno, visto che solo quest'ultimo è utile ai fini del programma.
    firstName=name;
    secondName=name;
    dateOfBirth=birthDate;
}
void TargetHeartRate::setFirstName(std::string name){firstName=name;}
std::string TargetHeartRate::getFirstName()const{return firstName;}

void TargetHeartRate::setSecondName(std::string surname){secondName=surname;}
std::string TargetHeartRate::getSecondName()const{return secondName;}

void TargetHeartRate::setDateOfBirth(int birthDate){dateOfBirth=birthDate;}
int TargetHeartRate::getDateOfBirth()const{return dateOfBirth;}

int TargetHeartRate::personAge(){
    int age{2021-dateOfBirth};
    return age;
}
int TargetHeartRate::maximumHeartRate(){
    int age = this->personAge();
    int maxHeartRate{220-age};
    return maxHeartRate;
}
std::string TargetHeartRate::heartBeatRange(){

    int maxHeartRate{this->maximumHeartRate()};
    double minRangeHeartRate{maxHeartRate*0.5};
    double maxRangeHeartRate{maxHeartRate*0.85};
    std::string range = std::to_string(minRangeHeartRate)+" - "+std::to_string(maxRangeHeartRate);
    return range;
}
