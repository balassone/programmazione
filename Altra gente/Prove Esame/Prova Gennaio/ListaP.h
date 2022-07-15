#ifndef LSP_H
#define LSP_H

#include"NodoP.h"

class ListaP{
    public:
    ListaP();
    ~ListaP();
    bool empty() const;
    
    void add(const Pacco*);
   
    Pacco& operator[](int);

    int size();

    void remove();

    int weeklyEarnings ();

    string toString();

    private:
    NodoP* head;

};

#endif
