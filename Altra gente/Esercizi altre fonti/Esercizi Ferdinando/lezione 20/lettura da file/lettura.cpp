#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using std::string;
using std::setw;
using std::ifstream;
using std::ios;
using std::cerr;
using std::endl;
using std::cout;
using std::left;
using std::right;

void stampa(const string&,const string&,int);

int main(){

    ifstream inFile;
    inFile.open("file.txt",ios::in); //ios::in (modalità di apertura sequenziale)

    if(!inFile){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<left<<setw(15)<<"Nome"<<setw(15)<<"Cognome"<<right<<setw(2)<<"età"<<endl;

    string nome;
    string cognome;
    int eta;

    while(!inFile.eof()){
        inFile>>nome;
        inFile>>cognome;
        inFile>>eta;
        stampa(nome,cognome,eta);
    }
    inFile.close();
}

void stampa(const string& n,const string& c,int e){
    cout<<endl;
    cout<<left<<setw(15)<<n<<setw(15)<<c<<right<<setw(2)<<e<<endl;
}