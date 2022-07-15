#include <iostream>
#include <string>
#include <vector>
#include "Albergo.h"
#include "Cliente.h"
#include "LinkedList.h"
#include "Date.h"

using std::vector;
using std::cout;
using std::string;
//prototipi di funzione
void quickSort(vector<Albergo*>&A, int p, int r);
int partition(vector<Albergo*>&A, int p, int r);
void swap(vector<Albergo*>& A,int i,int j);
void sortDecrescente(vector<Albergo*>&A);
void insertBooking(const string&n, const string&card, int cat, const Date&pren,vector<Albergo*>& A); 
void vectorPrint(vector<Albergo*>& A);


int main(){
    //dichiarazione di alberghi e cliente
    vector<Albergo*>alberghi;
    LinkedList<Cliente> book;
    Albergo a1{"La Perla", 35.50, 3};
    Albergo a2{"Gli Dei", 75.00,5};
    Albergo a3{"SoleSplendente", 40.00,4};

    alberghi.push_back(&a1);
    alberghi.push_back(&a3);
    alberghi.push_back(&a2);

    Cliente c1{"Franco Dergado ", "522666444888", {22,01,2022}};
    Cliente c2{"Giovanni Lorenzo ", "669988771122", {27,05,2022}};
    Cliente c3{"Ettore Silvestro ", "332255446667", {24,03,2022}};
    Cliente c4{"Donato DelVecchio ", "778855664422", {23,01,2022}};
    Cliente c5{"Franco Tristezza ", "663322441157", {15,06,2022}};
    Cliente c6{"Kevin Peperonata ", "786465132184", {11,05,2022}};


    a1.inserisciCliente(c1);
    a1.inserisciCliente(c2);

    a1.inserisciCliente(c3);        // errore: a3.inserisciCliente invece di a1.inserisciCliente

    book.add(c4);
    book.add(c5);
    book.add(c6);

    a3.impostaLista(book);

    sortDecrescente(alberghi);
    
    vectorPrint(alberghi);

    insertBooking("Giovanni Muciacia", "78945612472", 4, {18,02,2022}, alberghi);

    vectorPrint(alberghi);
}


void vectorPrint(vector<Albergo*>& A){   // stampa tutti gli alberghi con relative prenotazioni
    for(int i = 0; i< A.size(); i++){
        /* mancato cout */ cout <<A[i]->toString();
        cout << "\n *----------------------------------* \n";
    }
}

void insertBooking(const string&n, const string&card, int cat, const Date&pren, vector<Albergo*>&A){ // funzione per l'inserimento di una prenotazione
    Cliente cl{n, card, pren}; // istanzia un cliente temporaneo
    bool isInserted{false};      // segnala l'avvenuto inserimento di un cliente
    for (int i = 0; i < A.size(); i++)          // effettua una ricerca nell'array di alberghi
    {
        if(cat == A[i]->getCategoria()){          // confronta dapprima l'hotel in base alla categoria desiderata
            if(!(A[i]->cercaData(cl))){         //cerca se un cliente ha già prenotato nello stesso hotel quel giorno
                A[i]->inserisciCliente(cl);     //nel caso in cui lo spazio risultasse disponibile, il cliente verrà inserito...
                isInserted = true;              // viene segnalato l'avvenuto inserimento...
                sortDecrescente(A);             //l'array riordinato...
                break;                          // e il ciclo concluso
            }
        }
    }
    (isInserted) ? cout << "Cliente inserito correttamente \n" : cout <<"Non è stato possibile inserire il cliente \n";
}


void quickSort(vector<Albergo*>&A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A,p, q);
        quickSort(A,q+1,r);
    }
}

int partition(std::vector<Albergo*>&A, int p, int r){
    int i = p-1;
    int j = r+1;
    Albergo* x = A[p];
    while (true)
    {   
        do {j=j-1;} while (*(x)>*(A[j]));//NOTA BENE: per tipi elementari togliere gli asterischi

        do {i=i+1;} while (*(A[i])>*(x));//NOTA BENE: per tipi elementari togliere gli asterischi

        if(i < j){swap(A, i,j);}

        else {return j;}
    }
    
}

void swap(std::vector<Albergo*>& A,int i,int j){
    Albergo* temp= A.at(i);
    A.at(i)=A.at(j);
    A.at(j)=temp;
}


void sortDecrescente(std::vector<Albergo*>&A){quickSort(A, 0, A.size()-1);}