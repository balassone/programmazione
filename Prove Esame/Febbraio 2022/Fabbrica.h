#include "Piano.h"
#include "LinkedList.h"
#include <string>
#include <sstream>
#ifndef FABBRICA_H
#define FABBRICA_H
class Fabbrica{
    public:
        Fabbrica() : fabbrica() {}
        Fabbrica(const LinkedList<Piano*>& f) : fabbrica(f) {}
        Fabbrica& operator=(const LinkedList<Piano*>& f) {fabbrica=f;return *this;}
        ~Fabbrica() {
            while(fabbrica.getLength()!=0){
                fabbrica.removeFront();
            }
        };
        Fabbrica& insertTable(Piano* const p){
            fabbrica.addOrder(p);
            return *this;
        }
        float summarizeWarehouse() const{
            float sum{0};
            for(int i{0}; i<fabbrica.getLength(); ++i){
                sum+=(fabbrica.getElem(i)->getArea());
            }
            return sum;
        }
        std::string toString() const{
            std::ostringstream out;
            out << "Fabbrica.\n\n";
            for(int i{0}; i<fabbrica.getLength(); ++i){
                out << fabbrica.getElem(i)->toString();
            }
            return out.str();
        }
    private:
        LinkedList<Piano*> fabbrica;
};
#endif