#include <iostream>
#include <vector>
#include "Pubblicazione.h"
#include "Libro.h"
#include "Rivista.h"
#include "Articoli.h"

using std::vector;
using std::string;
using std::cout;

template<typename P>void quickSort(vector<P> &A, int p, int r);
template<typename P>int partition(vector<P> & A, int p, int r);
template<typename P>void swap(vector<P>&A, int i, int j);

int main(){

    vector<Pubblicazione*>pubblicazioni;
    Libro l{"baba", {"yaga"}, 1909, 800900313, "jw3"};
    Rivista r("cacca", {"chiappette", "al vento"}, 6969, "fare la cacca troppo spesso fa male", 69, 6, 420);
    Articoli a("ciao", {"buongiorno"}, 8989, "okokok", "nonono", 89);
    Articoli b("cico", {"buonanotte"}, 8689, "aiutooo", "uffa", 89);
    Libro l2{l};
    int numeroLibri{0},numeroRiviste{0},numeroArticoli{0};


    pubblicazioni.push_back(&l);
    pubblicazioni.push_back(&r);
    pubblicazioni.push_back(&a);
    pubblicazioni.push_back(&b);
    pubblicazioni.push_back(&l2);

    for(int i= 0; i<pubblicazioni.size(); i++){
        pubblicazioni[i]->print();
        cout << "\n *-----------------------------*\n";
    }
    quickSort(pubblicazioni, 0, 3);

    for(int i= 0; i<pubblicazioni.size(); i++){
        pubblicazioni[i]->print();
        cout << "\n *-----------------------------*\n";
    }

    for(Pubblicazione* i: pubblicazioni){
        Libro* libp = dynamic_cast<Libro*>(i);
            if (libp != nullptr)
            {
                numeroLibri ++;
                continue;
            }
            
        Rivista* rivp = dynamic_cast<Rivista*>(i);
            if (rivp != nullptr)
            {
                numeroRiviste ++;
                continue;
            }
        Articoli* artp = dynamic_cast<Articoli*>(i);
            if (artp != nullptr)
            {
                numeroArticoli ++;
                continue;
            }
    }




    cout << "\n Numero di libri presenti nelle pubblicazioni : "<<numeroLibri << "\n";
    cout << "\n Numero di articoli presenti nelle pubblicazioni : "<<numeroArticoli << "\n";
    cout << "\n Numero di Riviste presenti nelle pubblicazioni : "<<numeroRiviste << "\n";



}
template<typename P>
void quickSort(vector<P>&A, int p, int r){
    if(p<r){
        int q = partition(A, p, r);
        quickSort(A,p, q);
        quickSort(A,q+1,r);
    }
}
template<typename P>
int partition(vector<P>&A, int p, int r){
    int i = p-1;
    int j = r+1;
    P x = A.at(p);
    while (true)
    {   
        do {j=j-1;} while (*x<*A[j]);

        do {i=i+1;} while (*A[i]<*x);

        if(i < j){swap(A, i,j);}

        else {return j;}
    }
    
}
template<typename P>
void swap(vector<P>& A,int i,int j){
    P temp= A.at(i);
    A.at(i)=A.at(j);
    A.at(j)=temp;
}
