//Employee.cpp
//Abstract-base-class Employee member-function definitions
//Note: No definitions are given for pure virtual functions

#include"Employee.h"
using std::string;

//constructor
Employee::Employee(const string& first, const string& last, const string& ssn) : firstName(first), lastName(last), SocialSecurityNumber(ssn){}

//set first name
void Employee::setFirstName(const string& first){
    firstName=first;
}
string Employee::getFirstName() const{
    return firstName;
}
void Employee::setLastName(const string& last){
    lastName=last;
}
string Employee::getLastName() const{
    return lastName;
}
void Employee::setSocialSecurityNumber(const string& ssn){ //should be validated
    SocialSecurityNumber=ssn;
}
string Employee::getSocialSecurityNumber() const{
    return SocialSecurityNumber;
}
string Employee::toString() const{
    return getFirstName() + " "+getLastName()+"\nSocial Security Number: "+getSocialSecurityNumber();
}