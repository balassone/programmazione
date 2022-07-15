#ifndef STRINGLINKEDLIST_H
#define STRINGLINKEDLIST_H

#include "StringNode.h"
#include <string>

class StringLinkedList{

public:
    StringLinkedList(); //costruttore
    ~StringLinkedList(); //Distruttore
    //funzioni membro
    bool empty() const; //funzione membro che restituisce true se la lista è vuota. ci sta const perchè la funzione non può modificare i dati membro privati
    const std::string& front() const; //funzione membro che restituisce l'elemento in testa alla lista
    //Il primo const fa riferimento al fatto che l'utente non può modificare l'elemento in testa alla lista restituito dalla funzione front()
    //Il secondo const fa riferimento al fatto che la funzione non può modificare i dati membro della lista
    //Il riferimento si riferisce al fatto che l'elemento può essere anche molto grande e quindi si preferisce passare il riferimento 
    void addFront(const std::string&); //funzione che permette di aggiungere un elemento in testa alla lista
    void removeFront(); //funzione che permette di eliminare un elemento in testa alla lista
    //L'aggiunta e la rimozione avvengono sempre in testa
private:
    StringNode* head; //definisco la testa della lista come un puntatore alla classe StringNode
    //Inizialmente la testa della lsta sarà un puntatore nullo
};


#endif