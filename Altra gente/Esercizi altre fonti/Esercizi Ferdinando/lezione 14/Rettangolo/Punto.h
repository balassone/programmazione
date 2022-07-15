#ifndef PUNTO_H
#define PUNTO_H

class Punto{

public:
    //Costruttore
    Punto(double = 0.0,double = 0.0);
    //funzioni set e get
    void setX(double);
    void setY(double);
    double getX() const;
    double getY() const;

private:
    double x;
    double y;
};

#endif