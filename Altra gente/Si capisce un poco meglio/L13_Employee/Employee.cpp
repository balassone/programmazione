//Employee.cpp
//Employee class member-function definitions.
#include<iostream>
#include<sstream>
#include"Employee.h"
#include"Date.h"
using std::string; using std::endl;
using std::ostringstream; using std::cout;

//constructor uses member initializazer list to pass initializer values to constructors of member objects
Employee::Employee(const string& first, const string& last, const Date& dateOfBirth, const Date &DateOfHire)
    : firstName{first},
    lastName{last},
    birthDate{dateOfBirth},
    hireDate{DateOfHire} {
        //output Employee object to show when constructor is called
        cout<<"Employee object constructor: "<<firstName<<" "<<lastName<<endl;
    }
    //print Employee object
    string Employee::toString() const {
        ostringstream output;
        output<<lastName<<", "<<firstName<<"  Hired: "<<hireDate.toString()<<"  Birthday: "<<birthDate.toString();
        return output.str();
    }

    //output Employee object to show when its destructor is called
    Employee::~Employee(){
        cout<<"Employee object destructor: "<< lastName<<", "<<firstName<<endl;
    }
