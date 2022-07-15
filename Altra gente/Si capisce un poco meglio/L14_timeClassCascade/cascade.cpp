//Cascade.cpp
//Cascading member-function calls with "this" pointer

#include<iostream>
#include"Time.h"
using std::cout; using std::endl;

int main () {
    Time t;
    t.setHour(18).setMinute(30).setSecond(22); //cascade function calls

    //output universal and standard time formats
    cout<<"Universal time: "<<t.toUniversalString();
    cout<<"\nStandard time: "<<t.toStandardString();

    //cascaded function calls
    cout<<"\n\nNew standard time: "<<t.setTime(20,20,20).toStandardString()<<endl;
}