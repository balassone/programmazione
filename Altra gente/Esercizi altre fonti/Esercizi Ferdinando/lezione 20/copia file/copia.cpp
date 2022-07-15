#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cerr;
using std::endl;

int main(){
    int lunghezza=0;
    char* record=nullptr; //definisco un puntatore a caratteri e lo inizializzo con il puntatore nullo

    ifstream inFile;
    inFile.open("testo.txt",ios::in); //quando apro il file in lettura, il puntatore get si trova all'inizio

    if(!inFile){
        cerr<<"Non è stato possibile accedere al file testo.txt"<<endl;
        exit(EXIT_FAILURE);
    }

    inFile.seekg(0,ios::end); //sposto il puntatore get alla fine del file
    lunghezza=inFile.tellg(); //inFile.tellg() mi da la lunghezza in byte del file
    inFile.seekg(0,ios::beg); //sposto il puntatore get nuovamente all'inizio del file
    record=new char[lunghezza]; //alloco lo spazio in memoria per contenere il contenuto del file
    inFile.read(record,lunghezza); //leggo tutto il file 
    //il file viene visto dal compilatore c++ come una sequenza di byte e quindi come una sequenza di char(ogni char è un byte)

    ofstream outFile;
    outFile.open("testo_copia.txt",ios::out); //creo un file per copiare il contenuto di testo.txt

    if(!outFile){
        cerr<<"Non è stato possibile accedere al file testo_copoa.txt"<<endl;
        delete[] record; //prima di uscire dal programma devo deallocare lo spazio in memoria
        exit(EXIT_FAILURE);
    }
    outFile.write(record,lunghezza);
    delete[] record;

    inFile.close();
    outFile.close();


}