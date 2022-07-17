/*
Una fabbrica di mobili che produce tavoli deve mantere l’inventario dei piani di appoggio.
class Piano:
Ogni piano di appoggio porta delle informazioni sul 
    colore (codice intero),
    sul tipo di legno (stringa),
    sul forintore (stringa),
    il prezzo (float)  per centimetro quadrato. 
    
I piani di appoggio possono essere di tre tipi
    rotondi,
    rettangolari o 
    triangolari.
:class Rotondo, Rettangolare, Triangolare

Quelli rettangolari avranno una base e un’altezza, cosi’ come quelli triangolari,
mentre per quelli rotondi dovremo rappresentare il raggio.

L’elenco dei piani di appoggio e’ mantenuto in una lista (di puntatori a Piani) ordinata per area (funzione membro della classe) 
del piano di appoggio. 
Ogni volta che si produce un nuovo piano esso viene aggiunto alla lista nella posizione opportuna.


Implementare:
Le strutture  dati  per la rappresentazione  delle informazioni relative ai piani di appoggio
La funzione insertTable() che inserisce un piano di appoggio nella lista (addOrder)
La funzione summarizeWharehouse()che calcola la somma dei prezzi di tutti i piani di appoggio della lista

*/
#include "LinkedList.h"

#include <iostream>
//#include "Fabbrica.h"
#include "Piano.h"

using std::cin;
using std::cout;
using std::endl;
void insertTable(LinkedList<Piano*>& l, Piano* const p);
int main(){
    //Fabbrica f;
    Rotondo a(0,"Pino", "Divani",50,1);
    Rotondo d(1,"Sciao","Lesgo",60,2);
    Rettangolare b(1,"Quercia","Poltrone",200,3,5);
    Triangolare c(2,"Abete","Ske",15,2,10);
    LinkedList<Piano*> al;
    insertTable(al,&a);
    insertTable(al,&b);
    //insertTable(al,&c);
    //insertTable(al,&d);
    cout << al[0]->toString();
    return 0;
}

void insertTable(LinkedList<Piano*>& l, Piano* const p){
    if(l.isEmpty()){
        l.addFront(p);
    } else{
        for(int i=0; i<l.getLength(); i++){
            if(l[i]>p){
                l[i]=p;
                break;
            }
        }
    }
}