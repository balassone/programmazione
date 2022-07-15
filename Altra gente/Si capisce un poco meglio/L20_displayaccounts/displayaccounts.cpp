//displayaccounts.cpp
//Credit inquiry program.
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
using std::cerr; using std::cout;
using std::cin; using std::endl;
using std::ifstream; using std::ofstream; using std::ios;

int getRequest();                                       //display the menu and gets the choice
bool shouldDisplay(int, double);                        //decide if balance corresponds to the choice
void outputLine(int, const std::string&, double);       //prints the current record

int main() {
    //ifstream constructor opens the file
    ifstream inClientFile{"clients.txt",ios::in};

    //exit program if instream could not open the file
    if(!inClientFile){
        cerr<<"File could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }
    
    //get user's request (0, credit or debit balance)
    int request{getRequest()}; 
    while (request!=4){
        switch (request) {
            case 1:
            cout<<"\nAccounts with zero balance:\n";
            break;
            case 2:
            cout<<"\nAccounts with debit balance:\n";
            break;
            case 3:
            cout<<"\nAccounts with credit balance:\n";
            break;
        }
        int account;
        std::string name;
        double balance;

        //read account, name and balance from file

        //display the contents (until eof)
        while (!inClientFile.eof()){
        //read account, name and balance from file
        inClientFile>>account>>name>>balance;
        //display record
        if (shouldDisplay(request, balance)) {
            outputLine(account, name, balance);
            }
        }
        inClientFile.clear(); //resest eof for next input
        inClientFile.seekg(0); //reposition to the beginning of file
        request=getRequest(); //get additional request from user
    }
    
    cout<<"End of run"<<endl;
}

int getRequest() {
    //display request options
    cout<<"Enter request\n"
    <<"1 - List accounts with zero balance\n"
    <<"2 - List accounts with credit balance\n"
    <<"3 - List accounts with debit balance\n"
    <<"4 - End of run"<<std::fixed<<std::showpoint;

    int type;

    do {    //input user's request
        cout<<" \n? ";
        cin>>type;
    }
    while (type < 1 || type > 4);
    return type;
}
bool shouldDisplay(int type, double balance){
    if(type==1 && balance==0){
        return true;
    }
    if (type==2 && balance<0){
        return true;
    }
    if (type==3 && balance>0){
        return true;
    }
    return false;
}
//display single record from file
void outputLine(int account, const std::string& name, double balance){
    cout<<std::left<<std::setw(10)<<account<<std::setw(13)<<name
    <<std::setw(7)<<std::setprecision(2)<<std::right<<balance<<endl;
}