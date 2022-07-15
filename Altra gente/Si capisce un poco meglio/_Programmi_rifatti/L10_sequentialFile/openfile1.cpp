//openfile1.cpp
//Creating a sequential file
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib> //for exit function
using std::ofstream;
using std::ios;

int main() {
    ofstream outClientFile ("clients.txt", ios::out);

    if (!outClientFile) {
        std::cerr<<"File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout<<"Enter the account, name (last and first) and balance.\n"
    <<"Enter end-of-file to end input.\n?";

    int account;
    std::string lastName;
    std::string firstName;
    double balance;

    while (std::cin>>account>>lastName>>firstName>>balance) {
        outClientFile<<account<<' '<<lastName<<' '<<firstName<<' '<<balance<<std::endl;
        std::cout<<"?"<<std::endl;
    }

}