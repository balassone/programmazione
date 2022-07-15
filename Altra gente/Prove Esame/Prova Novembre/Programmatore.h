#ifndef PRGMM_H
#define PRGMM_H

#include<string>
#include<vector>

using std::vector;
using std::string;


class Programmatore{
friend bool operator==(const Programmatore& lhs, const Programmatore& rhs);
    public:
    Programmatore(const string&, double=0.0);
    Programmatore(const Programmatore&);
    ~Programmatore();
    Programmatore& operator=(const Programmatore&);

    bool operator>(const Programmatore&);
    bool operator<(const Programmatore&);
    

    void setNome(const string& n){nome=n;}
    void setCosto(double c){costo=c;}

    string getNome()const{return nome;}
    double getCosto()const{return costo;}
    string toString();

   //Programmatore& operator[](int);

    private:
    string nome;
    double costo;





};





#endif