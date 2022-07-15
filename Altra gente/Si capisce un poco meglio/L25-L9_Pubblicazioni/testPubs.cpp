//testPubs.cpp
#include"Publication.h"
#include"Book.h"
#include<iostream>
#include<vector>
#include<algorithm> //serve per invocare la funzione sort di <vector>
using std::vector;
using std::cout;
                                            //QuickSort
template<typename T>
int partition(vector<T>& A, int p, int q);

template<typename T>
void quickSort(vector<T>& A, int p, int r){
    if (p<r){
        int q=partition(A, p, r);
        quickSort(A,p,q);
        quickSort(A,q+1,r);
    }
}

template<typename T>
void swap(vector<T>& A, int x, int y){
    T temp=A[x];
    A[x] = A[y];
    A[y]=temp;
}

template<typename T>
int partition(vector<T>& A, int p, int r){
    T x= A[p];
    int i=p-1;
    int j=r+1;
    while(true){
        do
            j=j-1;
        while (*x<*A[j]);                 //era A[j]>x, abbiamo riscritto in modo da avere solo l'operatore <
                                          //inoltre è un vettore di puntatori a pubblicazioni il nostro, quindi dereferenziamo
        do
            i=i+1;
        while (*A[i]<*x);
        if(i<j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}
//scrittura della funzione da passare a sort se si vuole utilizzare l'ordinamento di <vector>
//se non scrivessimo questa funzione non diremmo la modalità con cui effettuare il confronto
//e quindi <vector> ordinerebbe gli indirizzi e non i valori
bool compareBib(Publication* A, Publication* B){
    return *A < *B;                                 //sfruttiamo il < riscritto per Publication
}

int Book::nBooks=0;

int main(){
    Publication b1("A great book", {"Rossi M.","Verdi C.", "Bianchi M."}, 2001);
    Publication b2("Another great book", {"Esposito M.","Bianchi M."}, 2002);
    Publication b3("A great novel", {"Arnaldi M.","Bianchi M."}, 2002);
    Book b4("The Art of Computer Programming", {"Knuth D."}, 1968, "Academic Publishers", "89283-7237362");

    vector<Publication*> bib;
    bib.push_back(&b1);
    bib.push_back(&b2);
    bib.push_back(&b3);
    bib.push_back(&b4);
    
    //quickSort(bib, 0, bib.size()-1);
    std::sort(bib.begin(), bib.end(), compareBib);
    
    for(int i=0; i<bib.size();i++){
        cout<<bib[i]->toString()<<"\n";
    }
    cout<<"Number of books in bibliography: "<<Book::nBooks<<"\n";
}