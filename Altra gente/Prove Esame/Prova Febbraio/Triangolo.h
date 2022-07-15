#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "Piano.h"

class Triangolo : public Piano{
    private:
    double base;
    double altezza;
    public:
    Triangolo() : Piano(), base{0.0}, altezza{0.0} {}
    virtual ~Triangolo() {}
    Triangolo(int c, const std::string&f, const std::string&l, float p, double b, double h);
    
    virtual double getArea() const override;
    virtual std::string toString() override;
};

#endif