/*Utilizzando tecniche di elaborazione dei file ad accesso casuale, creare un
programma di elaborazione del credito in grado di memorizzare al massimo 100
record a lunghezza fissa per un'azienda che può avere fino a 100
clienti. Ogni record dovrebbe consistere in un numero di conto
che funge da chiave di registrazione, un cognome, un nome e
un saldo. Il programma dovrebbe essere in grado di aggiornare un account,
inserisci un nuovo account, elimina un account e inserisci tutti i
record dell'account in un file di testo formattato per la stampa.*/

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


int main(){
    int x;
    string nome;
    string cognome;
    double saldo;
    string req;

    ofstream file;
    file.open("file.txt",ios::out | ios::binary);
    if(!file){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }

    Account account{};

    //Fase di inizializzazione: vengono creati 100 record della classe account 
    for(int i=0;i<100;i++){
        file.write(reinterpret_cast<char*>(&account),sizeof(Account))<<"\t";
    }

    //Fase di scrittura
    do{
        cout<<"Quale account vuoi modificare? (Inserisci il numero dell'account)"<<endl;
        cin>>x;
        while(x<1 || x>100){
            cout<<"L'account inserito non è valido"<<endl;
            cout<<"Inserisci un altro account"<<endl;
            cin>>x;
        }
    
        cout<<"Inserisci il nome,il cognome ed il saldo."<<endl;
        cout<<"Nome: ";
        cin>>nome;
        cout<<"Cognome: ";
        cin>>cognome;
        cout<<"Saldo: ";
        cin>>saldo;
        Account a1{x,nome,cognome,saldo};
        file.seekp(sizeof(Account)*(a1.getNumeroConto()-1));
        file.write(reinterpret_cast<char*>(&a1),sizeof(Account));
        cout<<"\n\nVuoi inserire un altro account?"<<endl;
        cin>>req;
    }
    while(req=="si");

    file.close();

}
