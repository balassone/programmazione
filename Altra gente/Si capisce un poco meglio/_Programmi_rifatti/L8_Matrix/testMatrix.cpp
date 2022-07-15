//testMatrix.cpp
#include"Matrix.h"
#include<iostream>
using std::cout; using std::endl;

int main() {
    Matrix m1 (3,2);
    m1.setValue(0,0,1.0);
    m1.setValue(0,1,4.0);
    m1.setValue(1,0,5.0);
    m1.setValue(1,1,6.0);
    m1.setValue(2,0,2.0);
    m1.setValue(2,1,3.0);

    Matrix m2 (2,3);
    m2.setValue(0,0,0.0);
    m2.setValue(0,1,1.0);
    m2.setValue(0,2,2.0);
    m2.setValue(1,0,3.0);
    m2.setValue(1,1,2.0);
    m2.setValue(1,2,1.0);

    cout<<"\nm1 is:\n"<<endl;
    for (int i=0; i< 3; i++){
        for (int j=0; j<2; j++){
            cout<<m1.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
    cout<<"\nm2 is:\n"<<endl;
    for (int i=0; i< 2; i++){
        for (int j=0; j<3; j++){
            cout<<m2.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }  
    Matrix m3=m1*m2;
    
    cout<<"\nm3 = m1 * m2 is:\n"<<endl;
    for (int i=0; i< 3; i++){
        for (int j=0; j<3; j++){
            cout<<m3.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }

    Matrix m4;
    cout<<"\nm4 is:\n"<<endl;
    for (int i=0; i< 3; i++){
        for (int j=0; j<3; j++){
            cout<<m4.getValue(i,j)<<"\t";
        }
        cout<<endl;
    }
}

