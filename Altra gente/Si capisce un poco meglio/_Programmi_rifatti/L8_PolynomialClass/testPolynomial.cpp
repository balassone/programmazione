//testPolynomial.cpp

#include<iostream>
#include"Polynomial.h"

using std::cout; using std::endl;

int main() {
    double a[] = {1.1, 2.2, 3.3, 4.4};
    Polynomial p1(a,4);
    Polynomial p2(p1);
    cout<<"p1 is: "<<p1<<endl<<"p2 is: "<<p2<<endl;

    Polynomial p3 = p1+p2;
    cout<<"p3 = p1 + p2 is: "<<p3<<endl;
    p1+=p3;
    cout<<"p1+=p3 is: "<<p1<<endl<<"p2 is: "<<p2<<endl<<"p3=p1+p2 is: "<<p3<<endl;
    double a4[] = {3,3,3,3,3};
    Polynomial p4{a4,5};
    cout<<"p4 is: "<<p4<<endl;
    p4+=Polynomial(8);
    cout<<"p4 after sum with constant polynomial '8': "<<p4<<endl;

    Polynomial p5 = p4*0.5;
    Polynomial p6 = 4*p5;
    cout<<"p5 and p6, that use overloaded * (p5=p4*0.5 and p6=4*p5)"<<endl<<"p5: "<<p5<<endl<<"p6: "<<p6<<endl;

    if (p4 == p4){
        cout<<"p4 == p4"<<endl;
    }
    if (p4 == p6) {
        cout<<"p4 == p6"<<endl;
    }

    double b[] = {1,2,3,4};
    double b2[] = {2,3};
    Polynomial p7{b,4};
    Polynomial p8{b2,2};
    Polynomial p9 = p7*p8;
    cout<<"p7 is: "<<p7<<"\np8 is: "<<p8<<endl<<"p9 = p7*p8 is: "<<p9<<endl;
    
    return 0;
}