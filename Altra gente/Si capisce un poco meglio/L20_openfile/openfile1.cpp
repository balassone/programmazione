//openfile1.cpp 
//Creating a sequential file
#include<iostream>
#include<string>
#include<fstream> //contains file stream processing types
#include<cstdlib> //exit function prototype
using std::ofstream;
using std::ios;

int main() {
    //ofstream constructor opens file
    ofstream outClientFile{"clients.txt", ios::out};

    //ofstream outClientFile;
    //outClientFile.open("clients.txt", ios::out);
    
    //exit program if unable to create file
    if(!outClientFile){ //overloaded operator !
        std::cerr<<"File could not be opened"<<std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout<<"Enter the account, name and balance.\n"
    <<"Enter end-of-file to end input.\n? ";

    int account;
    std::string name;
    double balance;

    //read account, name and balance from cin, then place in file
    while (std::cin>>account>>name>>balance){
        outClientFile<<account<<' '<<name<<' '<<balance<<std::endl;
        std::cout<<"?";
    }
    
    outClientFile.close(); 
}