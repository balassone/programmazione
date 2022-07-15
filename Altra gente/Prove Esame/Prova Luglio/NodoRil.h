#ifndef NODORIL_H
#define NODORIL_H

#include"Rilevamento.h"


class NodoRil{
    public:
    NodoRil();
    private:
    Rilevamento elem;
    NodoRil* next;

    friend class RilevList;
};




#endif