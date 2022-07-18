/*
Un’agenzia di spedizioni deve gestire le consegne settimanali dei pacchi. 
Ogni pacco ha 
    un mittente, 
    un destinatario, 
    una data di consegna 
    un peso in kilogrammi.
    
Per ogni pacco l’agenzia riceve  un  compenso base  pari a 1 euro per ogni chilogrammo. 
Esistono poi dei pacchi relativi alle spedizioni extra-europee che oltre alle informazioni di base contengono 
    la Nazione di spedizione
    il continente.  
Per questi pacchi l’agenzia oltre al compenso base riceve €10 per le spese di dogana dei pacchi provenienti dagli Stati Uniti e €15 per tutti gli altri continenti.
Manteniamo i pacchi di questa  settimana in  una lista. 
La lista e’ mantenuta in maniera ordinata in base alla  data di consegna.  
Cioe’ ogni volta che si aggiunge  un pacco alla lista,  esso viene inserito nella posizione corretta (non bisogna ri-ordinare la lista ad ogni aggiunta!).

Implementare:
Le strutture  dati  per la rappresentazione  delle informazioni relative alle consegne dell’agenzia
La funzione  weekly_earnings() che a partire dalla lista  di pacchi calcola la sommatoria  dei comprensi
Un programma driver che  istanzia un insieme di pacchi di varie tipologie, le inserisce nella lista e invoca la funzione weekly_earnings()

*/
#include <iostream>
#include <string>
#include "Pacco.h"
#include "Extra.h"
#include "Azienda.h"
using std::cout;
using std::endl;

int main(){
    Date today(18,7,2022);
    Date tomorrow(19,7,2022);
    Date yesterday(17,7,2022);
    Extra a("eBay","Balassone",today,4,"USA","America");
    Pacco b("Amazon","Skeke",tomorrow,5);
    Extra c("Subito","Chiara",yesterday,6,"Europa","Spagna");
    Azienda az;
    az.add(&b);
    az.add(&a);
    az.add(&c);
    cout << az.toString();
    cout << az.weeklyEarnings();
    // 4+5+6+15+10=25+15=40
    return 0;
}