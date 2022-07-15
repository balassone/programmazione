//testTHR.cpp
//tests the class TargetHeartRate

#include <iostream>
#include <string>
#include "TargetHeartRateCalculator.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main(){
	
	TargetHeartRate nonna{"Assunta", "Di Fraia", 1945};
    cout<<"Nome: "<<nonna.getFirstName()
    <<"\n Cognome: "<<nonna.getSecondName()
    <<"\n Anno di Nascita: "<<nonna.personAge()
    <<"\n massimo batto Cardiaco :"<<nonna.maximumHeartRate()
    <<"\n Raggio di valori battito cardiaco : "<<nonna.heartBeatRange();
}
