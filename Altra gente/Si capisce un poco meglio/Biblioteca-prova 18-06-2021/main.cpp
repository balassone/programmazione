#include"Libro.h"
#include"Prestito.h"
#include"QuickSort.h"
#include"Date.h"
#include<vector>
#include"DLinkedList.h"
using std::vector;
using std::cout;

bool comparing(Libro* A, Libro* B);

void borrow (Libro&, Date& );

int main() {
    Libro libro1 {"1232", {"Rossi G.", "Gialli D."}, "Programming", 1998, "294", 25};
    Libro libro2 {"1234", {"Verdi G.", "D'alessandro D."}, "Example", 1998, "294", 25};
    //creo un vettore di puntatori a libro
    vector<Libro*> libri;
    libri.push_back(&libro1);
    libri.push_back(&libro2);
    //utilizzo la funzione sort per ordinare il vettore:
    //sort(libri.begin(), libri.end(), comparing);
    quickSort(libri, 0, ((libri.size())-1));
    //mostro a video l'elenco di libri
    for (Libro* ptr : libri){
        cout<<ptr->toString();
    }   
    Date d1{12,11,2014};
    Date d2{11,10,2010};
    Prestito prestito1 {libro1, d1, d1+30};
    Prestito prestito2 {libro2, d2, d2+30};
    
    DLinkedList<Prestito> prestiti;
    prestiti.addFront(prestito1);
    prestiti.addFront(prestito2);

    

}

bool comparing(Libro* A, Libro* B){
    return (*A < *B);
}

void borrow(Libro& l, Date& d){
    
}

