//readingfile.cpp
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib> //for exit function
#include<iomanip>
using std::ifstream;
using std::ios;

void outputLine(int, const std::string&, const std::string&, double);

int main() {
    ifstream inClientFile("clients.txt", ios::in);
    if (!inClientFile){
        std::cerr<<"File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }

    int account;
    std::string lastName;
    std::string firstName;
    double balance;

    while (!inClientFile.eof()){
        inClientFile>>account>>lastName>>firstName>>balance;
        outputLine(account, lastName, firstName, balance);
    }
}

void outputLine(int acc, const std::string& last, const std::string& first, double bal){
    std::cout<<std::left<<std::setw(10)<<acc<<std::setw(13)<<last<<std::setw(13)<<first
    <<std::right<<std::showpoint<<std::fixed<<std::setprecision(2)<<bal<<std::endl;
}