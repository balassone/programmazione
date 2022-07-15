//testEmployee.cpp
//Demonstrating composition--an object with member objects.

#include<iostream>
#include"Date.h"
#include"Employee.h"
using std::cout;
using std::endl;

int main () {
    Date birth{26,5,1926};
    Date hire{17,8,1958};
    Employee manager{"Miles", "Davis", birth, hire};
    cout<<"\n"<<manager.toString()<<endl;
}