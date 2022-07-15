//testDate.cpp
//Demonstrating that class objects can be assigned to each other using memberwise assignment

#include<iostream>
#include"Date.h"
using std::cout; using std::endl;

int main () {
    Date date1{6,4,2021};
    Date date2; //date 2 defaults to 1/1/2000

    cout<<"date1= "<<date1.toString()<<"\ndate2= "<<date2.toString()<<"\n\n";
    
    date2=date1;

    cout<<"After default memberwise assignment, date2 = "<<date2.toString()<<endl;
}