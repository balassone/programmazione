/*
Vogliamo rappresentare i rapporti sociali (amicizia)  in una comunità di N persone. 
Ogni persona e’ rappresentata con 
    identificativo (un intero da 0 a N-1),  
    un nome, 
    un cognome, 
    indirizzo (stringa), 
    eta’ (intero).

Manteniamo l’insieme delle persone  in un vettore P in maniera tale che la persona con identificativo i è memorizzato nella posizione i-ma del vettore. 
Le informazioni sulle amicizie sono contenute in un file (friends.txt) organizzato con una coppia di interi su ogni riga (es.):
0 3
4 7
1 2
…

Ogni coppia (x,y) rappresenta l’amiciza fra x e y, e simmetricamente fra y e x, 0<= x, y <= N-1. 
Data una comunità di N persone, la matrice di adiacenza delle amicizie è una matrice A (simmetrica), di dimensioni  NxN, di 0 e 1, 
un cui A[i][j] = 1 rappresenta che la persona con identificativo i e’ amico della persona con identificativo j.  
A[i][j] = 0 invece rappresenta che le due persone i e j non hanno un rapporto di amicizia.

Implementare le strutture dati per rappresentare la comunità delle N persone  e la matrice di adiacenza delle amicizie.

Scrivere un programma che:
Inizializza, il vettore delle persone nella comunità 
Legge  le amicizie dal file 
Costruisce la matrice di adiacenza delle amicizie
Stampa per ogni persona l’età media dei suoi amici.
*/

#include <iostream>
#include "Persona.h"
#include "Community.h"

using std::cout;
using std::endl;

int main(){
    int N{10}; //Inizializzo N
    //Inizializzo N persone
    Persona a(0,"Steve","Jobs","USA",40);
    Persona b(1,"Tim","Cook","USA",60);
    Persona c(2,"Elon","Musk","USA",50);
    Persona d(3,"Jeff","Bezos","USA",34);
    Persona e(4,"Giorgio","Armani","USA",50);
    Persona f(5,"Mark","Zuckerberg","USA",30);
    Persona g(6,"Bill","Gates","USA",60);
    Persona h(7,"Michael","Jackson","USA",50);
    Persona i(8,"Steve","Wozniak","USA",50);
    Persona j(9,"Mark","Wahlberg","USA",30);
    //Invoco il costruttore di am per N persone, esso inizializzerà un vettore di 10 elementi
    Community am(N);
    //Inizializzo il vettore nella comunità, se non rispettiamo l'ordine di inserimento, il vettore non dà errori in quanto inizializzato con Persona blank
    am.addPersona(a);
    am.addPersona(c); //Faccio l'addPersona in un ordine non necessariamente sequenziale: nella libreria community i dettagli.
    am.addPersona(b);
    am.addPersona(d);
    am.addPersona(e);
    am.addPersona(f);
    am.addPersona(g);
    am.addPersona(h);
    am.addPersona(i);
    am.addPersona(j);
    //Stampiamo le persone
    cout << am.printPeople();
    //Stampiamo la matrice
    cout<<am.printMatrix()<<endl;
    //Stampiamo l'età media di amici per ogni persona
    cout << am.printMidAge();
    return 0;
}