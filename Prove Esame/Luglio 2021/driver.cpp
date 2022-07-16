/*
La città di BlueSky vuole monitorare i livelli di CO2 dell’aria della città. La città e’ divisa in quartieri secondo una matrice  20x20, ogni elemento della matrice corrisponde ad un quartiere della città. I rilevatori di CO2, mantenuti in un vettore, sono distribuiti in diversi quartieri,  le informazioni di ciascun rivelatore sono: id_station (intero), coord_x (intero), coord_y(intero) e una lista di rilevamenti mantenuta in ordine di data di rilevamento. Ogni rilevamento contiene le informazioni sulla data del rilevamento, e la quantità di CO2 in parti per milione - ppm (double).

Implementare le strutture dati per gestire le informazioni. Le classi dei rilevatori devono contenere il costruttore copia, l’operatore di assegnazione e il distruttore. 
Implementare le seguenti funzioni:
-	addMeasurement che prende in ingresso l’id del rilevatore, la data, e il livello di ppm e aggiunge questo rilevamento alla lista dei  rilevamenti di quella stazione
-	meanCO2Zone che prende in ingresso due date, d1 e d2, e le coordinate di una zona. Una zona e’ un insieme rettangolare di quartieri definiti dalle coordinate  del quartiere  in alto a sinistra e quello in basso a destra della zona. Questa funzione calcola il valore medio di ppm per tutte le stazioni di quella zona fra le date d1 e d2.
-	Un programma driver di esempio che istanzia gli oggetti e invoca le due funzioni.


Consegnare una cartella in formato compresso del tipo CognomeNome.zip (prima il cognome e poi il nome!). Il file zip contiene una cartella CognomeNome con il codice sorgente ed il relativo Makefile. Tutto il codice deve essere opportunamente documentato. Non consegnare programmi che non compilano correttamente.

*/

#include <iostream>
#include <vector>
#include <list>
#include "City.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
int main(){
    
    return 0;
}

