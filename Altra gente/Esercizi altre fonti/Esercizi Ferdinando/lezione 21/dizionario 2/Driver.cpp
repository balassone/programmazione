/* Implementa un semplice dizionario che traduce le parole inglesi in italiano.
Il programma dovrebbe consentire all'utente di:
- cercare ripetutamente parole inglesi da tradurre
- aggiungere nuove parole al dizionario
- visualizzare il contenuto del dizionario
- chiudere il programma 
Il dizionario dovrebbe essere scritto in un file in modo che tutte le modifiche apportate 
al dizionario siano persistenti.
-Il programma può definire una classe di voce del dizionario contenente la parola inglese e la parola italiana
-Il dizionario è memorizzato in un file di testo con una coppia di parole inglese-italiano su ogni riga
-All'avvio il programma carica il dizionario in un vettore di voci.
-Quindi il menu presenta le varie scelte all'utente
-Implementa i casi in cui il vettore del dizionario è ordinato e il caso in cui non è ordinato
-Prima di uscire il programma salva il nuovo dizionario nei file di testo */

//Implemento il caso in cui il vettore del dizionario è ordinato

#include <iostream>
#include "Dizionario.h"
#include "Dizionario.cpp"
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using std::setw;
using std::left;
using std::right;
using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::cin;
using std::cout;
using std::cerr;
using std::ios;
using std::endl;

void menu();
void ricerca(const vector<Dizionario>&);
void inserimento(vector<Dizionario>&);
void stampa(const vector<Dizionario>&);
void salva(const vector<Dizionario>&);
void quickSort(vector<Dizionario>&,int,int);
int partition(vector<Dizionario>&,int,int);
void swap(vector<Dizionario>&,int,int);
int binarySearch(const vector<Dizionario>&,string&);

int main(){
    int scelta;
    string req;
    ifstream inOutFile;
    inOutFile.open("eng_it.txt",ios::in);
    if(!inOutFile){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }

    vector <Dizionario> voci{}; //creo un vettore di puntatori alla classe dizionario
    Dizionario parola;
    string parolaIng;
    string parolaIta;

    while(!inOutFile.eof()){
        inOutFile>>parolaIng>>parolaIta;
        parola.setParolaInglese(parolaIng);
        parola.setParolaItaliana(parolaIta);
        voci.push_back(parola);
    }

    quickSort(voci,0,voci.size()-1); //Ordino il vettore in quanto non so se la lista di partenza è ordinata

    do 
    {
        menu();
        cin>>scelta;
        while(scelta<1 || scelta >4){
            cout<<"La scelta fatta non è tra quelle proposte"<<endl;
            cout<<"Effettua una nuova scelta: "<<endl;
            cin>>scelta;
        }

        switch (scelta)
        {
        case 1:
            cout<<"Cerca la traduzione di una parola inglese"<<endl;
            break;
        case 2:
            cout<<"Aggiungi una nuova parola al dizionario"<<endl;
            break;
        case 3:
            cout<<"Visualizza il contenuto"<<endl;
            break;
        case 4:
            exit(-1);
        }

        if(scelta==1){
            ricerca(voci);
        }
        else if(scelta==2){
            inserimento(voci);
        }
        else{
            stampa(voci);
        }

        cout<<"Vuoi effettuare un'altra operazione?"<<endl;
        cin>>req;
        inOutFile.clear();
        inOutFile.seekg(0,ios::beg);    
    }
    while(req=="si");

    salva(voci);
    inOutFile.close();
}

void menu(){
    cout<<"Scegli tra le seguenti opzioni: "<<endl;
    cout<<"1: Cerca la traduzione di una parola inglese"<<endl;
    cout<<"2: Aggiungi una nuova parola al dizionario"<<endl;
    cout<<"3: Visualizza il contenuto del dizionario"<<endl;
    cout<<"4: Termina"<<endl;
}

void ricerca(const vector<Dizionario>& dict){
    string parolaIng;
    string parolaIta="";
    cout<<"Qual'è la parola inglese di cui vuoi cercare la traduzione? "<<endl;
    cin>>parolaIng;
    int pos=binarySearch(dict,parolaIng);
    if(pos==-1){
        cout<<"La parola non è presente nel dizionario"<<endl;
    }
    else{
        cout<<"La traduzione della parola cercata è: "<<dict[pos].getParolaItaliana()<<endl;
    }
}

void inserimento(vector<Dizionario>& dict){
    string parolaIng;
    string parolaIta;
    cout<<"Inserisci la parola inglese e la sua traduzione italiana:"<<endl;
    cout<<"Parola inglese: ";
    cin>>parolaIng;
    cout<<"Parola italiana: ";
    cin>>parolaIta;
    Dizionario nuovaParola{parolaIng,parolaIta};
    dict.push_back(nuovaParola);
    quickSort(dict,0,dict.size()-1);
    cout<<"L'inserimento è stato effettuato correttamente"<<endl;
}

void stampa(const vector<Dizionario>& dict){
    cout<<left<<setw(15)<<"Parola inglese"<<right<<setw(15)<<"Parola italiana"<<endl;
    for(size_t i=0;i<dict.size();i++){
        cout<<left<<setw(15)<<dict[i].getParolaInglese()<<right<<setw(15)<<dict[i].getParolaItaliana()<<endl;
    }
}

void salva(const vector<Dizionario>& dict){
    ofstream file;
    file.open("eng_it.txt",ios::out);
    if(!file){
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE);
    }
    for(size_t i=0;i<dict.size()-1;i++){
        file<<dict[i].getParolaInglese()<<"\t"<<dict[i].getParolaItaliana()<<endl;       
    }
    file<<dict[dict.size()-1].getParolaInglese()<<"\t"<<dict[dict.size()-1].getParolaItaliana();
    file.close();
}

void quickSort(vector<Dizionario>& A,int p ,int r){
    if(p<r){
        int q=partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}
 
int partition(vector<Dizionario>& A,int p,int r){
    Dizionario x=A[p];
    int i=p-1;
    int j=r+1;
    while(true){
        do{ 
            j=j-1;
        }
        while(A[j]>x);
        do{ 
            i=i+1;
        }
        while(x>A[i]);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

void swap(vector<Dizionario>& A,int i,int j){
    Dizionario temp;
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}

int binarySearch(const vector<Dizionario>& A,string& nom){
    int mid;
    int p=0;
    int r=A.size()-1;
    while(p<r){
        mid=(p+r)/2;
        if(nom==A[mid].getParolaInglese()){
            return mid;
        }
        else if(nom>A[mid].getParolaInglese()){
            p=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}
