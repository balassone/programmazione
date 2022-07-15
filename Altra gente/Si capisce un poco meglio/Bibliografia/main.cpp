//main.cpp
#include"Pubblicazione.h"
#include"Libro.h"
#include"Rivista.h"
#include"Convegno.h"
#include<list>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

using std::list;
using std::string;
using std::cout;
using std::sort;
/*
int partition(vector<Pubblicazione>&, int, int);
void quickSort(vector<Pubblicazione>&, int, int);
int partition(vector<Pubblicazione>&, int, int);

*/
bool comparing(Pubblicazione* A, Pubblicazione* B);

int main() {
    Libro libro("Vafammocc a chi te muort", {"Esposito C.", "Iovine A."}, 2019, "Rizzoli", "198232");
    Rivista rivista("L'arte di essere sinceri", {"Bugiardo S."}, 1989, "Scherzavo, l'anno è 1991", 23, 1, 90);
    Convegno convegno("Il convegno del grandissimo Professore Celentano", {"Celentano G., Celentano L."}, 2014, "COMPETENZA ED ONESTA'", "Castellammare di Stabia", 70);

    
    vector<Pubblicazione*> pubblicazioni;
    pubblicazioni.push_back(&libro);
    pubblicazioni.push_back(&rivista);
    pubblicazioni.push_back(&convegno);
    sort(pubblicazioni.begin(), pubblicazioni.end(), comparing);
    int cont=0;


    for (Pubblicazione* ptr : pubblicazioni){
        if(dynamic_cast<Libro*>(ptr)) {
            cont++;
        }
        cout<<ptr->toString();
    }
    cout<<"Il numero di libri è: "<<cont;
        

}

bool comparing(Pubblicazione* A, Pubblicazione* B){
    return *A<*B;
}

/*
void quickSort(vector<Pubblicazione>& A, int p, int r){
    if (p<r){
        int q=partition(A, p, r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

void swap(vector<Pubblicazione>& A, int x, int y){
    Pubblicazione temp=A[x];
    A[x] = A[y];
    A[y]=temp;
}

int partition(vector<Pubblicazione>& A, int p, int r){
    Pubblicazione x= A[p];
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while (x<A[j]);
        do
            i=i+1;
        while (A[i]<x);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

*/