#include <string>
#include <vector>
#include "Persona.h"
#include "Matrix.h"
#ifndef COMMUNITY_H
#define COMMUNITY_H
class Community{
    public:
        explicit Community(const int& n=0); //Chiede al sistema operativo di allocare un vettore di N elementi (inizialmente blank) e la matrice di adiacenza NxN con i valori opportuni
        Community& addPersona(const Persona&); //Aggiungo un oggetto di tipo persona al vettore P
        std::string printPeople() const; //Stampo tutte le persone
        std::string printMatrix() const; //Stampo la matrice delle amicizie.
        std::string printMidAge() const; //Stampo l'età media delle amicizie.
    private:
        int N;
        std::vector<Persona> P;
        Matrix amicizie;
};
#endif