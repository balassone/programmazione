//readfile.cpp
#include<iostream>
#include<fstream> //file stream
#include<iomanip>
#include<string>
#include<cstdlib>
using std::ifstream;
using std::ios;
void outputLine(int, const std::string&, double); //prototype

int main(){
    //ifstream constructor opens the file
    ifstream inClientFile("clients.txt", ios::in);

    //exit program if ifstream could not open the file
    if(!inClientFile){
        exit(EXIT_FAILURE);
    }

    std::cout<<std::left<<std::setw(10)<<"Account"<<std::setw(13)<<"Name"<<" Balance\n"<<std::fixed<<std::showpoint;

    int account;
    std::string name;
    double balance;

    //display each record in file
    while (inClientFile>>account>>name>>balance){
        outputLine(account, name, balance);
    }
}
//display single record from file
void outputLine(int account, const std::string& name, double balance){
    std::cout<< std::left<<std::setw(10)<<account<<std::setw(13)<<name<<std::setw(7)<<std::setprecision(2)<<std::right<<balance<<std::endl;
}


