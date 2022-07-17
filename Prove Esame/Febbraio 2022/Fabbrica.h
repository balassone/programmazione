#include "Piano.h"
#include "LinkedList.h"
#ifndef FABBRICA_H
#define FABBRICA_H
class Fabbrica{
    public:
        Fabbrica() : fabbrica() {}
        Fabbrica(const LinkedList<Piano*>& f) : fabbrica(f) {}
        Fabbrica& operator=(const LinkedList<Piano*>& f) {fabbrica=f;}
        ~Fabbrica() = default;
        Fabbrica& insertTable(Piano& const p){
            fabbrica.addOrder(&p);
        }
        float summarizeWarehouse() const{
            float sum{0};
            for(int i{0}; i<fabbrica.getLength(); ++i){
                //sum pricing
                sum+=fabbrica[i]->getPrice();

            }
        }
    private:
        LinkedList<Piano*> fabbrica;
};
#endif