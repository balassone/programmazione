#include "Data.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    Data d1{3,5,2020};
    Data d2{24,7,2019};

    cout<<"la data d1 è: "<<d1<<endl;
    cout<<"La data d2 è: "<<d2<<endl;
    Data d3=d1+7;
    cout<<"La somma tra d1 e 7 è: "<<d3<<endl;
    Data d4=20+d2;
    cout<<"La somma tra 20 e d2 è: "<<d4<<endl;
    if(d1<d2){
        cout<<"d1 è minore di d2"<<endl;
    }
    else{
        cout<<"d1 è maggiore di d2"<<endl;
    }
    if(d1!=d2){
        cout<<"d1 è diverso da d2"<<endl;
    }
    else{
        cout<<"d1 è uguale a d1"<<endl;
    }
    d1+=4;
    cout<<"d1+=4 :"<<d1<<endl;;
    d2.operator++();
    cout<<"d2++ :"<<d2<<endl;

    Data d5=d1-20;
    cout<<"d1-20: "<<d5;




}