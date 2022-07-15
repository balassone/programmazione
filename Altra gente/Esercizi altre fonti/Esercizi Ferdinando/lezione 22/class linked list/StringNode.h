#ifndef STRINGNODE_H
#define STRINGNODE_H

#include <string>

class StringNode{ //Definisco una classe nodo di stringhe. Si può generalizzare ad un tipo generico

private:
    std::string elemento; //ogni nodo conterrà un elemento di tipo stringa
    StringNode* next; //ogni nodo conterrà un puntatore al prossimo nodo. In realtà non è una definizione ricorsiva poichè i nodi sono diversi

    friend class StringLinkedList;
    //definisco una classe friend di nome StringLinkedList che può accedere ai memebri privati della classe StringNode
    //La classe StringLinkedList implementa una lista di nodi di stringhe (poi generalizzaremo ad un tipo generico)
};

#endif