#include <iostream>
#include <fstream> //includo la libreria per redirigere il flusso di in/out
#include <string>
using std::ofstream; //classe che mi serve per scrivere sul file
using std::ios; //serve per specificare il tipo di operazione che devo effetturare sul file
using std::cerr;
using std::endl;
using std::string;
using std::cin;
using std::cout;


int main(){
    ofstream outFile; //definisco un oggetto outFile della classe ofstream
    outFile.open("File.txt",ios::out); //con open creo il collegamento tra il programma ed il file di nome File.txt
    //ios::out specifica il tipo di operazione che sto effettuando (scrittura sequenziale)

    if(!outFile){ //verifico se l'accesso al file è stato effettuato con successo
        cerr<<"Non è stato possibile accedere al file"<<endl;
        exit(EXIT_FAILURE); //exit termina il programma e restituisce al SO un valore diverso da 0 (EXIT_FAILURE) per
                            //indicare che l'accesso non è andato a buon fine; 
    }

    string nome;
    string cognome;
    int eta;

    cout<<"Inserisci nome,cognome ed età: "<<endl;
    while(cin>>nome>>cognome>>eta){ //mentre non è stato premunto Ctrl+D
        //inserisci il nome //inserisci il cognome//inserisci l'età
        outFile<<nome<<"\t"<<cognome<<"\t"<<eta<<endl; //scrivi sul file
    }

    outFile.close(); //Una volta terminato è buona norrma chiudere il collegamento tra il programmaed il file
}