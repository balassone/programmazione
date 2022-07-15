#ifndef NDD_H
#define NDD_H

#include"Piano.h"
#include"Rettangolo.h"
#include "Cerchio.h"
#include "Triangolo.h"
class ListaP;

class NodoP{
    private:
    Piano* elem;
    NodoP* next;

    friend class ListaP;
};

#endif