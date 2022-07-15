#ifndef LSP_H
#define LSP_H
#include <sstream>
#include"NodoP.h"

class ListaP{
    public:
    ListaP();
    ~ListaP();
    bool empty() const;
    
    void insertTable(const Piano*);
   
    Piano& operator[](int);

    int size();
    int summarizeWarehouse();
    void remove();

    int weeklyEarnings ();

    std::string toString();

    private:
    NodoP* head;

};

#endif
