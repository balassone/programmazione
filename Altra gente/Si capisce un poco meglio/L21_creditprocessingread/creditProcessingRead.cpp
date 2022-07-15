//creditProcessingRead.cpp
//Reading a random-access file sequentially.
#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include"ClientData.h"
using std::ostream;
using std::ifstream;
using std::ios;
void outputLine(ostream&, const ClientData&); //prototype

int main(){
    ifstream inCredit("credit.dat", ios::in | ios::binary);

    //exit program if ifstream cannot open the file
    if(!inCredit){
        std::cerr<<"File could not be opened."<<std::endl;
    }

    //output column heads
    std::cout<<std::left<<std::setw(10)<<"Account"
    <<std::setw(16)<<"Last name"
    <<std::setw(11)<<"First Name"
    <<std::setw(10)<<std::right<<"Balance\n";

    ClientData client; //create record

    //read first record from the file
    inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    //read all records from file
    while(inCredit){ //equivale a while(!inCredit.eof())
        //display record
        if(client.getAccount()!=0){
            outputLine(std::cout, client);
        }
        //read next from file
        inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
}

//display single record
void outputLine(ostream& output, const ClientData& record){
    output<<std::left<<std::setw(10)<<record.getAccount()
    <<std::setw(16)<<record.getLastName()
    <<std::setw(11)<<record.getFirstName()
    <<std::setw(10)<<std::setprecision(2)<<std::right<<std::fixed<<std::showpoint<<record.getBalance()<<std::endl;
}