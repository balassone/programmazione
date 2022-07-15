//testPolynomial.cpp

#include<iostream>
#include"Polynomial.h"

using std::cout; using std::endl;

int main() {

    double a[] = {1.1, 2.2, 3.3, 4.4};
    Polynomial p1{a,4};
    Polynomial p2(p1);
    cout<<"p1 is "<<p1<<endl<<"p2 is "<<p2<<endl;

    Polynomial p3=p1+p2;
    p1+=p3;
    cout<<"p1 is "<<p1<<endl<<"p3 is "<<p3<<endl;

    double a4[] = {3,3,3,3,3};
    Polynomial p4(a4,5);
    cout<<p4<<endl;
    p4+=Polynomial(8);
    cout<<p4<<endl;

    Polynomial p5 = p4*0.5;
    Polynomial p6 = 4*p4;
    cout<<p5<<endl<<p6<<endl;
}