#include "Pubblicazione.h"
#include "Libro.h"
#include "Rivista.h"
#include "Convegno.h"
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

template<typename T> void quickSort(vector<T>&,int,int);
template<typename T> int partition(vector<T>&,int,int);
template<typename T> void swap(vector<T>&,int,int);

void stampa(Pubblicazione&);

int main(){
    int l=0;
    int r=0;
    int c=0;

    vector<string> autori_l1{"Ragozzino","Modugno","Pennacchio"};
    Data data_l1{18,4,1994};
    vector<string> autori_r1{"Russo","Fasolino"};
    Data data_r1{3,5,1997};
    vector<string> autori_c1{"Cacciapuoti","Pirozzi"};
    Data data_c1{2,2,1889};
    Libro l1{"AAAAAAA",autori_l1,data_l1,"Mondadori","444335-6555"};
    Rivista r1{"BBBBBB",autori_r1,data_r1,334,443};
    Convegno c1{"CCCCCCC",autori_c1,data_c1,"Via Napoli",334};
    vector<string>autori_l2=autori_l1;
    Data data_l2(13,5,1959);
    Libro l2{"DDDDDD",autori_l2,data_l2,"Universal","4456654-5543"};

    vector<Pubblicazione*> lista{};

    lista.push_back(&l1);
    lista.push_back(&r1);
    lista.push_back(&c1);
    lista.push_back(&l2);

    quickSort(lista,0,lista.size()-1);
    for(Pubblicazione* i: lista){
        stampa(*i);

        Libro* rifl=dynamic_cast<Libro*>(i);
        Rivista* rifr=dynamic_cast<Rivista*>(i);
        Convegno* rifc=dynamic_cast<Convegno*>(i);
        
        if(rifl!=nullptr){
            l++;
        }
        if(rifr!=nullptr){
            r++;
        }
        if(rifc!=nullptr){
            c++;
        }
    }
    cout<<"\nI libri sono: "<<l<<endl<<"Gli articoli su riviste sono: "<<r<<endl<<"Gli articoli su atti di convegno sono: "<<c<<endl;

}

void stampa(Pubblicazione& i){
        cout<<i.toString()<<endl;
}

template <typename T>
void quickSort(vector<T>& A,int p,int r){
    if(p<r){ //se ci sono almeno due elementi nel vettore
        int q=partition(A,p,r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

template <typename T>
int partition(vector<T>& A,int p,int r){
    T x=A[p]; //elemento pivot
    int i=p-1;
    int j=r+1;
    while(true){
        do{
            j=j-1;
        }
        while(*x<*A[j]); //overload dell'operatore < //devo deferenziare perchè il vettore lista contiene dei puntatori a publicazioni
        do
        {
            i=i+1;
        } while (*A[i]<*x); //overload dell'operatore < //devo deferenziare perchè il vettore lista contiene dei puntatori a pubblicazioni
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

template <typename T>
void swap(vector<T>& A,int i,int j){
    T temp=A[i];
    A[i]=A[j];
    A[j]=temp;
}
