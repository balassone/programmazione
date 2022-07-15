#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>

class Polinomio{
    
friend std::ostream& operator<<(std::ostream&,const Polinomio&);

public:
    //Costruttori:
    Polinomio(); //Definisco un costruttore per il polinomio del tipo P(x)=0.0;
    explicit Polinomio(double); //Definisco un costruttore per il polinomio del tipo P(x)=const
    Polinomio(double *,int); //Definisco un costruttore per il polinomio del tipo P(x)=const+ax+bx^2...;
    //Costruttore copia
    Polinomio(const Polinomio&);
    //Distruttore
    ~Polinomio();
    //Costruttore copia
    Polinomio& operator=(const Polinomio&);
    //Overloading degli operatori
    Polinomio& operator+=(const Polinomio&);
    Polinomio& operator*=(double);
    bool operator==(const Polinomio&);
    Polinomio& operator*(const Polinomio&);



private:
    int dimensione; //dim è la dimesione o taglia del polinomio; è dato dal grado del polinomio + 1(termine noto)
    double* coefficienti; //rappresento i coefficienti come un puntatore a double, ovvero come un array built-in; 
    //infatti avrei anche potuto scrivere double coefficienti[];

};
//Overloading degli operatori
//Questi li definisco esternamente poichè non hanno bisogno di accedere ai dati membro della classe Polinomio in quanto
//si basano su funzioni membro che sono pubbliche.
Polinomio operator+(const Polinomio&,const Polinomio&);
Polinomio operator*(const Polinomio&,double);
Polinomio operator*(double,Polinomio&);


#endif