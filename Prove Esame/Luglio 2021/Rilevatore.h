#ifndef RILEVATORE_H
#define RIVELATORE_H
#include "Rilevamento.h"
#include <list>
#include "Date.h"
class Rilevatore{
    public:
        explicit Rilevatore(int id=1, int xx=1, int yy=1);
        Rilevatore (const Rilevatore&);
        ~Rilevatore() = default;
        Rilevatore& operator=(const Rilevatore&);
        Rilevatore& setID(const int&);
        const int& getID() const;
        Rilevatore& setX(const int&);
        const int& getX() const;
        Rilevatore& setY(const int&);
        const int& getY() const;
        Rilevatore& add(const Date& dat, const int&ppm);
        const std::list<Rilevamento>& getRel() const{
            return rilevamenti;
        }
    private:
        int id_station;
        int x;
        int y;
        std::list<Rilevamento> rilevamenti;
};
#endif