#include "matrice.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

int main(){
    int r=4;
    int c=4;
    Matrice m1(r,c);
    Matrice m2(r,c);
    srand(static_cast<unsigned int>(time(0))); //per passare da un double ad un int, abbiamo bisogno di uno static cast
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            m1.setMatrice(i,j,static_cast<double>(rand()%100)/100);
            m2.setMatrice(i,j,static_cast<double>(rand()%100)/100);
            //rand()%100 è un numero intero compreso tra 0 e 99. Diviso 100 da un numero compreso tra 0 e .0.99;
            //ho dovuto fare uno static cast perchè altrimenti avrei ottenuto sempre 0
        }
    }
    cout<<"\nLa matrice m1 è: "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<m1.getMatrice(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nLa matrice m2 è: "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<m2.getMatrice(i,j)<<"\t";
        }
        cout<<endl;
    }

    Matrice m3=m1+m2;

    cout<<"\nm1+m2: "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<m3.getMatrice(i,j)<<"\t";
        }
        cout<<endl;
    }

    Matrice m4=m1-m2;

    cout<<"\nm1-m2: "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<m4.getMatrice(i,j)<<"\t";
        }
        cout<<endl;
    }

    Matrice m5=m1*m2;

    cout<<"\nm1*m2: "<<endl;
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            cout<<m5.getMatrice(i,j)<<"\t";
        }
        cout<<endl;
    }
}
