//testDate.cpp
#include"Date.h"
using std::cout; using std::endl;

int main() {
    Date d1{2,4,2020};
    Date d2{28,2,2008};

    cout<<"\nd1 is "<<d1;
    cout<<"\nd1 += 7 is "<< (d1 += 7);
    
    cout<<"\n\nd2 is "<<d2;
    cout<<"\n++d2 is "<<++d2<<" (leap year allows 29th)";

    Date d3{13,1,2010};
    cout<<"\n\nTesting prefix increment operator:\n"<<
        "d3 is "<<d3<<
        "\n++d3 is "<<++d3<<endl;
    cout<<"d3 is "<<d3;
    cout<<"\n\nTesting postfix increment operator:\n"<<
        "d3 is "<<d3<<"\nd3++ is "
        <<d3++<<endl;
    cout<<"d3 is "<<d3<<endl;

    std::string check=(d2<d3) ? " is" : " is not";
    cout<<"\n\nTesting relational operators:\n"
        <<d2<<check<<" less than "<<d3<<"\n";
    
    Date d4=d3+10;
    cout<<"\n\nTesting summing numberofdays\n"
        <<d4<<" = "<<d3<<" + 10 days\n"<<endl;
}