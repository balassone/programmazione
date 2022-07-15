/*Estendi l'esempio della linked list.
-Implementa la funzione membro size() che restituisce il numero degli elementi nella lista
-Implementa l'overloading dell'operatore operator[](int i), che restituisce l'i-esimo elemento memorizzato nella lista
-Implementa la funzione di ricerca per trovare il nodo contenente uno specifico elemento
-Implementa la funzione delete che elimina un elemento nella lista
-Inserire un elemento alla fine della lista
-Fare il reverse della lista */

#include <iostream>
#include "LinkedList.h"
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(){

    LinkedList<string> l1;
    l1.addFront("ciaoo");
    l1.addFront("ciaooo");
    l1.addFront("ciaoooo");
    l1.addFront("ciaooooo");
    l1.addBack("ciao");
    cout<<l1.toString();
    l1.reverse();
    cout<<endl;
    cout<<l1.toString();
    cout<<endl;
    LinkedList<string> l2;
    l2=l1;
    cout<<l2.toString();
}
