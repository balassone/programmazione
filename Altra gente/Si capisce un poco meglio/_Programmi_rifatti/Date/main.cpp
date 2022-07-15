//main.cpp
#include"Date.h"
#include<iostream>
using std::cout; using std::endl;

int main() {
    Date d1 {1,3,1987};
    Date d2 {2,3,1987};
    cout<<((d1<d2) ? d1 : d2)<<" is minor date";
    cout<<"\n"<<d1<<" + 37 days = "<<d1+37;
}