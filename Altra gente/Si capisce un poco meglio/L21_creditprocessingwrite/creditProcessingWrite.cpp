//creditProcessingWrite.cpp
//writing to random-access file created in folder "creditprocessing" and copied in this folder
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"ClientData.h"
using std::fstream;
using std::ios;

int main(){
    fstream outCredit{"credit.dat", ios::in | ios::out | ios::binary};

    //exit program if fstream could not open the file
    if (!outCredit){
        std::cerr<<"File could not be opened."<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::cout<<"Enter account number (1 to 100, 0 to end input)\n?";
    
    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::cin>>accountNumber;

    //user enters informations, which are copied into file
    while(accountNumber>0 && accountNumber<=100){
        std::cout<<"Enter last name, first name and balance\n?";
        std::cin>>lastName;
        std::cin>>firstName;
        std::cin>>balance;

        //create ClientData object
        ClientData client{accountNumber, lastName, firstName, balance};

        //seek position in file of user-specified record
        //qui capiamo in che posizione andare a scrivere poizionando il puntatore put nella posizione opportuna
        outCredit.seekp((client.getAccount()-1) * sizeof(ClientData));

        //write user-specified information in file
        //qui scriviamo 
        outCredit.write(reinterpret_cast<const char*> (&client), sizeof(ClientData));

        //enable user to enter another account
        std::cout<<"Enter a number\n?";
        std::cin>>accountNumber;
    }
    outCredit.close();
}