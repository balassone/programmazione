//testDate.cpp

#include<iostream>
#include "Date.h"
using namespace std;

int main () {
    Date d1{25,12,2020};
    Date d2;

    cout<<"d1 is "<<d1<<"\nd2 is "<<d2; //utilizzo dell'operatore di trasferimento ridefinito in Date.cpp
    cout<<"\n\nd1+=7 is "<<(d1+=7);

    d2.setDate(20,2,2008);
    cout<<"\n\nd2 is "<<d2;
    cout<<"\n++d2 is "<<++d2<< " (leap year allows 29th)";

    Date d3{13,1,2010};
    cout<<"\n\nTesting the prefix increment operator: \n"<<"d3 is "<<++d3<<endl;
    cout<<"++d3 is "<<++d3<<endl;
    cout<<"d3 is "<<d3;

    cout<<"\n\nTesting the postfix increment operator:\n"<<"d3 is "<<d3<<endl;
    cout<<"d3++ is "<<d3++<<endl;
    cout<<"d3 is "<<d3<<endl;

    std::string check=(d2<d3)? "is ":"is not ";
    cout<<"\n\nTesting relational operators:\n"<<d2<<check<<"less than "<<d3<<"\n";

    Date d4= d3+10;
    cout<<"\n\nTesting summing numberofdays\n"<<d4<<" = "<<d3<<" + 10 days"; 

}