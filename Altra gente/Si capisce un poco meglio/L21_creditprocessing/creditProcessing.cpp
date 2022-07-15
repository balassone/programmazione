//creditProcessing.cpp
//creating a randomly accessing file
#include <iostream>
#include<fstream>
#include<cstdlib>
#include"ClientData.h"
using std::ofstream;
using std::ios;
using std::cerr;

int main() {
    ofstream outCredit("credit.dat", ios::out | ios::binary);

    //exit program if ostream could not open the file
    if(!outCredit){
        cerr<<"File could not be opened."<<std::endl;
        exit(EXIT_FAILURE);
    }

    ClientData bankClient; //constructor zeros out each data member

    //output 100 blank records to file
    for (int i=0; i<100; i++){
        outCredit.write(reinterpret_cast<const char*> (&bankClient), sizeof(ClientData));
    }
}