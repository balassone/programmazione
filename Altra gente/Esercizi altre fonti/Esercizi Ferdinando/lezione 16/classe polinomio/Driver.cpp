#include <iostream>
#include "Polinomio.h"
using std::cin;
using std::cout;
using std::endl;

int main(){
    Polinomio p1{5.5};
    double coeff2[]={1.1,2.2,3.3,4.4,5.5};
    Polinomio p2{coeff2,5};
    double coeff3[]={1.1,2.2,3.3,4.4,5.5,6.6};
    Polinomio p3{coeff3,6};

    cout<<"Il polinomio p1 è: "<<p1<<endl;
    cout<<"Il polinomio p2 è: "<<p2<<endl;
    cout<<"Il polinomio p3 è: "<<p3<<endl;

    Polinomio p4;
    Polinomio p5;
    Polinomio p6;
    p4=p2+p3;
    p5=p2*10;
    p6=p1*p2;
    cout<<"p2+p3: "<<p4<<endl;
    cout<<"p2*10: "<<p5<<endl;
    /*cout<<"p1*p2: "<<p6<<endl;*/


    


}