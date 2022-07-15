//copia file con argomenti del main
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::cerr;
using std::ios;

int main(int argc,char* argv[]){
    if(argc!=3){
        cerr<<"Il numero di argomenti deve essere 3 e nel seguente ordine: "<<endl;
        cerr<<"nome_driver testo.txt testo_copia.txt";
        exit(EXIT_FAILURE);
    }

    int lunghezza=0;
    char* record=nullptr;

    ifstream inFile;
    inFile.open(argv[1],ios::in);
    if(!inFile){
        cerr<<"Il file "<<argv[1]<<" non può essere aperto"<<endl;
        exit(EXIT_FAILURE);
    }
    inFile.seekg(0,ios::end);
    lunghezza=inFile.tellg();
    inFile.seekg(0,ios::beg);
    record=new char[lunghezza];
    inFile.read(record,lunghezza);

    ofstream outFile;
    outFile.open(argv[2],ios::out);
    if(!outFile){
        cerr<<"Il file "<<argv[2]<<" non può essere aperto"<<endl;
        delete[] record;
        exit(EXIT_FAILURE);
    }
    outFile.write(record,lunghezza);
    delete[] record;

    inFile.close();
    outFile.close();
}