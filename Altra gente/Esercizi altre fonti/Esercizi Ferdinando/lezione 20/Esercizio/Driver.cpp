/*Scrivere un programma che consenta ad un gestore del credito di visualizzare
le informazioni sull'account per quei clienti con:
- zero credito (cioè clienti che non devono nulla alla società)
- credito negativo (cioè clienti a cui l'azienda deve denaro) 
- credito positivo (vale a dire, i clienti che devono denaro all'azienda)
• Il programma visualizza un menu e consente al gestore del credito
di scegliere una delle tre opzioni per ottenere informazioni sul credito.
L'opzione 1 produce un elenco di conti con credito zero.
L'opzione 2 produce un elenco di conti con credito negativo.
L'opzione 3 produce un elenco di conti con credito positivo.
L'opzione 4 termina l'esecuzione del programma.
L'inserimento di un'invalida opzione richiede una nuova scelta.*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::string;
using std::cerr;
using std::endl;
using std::ifstream;
using std::cout;
using std::cin;
using std::ios;

void menu();
void stampa(string&,string&,double);

int main(){
    int x;
    string req;
    string nome;
    string cognome;
    double credito;

    ifstream readFile;
    readFile.open("Testo.txt",ios::in);
    if(!readFile){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }

    do {
        menu();
        cout<<"Quale scelta vuoi effetturare? "<<endl;
        cin>>x;
        while(x<1 || x>4){
            cout<<"La scelta fatta non è tra quelle proposte."<<endl;
            cout<<"Effetturare una nuova scelta"<<endl;
            cin>>x;
        }
    
        switch (x)
        {
        case 1:
            cout<<"L'elenco dei conti con credito zero è il seguente: "<<endl;
            break;
    
        case 2:
            cout<<"L'elenco dei conti con credito negativo è il seguente: "<<endl;
            break;
        case 3:
            cout<<"L'elenco dei conti con credito positivo è il seguente: "<<endl;
            break;
        case 4:
            exit(-1);
        }

        cout<<left<<setw(15)<<"Nome"<<setw(15)<<"Cognome"<<right<<setw(5)<<"Credito"<<endl;

        while(!readFile.eof()){
            readFile>>nome>>cognome>>credito;
            if(x==1 && credito==0.0){
                stampa(nome,cognome,credito);
            }
            else if(x==2 && credito<0.0){
                stampa(nome,cognome,credito);
            }
            else if(x==3 && credito>0.0){
                stampa(nome,cognome,credito);
            }

        }

        cout<<"\n\nEcco i risultati richiesti."<<endl;
        cout<<"Vuoi effetturare un'altra operazione?"<<endl;
        cin>>req;
        cout<<endl;
        readFile.clear(); //clear() serve per abbassare tutti i flag
        readFile.seekg(0,ios::beg);
    }
    while(req=="si");

    readFile.close();

}

void menu(){
    cout<<"Menù: "<<endl;
    cout<<"1: elenco conti con credito zero"<<endl;
    cout<<"2: elenco conti con credito negativo"<<endl;
    cout<<"3: elenco conti con credito positivo"<<endl;
    cout<<"4: termina"<<endl;
}

void stampa(string& nome,string& cognome,double credito){
    cout<<left<<setw(15)<<nome<<setw(15)<<cognome<<right<<setw(5)<<credito<<endl;
}