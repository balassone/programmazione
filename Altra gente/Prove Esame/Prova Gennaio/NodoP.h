#ifndef NDD_H
#define NDD_H

#include"Pacco.h"
#include"PaccoExtra.h"

class NodoP{
    private:
    Pacco* elem;
    NodoP* next;

    friend class ListaP;
};

#endif