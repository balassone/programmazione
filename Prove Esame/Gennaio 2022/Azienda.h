#include "Pacco.h"
#include "Extra.h"
#include "LinkedList.h"
#include <string>
#include <sstream>
#ifndef AZIENDA_H
#define AZIENDA_H
class Azienda{
    public:
        Azienda() : l() {}
        ~Azienda() = default;
        Azienda& add(Pacco* p){
            l.addOrder(p);
            return *this;
        }

        double weeklyEarnings(){
            double sum=0;
            for(int i=0; i<l.size(); ++i){
                Extra* e=dynamic_cast<Extra*>(l[i]);
                if (e!=nullptr){
                    if(e->getNazione()=="USA"){
                        sum+=(10+e->getPeso());
                    } else {
                        sum+=(15+e->getPeso());
                    }
                } else{
                    sum+=l[i]->getPeso();
                }
            }
            return sum;
        }
        std::string toString(){
            std::ostringstream out;
            for(int i=0; i<l.size(); ++i){
                out << l[i]->toString() << "\n" << "\n";
            }
            return out.str();
        }
    private:
        LinkedList l;
};
#endif