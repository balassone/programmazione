//matrixDriver.cpp

#include <iostream>
#include "Matrix.h"
#include <stdexcept>


using namespace std;

int main(){
    double** matriciana = new double*[3];
    for(int i=0; i<3;i++){matriciana[i] = new double[3];}
    for(int i=0; i<3;i++){for(int j=0; j<3; j++){matriciana[i][j]=1+i+j;}}

    double** mammeta = new double*[3];
    for(int i=0; i<3;i++){mammeta[i] = new double[3];}
    for(int i=0; i<3;i++){for(int j=0; j<3; j++){mammeta[i][j]=1;}}

    Matrix amatriciana(3,3,matriciana);
    Matrix ammammeta(3,3,mammeta);

   
    ammammeta.print();
    amatriciana.print();
    Matrix boi = ammammeta * amatriciana;
    boi.print();
    Matrix boi2 = amatriciana - ammammeta;
    boi2.print();
    Matrix boi3 = amatriciana + ammammeta;
    boi3.print();

    double** matriciana2 = new double*[3];
    for(int i=0; i<3;i++){matriciana2[i] = new double[2];}
    for(int i=0; i<3;i++){for(int j=0; j<2; j++){matriciana2[i][j]=1+i+j;}}
    double** mammeta2 = new double*[2];
    for(int i=0; i<2;i++){mammeta2[i] = new double[3];}
    for(int i=0; i<2;i++){for(int j=0; j<3; j++){mammeta2[i][j]=1;}}


    Matrix amatriciana2(2,3,matriciana);
    Matrix ammammeta2(3,2,mammeta);
    ammammeta2.print();
    amatriciana2.print();
    Matrix boi4 = ammammeta2 * amatriciana2;
    boi4.print();
    Matrix boi5 = amatriciana2 * ammammeta2;
    boi5.print();

    cout << "\n\n element" <<boi5[0][1];
    /*
    Matrix boi6 = amatriciana * amatriciana2; //excepion 1: missmatch for * operator
    boi6 = amatriciana + amatriciana2; //exception 2: missmatch for + operator
    */

}