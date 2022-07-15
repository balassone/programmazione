#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::setw;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;
using std::cout;
using std::cin;
using std::left;
using std::right;

void display(Account&);
    
int main(){
    //Lettura da file binario //vogliamo stampare solo i record non vuoti
    ifstream fil;
    fil.open("file.txt", ios::in | ios::binary);
    if(!fil){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }
    Account cliente;
    cout<<left<<setw(15)<<"Numero conto"<<setw(15)<<"Nome"<<setw(15)<<"Cognome"<<right<<setw(5)<<"Saldo"<<endl;
    fil.read(reinterpret_cast<char*>(&cliente),sizeof(Account));
    while(!fil.eof()){
        if(cliente.getNumeroConto()!=0){
            display(cliente);
        }
        fil.read(reinterpret_cast<char*>(&cliente),sizeof(Account));
    }

    fil.close();


}



void display(Account& account){
    cout<<left<<setw(15)<<account.getNumeroConto()<<setw(15)<<account.getNome()<<setw(15)
    <<account.getCognome()<<right<<setw(5)<<account.getSaldo()<<endl;
}