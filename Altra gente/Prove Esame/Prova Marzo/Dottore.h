#ifndef DOTTORE_H
#define DOTTORE_H
#include "LinkedQueue.h"
#include "Paziente.h"
#include <iostream>
class Paziente;

class Dottore{
    friend bool operator<(const Dottore& lhs, const Dottore& rhs);
    friend bool operator>(const Dottore&lhs, const Dottore& rhs);
    friend bool operator==(const Dottore& lhs, const Dottore& rhs);
    public:
    Dottore();
    ~Dottore();
    Dottore(const std::string& n,const std::string& c,const std::string &cf,const std::string&t);
    //Dottore(const std::string& n,const std::string& c,const std::string &cf,const std::string&t, LinkedQueue<Paziente>&q);
    Dottore(const Dottore& d);
    Dottore& operator =(const Dottore&d);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getCodiceFiscale() const;
    std::string getNumeroTelefono() const;
    LinkedQueue<Paziente> getCoda() const;
    void setNome(const std::string&n );
    void setCognome(const std::string& c);
    void setCodiceFiscale(const std::string &cf);
    void setNumeroTelefono(const std::string &t);
    void impostaCoda(const LinkedQueue<Paziente>&c);
    int dimensioneCoda() const {return codaAttesa.size();}

    void nuovoPaziente(const Paziente& p) ;
    void fineVisita();

    std::string toString() const;

    private:
    std::string nome;
    std::string cognome;
    std::string codiceFiscale;
    std::string numeroTelefono;
    LinkedQueue<Paziente> codaAttesa;
};

#endif
