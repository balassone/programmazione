//Program to test class Time
 #include <iostream>
 #include <stdexcept>
 #include "Time.h"

 using namespace std;

 //mostra il tempo in formato 24 ore e 12 ore
 void displayTime(const string& message, const Time& time) {
     cout<< message << "\nUniversal time: "<<time.toUniversalString()<<"\nStandard time: "<<time.toStandardString()<<"\n\n";
 }

 int main () {
     Time t;

     displayTime("Initial time:", t);
     t.setTime(13,27,49);
     displayTime("After setTime:", t);

     //tentativo di settare un tempo invalido
     try {
         t.setTime(99,99,99);
     }
     catch (invalid_argument& e){
         cout<<"Exception: "<<e.what()<<"\n\n";
     }
     displayTime("After attempting to set an invalid time:", t);
 }