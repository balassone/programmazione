#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include "Matrix.h"
#include "Persona.h"
#include "Community.h"

Community::Community(const int& n): N(n), amicizie(N) {
    Persona blank;
    //Nota Bene: avrei potuto risparmiarmi di inizializzare il vettore con account bianchi, ma in tal caso sarei stato costretto a chiamare addPersona in ordine.
    //In questo modo aumento la robustezza dell'inserimento dei dati aposteriori.
    for(int i=0; i<N; ++i){
        P.push_back(blank);
    }

    std::fstream file("friends.txt",std::ios::in); //Vogliamo solo leggere il file, quindi inizializzo il file in sola lettura.
    if(!file){
        throw std::runtime_error("File not found");
    }
    int a{0}, b{0};
    while(file){
        file >> a >> b;
        //Matrice simmetrica: inverto gli indici ed effettuo la stessa operazione
        //Nota bene, ho inizializzato la matrice con gli zeri in modo da non avere problemi con i valori di default.
        amicizie.setNumber(a,b,1);
        amicizie.setNumber(b,a,1);
    }

}

Community& Community::addPersona(const Persona& p){
    //Come da traccia, l'ID corrisponde alla posizione di una persona nel vettore della community.
    P[p.getID()]=p;
    return *this;
}

std::string Community::printPeople() const {
    //Invoco toString per ogni persona.
    std::stringstream out;
    for(int i{0}; i<N; ++i){
        out << P[i] << "\n\n";
    }
    return out.str();
}

std::string Community::printMatrix() const{
    std::ostringstream out;
    out << amicizie; //In Matrix c'è l'overloading dell'operatore <<
    return out.str();
}

std::string Community::printMidAge() const{
    double mid{0};
    int count{0};
    std::ostringstream out;
    for(int i=0; i<N; ++i){
        mid=0;
        count=0;
        out << "Gli amici di " << P[i].getName() << " " << P[i].getSurname() << " hanno un'eta' media di ";
        for(int j=0; j<N; ++j){
            if(amicizie.getNumber(i,j)==1){
                mid+=P[j].getAge();
                count++;
            }
        }
        out << mid/count << " anni.\n\n"; //Dividiamo un double per un intero, otteniamo un double. Se si preferiva una media intera, basta rendere mid un intero.
    }
    return out.str();
}