#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Biscotto.h"
#include "LinkedList.h"
#ifndef AZIENDA_H
#define AZIENDA_H
class Azienda{
    public:
    Azienda(){
        std::fstream file("europeanBiscuits.txt", std::ios::in | std::ios::out);
        if(!file){
            throw std::runtime_error("File non trovato");
        }
        file >> n;
        for(int k=0; k<n; ++k){
            int i; file >> i;
            std::string a; file >> a;
            std::string b; file >> b;
            float c;
            std::vector<float> d;
            for(int i=0; i<10; ++i){
                file >> c;
                d.push_back(c);
            }
            if(d.size()!=10) throw std::runtime_error("No");
            Biscotto bis(i,a,b,d);
            biscotti.push_back(bis);
        }
    }
    bool simili(const Biscotto& a, const Biscotto& b){
        float dist{0};
            for(int i=0; i<10; ++i){
                dist+=pow(a.getCaratt()[i]-b.getCaratt()[i],2);
            }
        dist=sqrt(dist);
        //std::cout << "Easy qua";
        if(dist<=epsilon){
            return true;
        } else {
            return false;
        }
    }

    Azienda& buildGraph(){
        //std::cout << "Build begins";
        LinkedList empty;
        //std::cout << "Proseguo?";
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i!=j && simili(biscotti[i],biscotti[j])){
                    empty.addBack(biscotti[j].getID());
                }
            }
            grafo.push_back(empty);
            //std::cout << "Fin qui ci sono\n";
            empty.clear();
        }
        return *this;
    }

    std::string toString(){
        std::ostringstream out;
        int i{0};
        for(auto& list : grafo){
            out << i << ": " << list.toString() << " --- Numero di simili: " << list.size() <<"\n";
            i++;
        }
        return out.str();
    }
    private:
        int n;
        std::vector<Biscotto> biscotti;
        std::vector<LinkedList> grafo;
        float epsilon=10;
};
#endif