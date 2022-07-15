//createNewFile.cpp
#include<fstream>
#include"Articolo.h"
#include<iostream>
#include<cstdlib>
using std::cout; using std::cerr; using std::endl;
using std::ofstream;
using std::ios;


int main() {
    ofstream emptyFile("hardware.dat", ios::out | ios::binary);
    if(!emptyFile){
        cerr<<"File could not be opened"<<endl;
        exit(EXIT_FAILURE);
    }
    Articolo articolo;
    emptyFile.seekp(0);
    for (int i=0; i<100; i++){
        emptyFile.write(reinterpret_cast<const char*>(&articolo), sizeof(Articolo));
    }
    emptyFile.close();
}