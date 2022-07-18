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
            //insert p based on the area of p
            if(fabbrica.isEmpty()){
                fabbrica.addFront(p);
            }
            else{
                if(fabbrica.getFront()->getArea()>p->getArea()){
                    fabbrica.addFront(p);
                }
                else{
                    //search for the position of an element that has a bigger area than p and add p in that position
                    int i=0;
                    while(fabbrica[i]->getArea()<p->getArea() && i<fabbrica.getLength()){
                        i++;
                    }
                    if(i==fabbrica.getLength()){
                        fabbrica.addBack(p);
                    }
                    else{
                        fabbrica.addPosition(i,p);
                    }
                    
                }
            }
            return *this;
        }
        float summarizeWarehouse() const{
            //return sum of all the areas of the pianos in the warehouse
            float sum=0;
            for(int i=0;i<fabbrica.getLength();i++){
                sum+=fabbrica[i]->getArea();
            }
            return sum;
        }
        std::string toString() const{
            std::ostringstream out;
            out << "Fabbrica.\n\n";
            for(int i{0}; i<fabbrica.getLength(); ++i){
                out << fabbrica[i]->toString();
            }
            return out.str();
        }
        int getLength() const{
            return fabbrica.getLength();
        }
    private:
        LinkedList<Piano*> fabbrica;
};
#endif