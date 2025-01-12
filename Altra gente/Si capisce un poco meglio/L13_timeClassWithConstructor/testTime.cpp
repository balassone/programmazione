//testTime.cpp
//constructor with default arguments
#include<iostream>
#include<stdexcept>
#include"Time.h"
using std::cout;
using std::invalid_argument;
using std::endl;
using std::cerr;
using std::string;

void displayTime(const string& message, const Time& time) {
    cout<<message<<"\nUniversal time: "<<time.toUniversalString()<<"\nStandard time: "<<time.toStandardString()<<"\n\n";
}

int main () {
    Time t1;
    Time t2{2};
    Time t3{21,34};
    Time t4{12,25,42};

    cout<<"Constructed with:\n\n";
    displayTime("t1: all argument defaulted", t1);
    displayTime("t2: hour specified; minute and second defaulted",t2);
    displayTime("t3: hour and minute specified; second defaulted", t3);
    displayTime("t4: hour, minute and second specified", t4);

//tentativo di inizializzare t5 con valori non consentiti
    try{
        Time t5{27, 74, 99};
    }
    catch (invalid_argument& e){
        cerr<< "Exception while initializing t5: "<<e.what()<<endl; 
    }
}