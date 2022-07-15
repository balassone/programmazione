#include <iostream>
#include <vector>
#include "Venditore.h"
#include "Salariato.h"
#include "Anziano.h"
#include "Data.h"
using std::cout;
using std::endl;
using std::vector;

void StampaInformazioni(Impiegato& i){ //up-casting --> dynamic binding
    cout<<i.informazioni()<<endl;
}

int main(){
    Data v1{16,0,1997};
    Data s1{2,4,2000};
    Data a1{22,4,1985};
    Venditore v{"Ferdinando","Costigliola",v1,"Vico Fondola","3945569283","CSTFDN97M16R033S",2000,5,0.75};
    Salariato s{"Mario","D'Agostino",s1,"Via Napoli","3928845868","DGSMRA00M02R586K",1500};
    Anziano a{"Francesco","Cacciapuoti",a1,"Via Milano","3245572343","CCCFRC85M22E677M",34,4,0.5,1500};


    vector<Impiegato*> Dipendenti{}; //dichiaro un vettore "Dipendenti" di puntatori ad Impiegato e lo inizializzo a 0

    Dipendenti.push_back(&v);
    Dipendenti.push_back(&s);
    Dipendenti.push_back(&a);

    cout<<"Le informazioni sugli impiegati sono:\n "<<endl;
    for(Impiegato* i: Dipendenti){
        Anziano* x=dynamic_cast<Anziano*>(i); //Dynamic_cast per effetturare il down-casting
        if(x!=nullptr){
            (*x).setStipendioBase((*x).getStipendioBase()+0.1*((*x).getStipendioBase()));
            //faccio puntare x, che è un puntatore alla classe Anziano, alla funzione membro setStipendioBase per modificarne il valore
            //In maniera analoga potevo fare:
            // x->setStipendioBase(x->getStipendioBase()+0.1*(x->getStipendioBase()));
        }
        StampaInformazioni(*i);
    }






}
