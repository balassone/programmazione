/*
Un’azienda di sviluppo software intende gestire i propri progetti. 
Ogni progetto 
    ha un nome (stringa), 
    un committente (stringa), 
    un importo (float), 
    una data di inizio 
    e una data di consegna del progetto. 
    Il progetto contiene inoltre una lista di tasks. 

Una task contiene 
    il nome della task, 
    la data di scadenza, 
    il numero di ore uomo (intero),  
    il riferimento al programmatore responsabile di quel task. 

La lista dei task e’ mantenuta ordinata per data di scadenza.

Per mantenuta intendiamo che ogni volta che si inserisce un task ad un progetto esso va inserito nell’ordine corretto (quindi non bisogna ordinare dopo aver inserito tutti i task).

Per ogni programmatore manteniamo 
    il nome, 
    ed il costo orario. 
    I programmatori sono contenuti in un vettore ordinato per costo.

Implementare le classi per rappresentare le varie informazioni, con le opportune funzioni membro
Implementare la funzione workloadDeveloper() che restituisce la somma delle ore uomo dei task di cui quel programmatore e’ responsabile.

*/

#include "Azienda.h"
#include "Project.h"
#include "Programmatore.h"
#include "LinkedList.h"
#include "Date.h"
#include "Task.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cin;
using std::cout;
int main(){
    Azienda acme;
    Project p;
    Task a;
    Task b;
    Task c;
    Task d;
    Programmatore pro("Francesco Balassone", 15);
    Programmatore q("Mattia Brodo", 20);
    acme.addProgrammatore(pro);
    acme.addProgrammatore(q);
    Programmatore ciao("Luca",30);
    acme.addProgrammatore(ciao);
    cout << acme.printProgrammatori();
    Date today;
    Date tomorrow;
    Date toyota;

    return 0;
}