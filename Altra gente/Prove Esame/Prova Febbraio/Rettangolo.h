#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include "Piano.h"

class Rettangolo : public Piano
{
private:
    double base;
    double altezza;
public:
    Rettangolo() : Piano(), base{0.0}, altezza{0.0}{}
    Rettangolo(int c, const std::string&f, const std::string&l, float p, double b, double h);
    virtual ~Rettangolo(){}
    virtual double getArea() const override;
    virtual std::string toString() override;
};

#endif
