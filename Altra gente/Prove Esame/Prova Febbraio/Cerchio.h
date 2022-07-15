#ifndef CERCHIO_H
#define CERCHIO_H

#include "Piano.h"

class Cerchio : public Piano
{
private:
    double raggio;
public:
    Cerchio() : Piano(), raggio{0.0} {}
    Cerchio(int c, const std::string&f, const std::string&l, float p, double r);
    virtual ~Cerchio() {}
    
    virtual double getArea() const override;
    virtual std::string toString() override;

};

#endif
