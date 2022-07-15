#ifndef RILIST_H
#define RILIST_H

#include"NodoRil.h"
#include"Rilevamento.h"
#include <iostream>



class RilevList{
    public:
    RilevList();
    ~RilevList();
    bool empty() const;
    const Rilevamento& front() const;
    void addMeasurement(const Rilevamento&);
    void insertBack(const Rilevamento&);

    int size();

    void remove();

    Rilevamento& operator[](int);

    RilevList& operator=(const RilevList&);


    
    
    

    private:
    NodoRil* head;

    friend class Rilevatore;

};

#endif