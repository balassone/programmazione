#include "Orario.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(){
    Orario o1{18};
    Orario o2{22,15,59};

    cout<<"L'orario o1 è: "<<endl;
    cout<<"formattazione universale: "<<o1.getUniversalOrario()<<endl;
    cout<<"formattazione americana: "<<o1.getAmericanOrario()<<endl;

    cout<<"\nL'orario o2 è: "<<endl;
    cout<<"formattazione universale: "<<o2.getUniversalOrario()<<endl;
    cout<<"formattazione americana: "<<o2.getAmericanOrario()<<endl;


}