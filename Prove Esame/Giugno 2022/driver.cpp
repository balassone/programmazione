/*
L’Agenzia Europea dei Biscotti (EBA) vuole catalogare in gruppi tutti i tipi di  biscotti prodotti in Europa in base alle loro caratteristiche.
Un tipo di biscotto ha 
    un identificativo (potrebbe essere un intero fra  0 e N-1, dove N e’ il numero di tipi di biscotto), 
    un nome (stringa), 
    un produttore (stringa) 
    un vettore di 10 caratteristiche numeriche (float) che ne descrivono le proprietà che sono:
        colore, 
        peso, 
        %grassi,  
        contenuto in proteine,
        altro.
Le informazioni sono contenute in un file di testo (europeanBiscuits.txt) contenente 
    sulla prima riga il numero totale di biscotti 
    sulle righe successive le informazioni su un tipo di biscotti, es:

15
0 Gocciole Barilla 0.1 0.35 … 12.3
1 Krumiri Bistefani 0.05 0.34 … 3.2
….
14 Macine Barilla 0.1 0,2  … 1.3

I biscotti vengono mantenuti in un vettore (vettore di vettori).

Per la classificazione viene usato un parametro (float)  Epsilon,
    due biscotti sono Epsilon-simili se la distanza euclidea fra i loro vettori delle caratteristiche e’ minore di Epsilon 
    (la distanza euclidea e’ la radice quadrata della somma dei quadrati delle differenze). 

Il grafo della similarità è un vettore di N liste (di interi) in cui nella lista i-ma ci sono gli ID dei biscotti Epsilon-simili al biscotto i-mo. Es:
IMMAGINE
Nota che la relazione e’ simmetrica: se A e’ Epsilon-simile a B allora B è Epsilon-simile  ad A. 

Implementare le strutture dati per rappresentare l’insieme dei biscotti e il grafo della  Epsilon-similarità. 

Scrivere un programma che:
Legge i dati dal file 
Costruisce il grafo di similarità in base ai dati letti in ingresso
Stampa per ogni tipo di biscotto il numero di Epsilon-simili.

Facoltativo: scrivere una funzione cluster che riceve in ingresso l’id di un biscotto e stampa tutti i biscotti raggiungibili da esso attraverso il  grafo di similarità. 
Diciamo che  un elemento b è raggiungibile da un elemento a se esiste una sequenza di biscotti b0=a,b1,b2 …bk=b tali che bi è Epsilon-simile a bi+1. 
Suggerimento: è facile implementarla con una funzione ricorsiva che usa un array statico di N flag che marca gli elementi gia’ visitati e 
scorre la lista dell’elemento iniziale ricevuto in ingresso appena trova un elemento non ancora visitato lo stampa e visita la lista del nuovo elemento.

*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Azienda.h"
#include "Biscotto.h"
using std::cout;

int main(){
    Azienda az;
    az.buildGraph();
    cout << az.toString();
    return 0;
}