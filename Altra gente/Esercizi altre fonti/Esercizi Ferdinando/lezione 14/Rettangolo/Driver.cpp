#include "Rettangolo.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    Punto p1{3.0,2.0};
    Punto p2{7.0,2.0};
    Punto p3{3.0,8.0};
    Punto p4{7.0,8.0};
    Rettangolo rettangolo{p1,p2,p3,p4};

    cout<<"Il rettangolo ha :"<<endl;
    cout<<"Base: "<<rettangolo.baseRettangolo()<<endl;
    cout<<"Altezza: "<<rettangolo.altezzaRettangolo()<<endl;
    cout<<"Perimetro: "<<rettangolo.perimetroRettangolo()<<endl;
    cout<<"Area: "<<rettangolo.areaRettangolo()<<endl;
    if(rettangolo.quadrato()){
        cout<<"\nIl rettangolo è un quadrato"<<endl;
    }
    else{
        cout<<"\nIl rettangolo non è un quadrato"<<endl;
    }
}