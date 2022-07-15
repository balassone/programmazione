/* Gestione magazzino.
• Scrivere un programma c++ che permetta la gestione di un magazzino
• Il magazzino ha al piu’ 100 articoli diversi
• Per ogni articolo vogliamo rappresentare il codice (fra 0 e 99), 
il nome, la quantità ed il prezzo
• I dati saranno memorizzati in un file “hardware.dat”
• Il programma, una volta inizializzato l’insieme dei record, permette di:
• inserire un record
• Cancellare un record
• Aggiornare un record
• Stampare la lista di record presenti 
*/

#include "magazzino.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::setw;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::fstream;
using std::ios;
using std::left;
using std::right;

void menu();
void inserimento(fstream&);
void cancella(fstream&);
void aggiorna(fstream&);
void stampa(fstream&);

int main(){
    int x;
    string req;
    fstream inOutFile;
    inOutFile.open("hardware.txt",ios::in | ios::out | ios::binary);
    if(!inOutFile){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }
    Magazzino magazzino{};
    for(int i=0; i<100; ++i){
        inOutFile.write(reinterpret_cast<char*>(&magazzino),sizeof(Magazzino));
        //ad ogni write, il puntatore set si sposta in avanti
    }
    inOutFile.seekg(0,ios::beg);
    inOutFile.seekp(0,ios::beg);
    //Termina la fase di inizializzazione
    do{
        menu();
        cin>>x;
        while(x<1 || x>5){
            cout<<"La scelta effettuata non è valida"<<endl;
            cin>>x;
        }
        switch (x)
        {
        case 1:
            cout<<"Inserisci un nuovo record: "<<endl;
            break;
        case 2:
            cout<<"Cancella un record: "<<endl;
            break;
        case 3:
            cout<<"Aggiorna un record: "<<endl;
            break;
        case 4:
            cout<<"Stampa record presenti: "<<endl;
            break;
        case 5:
            exit(-1);
        }

        if(x==1){
            inserimento(inOutFile);
        }
        else if(x==2){
            cancella(inOutFile);
        }
        else if(x==3){
            aggiorna(inOutFile);
        }
        else{
            stampa(inOutFile);
        }

        cout<<"\n\nVuoi effettuare altre operazioni?"<<endl;
        cin>>req;
        inOutFile.seekp(0,ios::beg);
        inOutFile.seekg(0,ios::beg);
        inOutFile.clear();
    }
    while(req=="si");

    inOutFile.close();

}

void menu(){
    cout<<"Scegli tra le seguenti opzioni"<<endl;
    cout<<"1: Inserisci un nuovo record"<<endl;
    cout<<"2: Cancella un record"<<endl;
    cout<<"3: Aggiorna un record"<<endl;
    cout<<"4: Stampa i record presenti"<<endl;
    cout<<"5: Termina"<<endl;
}

void inserimento(fstream& file){
    int codice;
    string nome;
    int quantita;
    double prezzo;
    cout<<"Qual'è il codice dell'articolo da inserire?"<<endl;
    cin>>codice;
    while(codice<1 || codice>100){
        cout<<"Il codice inserito non è valido. Riprova:"<<endl;
        cin>>codice;
    }
    cout<<"\nInserisci il nome dell'articolo, la quantità ed il prezzo: "<<endl;
    cout<<"Nome: ";
    cin>>nome;
    cout<<"Quantità: ";
    cin>>quantita;
    cout<<"Prezzo: ";
    cin>>prezzo;
    Magazzino articolo{codice,nome,quantita,prezzo};
    file.seekp((articolo.getCodice()-1)*sizeof(Magazzino));
    file.write(reinterpret_cast<char*>(&articolo),sizeof(Magazzino));
}

void cancella(fstream& file){
    int codice;
    string req;
    cout<<"Qual'è l'articolo che vuoi eliminare?"<<endl;
    cout<<"Inserisci il codice dell'articolo: ";
    cin>>codice;
    while(codice<1 || codice>100){
        cout<<"Il codice inserito non è valido. Riprova:"<<endl;
        cin>>codice;
    }
    file.seekg((codice-1)*sizeof(Magazzino));
    Magazzino articolo;
    file.read(reinterpret_cast<char*>(&articolo),sizeof(Magazzino));
    cout<<"L'articolo che vuoi eliminare è il seguente? "<<endl;
    cout<<articolo.getCodice()<<" "<<articolo.getNome()<<" "<<articolo.getQuantita()<<" "<<articolo.getPrezzo()<<endl;
    cin>>req;
    if(req=="si"){
        file.seekg((codice-1)*sizeof(Magazzino));
        Magazzino annullaArticolo{};
        file.write(reinterpret_cast<char*>(&annullaArticolo),sizeof(Magazzino));
    }
}

void aggiorna(fstream& file){
    int codice;
    string nuovoNome;
    int nuovaQuantita;
    double nuovoPrezzo;
    cout<<"Quale articolo vuoi aggiornare? Inserisci il numero dell'articolo"<<endl;
    cin>>codice;
    while(codice<1 || codice>100){
        cout<<"Il codice inserito non è valido. Riprova:"<<endl;
        cin>>codice;
    }
    Magazzino articolo;
    file.read(reinterpret_cast<char*>(&articolo),sizeof(Magazzino));
    cout<<"L'articolo che vuoi aggiornare è il seguente: "<<endl;
    cout<<articolo.getCodice()<<" "<<articolo.getNome()<<" "<<articolo.getQuantita()<<" "<<articolo.getPrezzo()<<endl;
    cout<<"Nome: ";
    cin>>nuovoNome;
    cout<<"Quantità: ";
    cin>>nuovaQuantita;
    cout<<"Prezzo: ";
    cin>>nuovoPrezzo;
    articolo.setNome(nuovoNome);
    articolo.setQuantita(nuovaQuantita);
    articolo.setPrezzo(nuovoPrezzo);
    file.seekg((codice-1)*sizeof(Magazzino));
    file.write(reinterpret_cast<char*>(&articolo),sizeof(Magazzino));
}

void stampa(fstream& file){
    cout<<left<<setw(20)<<"Codice articolo"<<setw(15)<<"Nome"<<setw(15)<<"Quantità"<<right<<setw(10)<<"Prezzo"<<endl;
    Magazzino articolo;
    file.read(reinterpret_cast<char*>(&articolo),sizeof(Magazzino));
    while(!file.eof()){
        if(articolo.getCodice() != 0){
            cout<<left<<setw(20)<<articolo.getCodice()<<setw(15)<<articolo.getNome()<<setw(10)<<articolo.getQuantita()
            <<right<<setw(4)<<articolo.getPrezzo()<<endl;
        }
        file.read(reinterpret_cast<char*>(&articolo),sizeof(Magazzino)); //vado avanti di un record
        //ad ogni read, il puntatore get si sposta in avanti
    }
}