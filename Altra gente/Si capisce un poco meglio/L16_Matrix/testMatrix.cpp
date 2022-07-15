//testMatrix.cpp
#include"Matrix.h"
#include<iostream>
#include<cstdlib>
using std::cout; using std::endl;

int main(){
    int r=4;
    int c=4;
    Matrix A(r,c);
    Matrix B(r,c);
    Matrix C(r,c);
    srand(1);
    for (int i=0; i<r; i++){
        for (int j=0;j<c;j++){
            A.setValue(i,j,1.1);
            B.setValue(i,j,static_cast<double> (rand()%100)/100); //rand()%100 è un intero tra 0 e 100;
                                                                  //divido per 100 così per ottenere un numero tra
                                                                  //0 ed 1 e però prima devo fare una conversione 
                                                                  //da int a double perché se no otterrei sempre 0
        }
    }
    cout<<"Matrix A "<<endl;
    for (int i=0; i<r;i++){
        for (int j=0; j<c; j++) {
            cout<<A.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix B"<<endl;
    for (int i=0; i<r; i++){
        for (int j=0;j<c;j++) {
            cout<<B.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    
    cout<<"Matrix C before addition"<<endl;
    
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++) {
            cout<<C.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }

    C=A+B;

    cout<<"Matrix C after addition"<<endl;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++) {
            cout<<C.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }

    Matrix D=A*B;
    cout<<"Matrix D after multiplication"<<endl;
    for (int i=0; i<r; i++){
        for (int j=0; j<r; j++){
            cout<<D.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
}