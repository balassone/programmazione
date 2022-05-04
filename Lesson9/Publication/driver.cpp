#include "Publication.h"
#include "Book.h"
#include <iostream>
#include "quicksort.h"
#include <algorithm>
using std::cin; using std::cout; using std::vector; using std::string;
//bool comparePubsPtr(Publication* A, Publication* B){return *A<*B;}
int Book::nBooks=0; //Posso accedervi perché è pubblica, la uso così per inizializzare la var statica
int main(){
    vector <Publication*> bib;
    bib.push_back(new Publication({"Giovanni Bianchi","Michele rossi"}, "A great book",2021));
    bib.push_back(new Book ({"Aho Albert", "Jeoffrey Hocroft", "Ullmann"}, "Introduction to Computer Algorithms",1974,"98981981","Prentice All"));
    bib.push_back(new Book ({"Donald Knut"}, "The Art of Computer Programming",1968,"98981981","Prentice All"));
    quickSort(bib, 0, bib.size()-1);
    
    for(int i=0; i<bib.size(); ++i){
        cout << bib[i]->toString() << std::endl; // bib[i]->toString
    }
    cout << "Nbooks:" << Book::nBooks << std::endl;
    return 0;
}