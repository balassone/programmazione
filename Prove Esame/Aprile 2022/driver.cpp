/*
Una grande azienda di accoglienza turistica gestisce un insieme di alberghi. 
Ogni albergo ha un nome, una categoria (due, tre, quattro, cinque stelle), un prezzo unitario della camera e una lista di prenotazioni. 
Ogni prenotazione contiene il nome del cliente, il codice della carta di credito e la data della prenotazione (assimiamo che tutte le prenotazioni siano di una notte sola). 
La lista delle prenotazioni viene mantenuta in ordine di data. 
L’insieme degli alberghi viene mantenuto in un vettore ordinato un base al numero di prenotazioni (decrescente).


Implementare:
●	Le strutture  dati  per la rappresentazione  delle informazioni relative agli albergli e alle prenotazioni
●	La funzione insert_booking che prende in ingresso nome del cliente, il  numero di carta di crediti, la data della prenotazione e la categoria selezionata, e inserisce la prenotazione nel primo albergo (secondo l’ordine del vettore) di quella categoria che ha quella data libera. 

*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Date.h"
#include "Prenotazione.h"
#include "Albergo.h"
#include "Azienda.h"
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int main(){
    vector<Albergo> v;
    Albergo a("Star Hotel",4,50);
    Albergo b("Frank Hotel",2,15);
    Albergo c("Luxury Hotel",5,200);
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    Azienda hotels(v);
    //cout << hotels.toString();
    Date today(16,7,2022);
    Date tomorrow(17,7,2022);
    hotels.insert_booking("Francesco Balassone","1234",today,4);
    hotels.insert_booking("Luca Stok","5678",today,5);
    hotels.insert_booking("Ceccarellis","9101",tomorrow,4);
    cout << endl << endl;
    cout << hotels.toString();
    return 0;
}