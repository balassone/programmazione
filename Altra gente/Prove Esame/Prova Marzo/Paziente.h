//paziente.h

#ifndef PAZIENTE_H
#define PAZIENTE_H

#include <string>
#include <iostream>
#include "Dottore.h"

class Dottore;
class Paziente{
friend bool operator==(const Paziente&lhs, const Paziente&rhs);
friend std::ostream& operator<< ( std::ostream& os, const Paziente& p);
    private:
    std::string nome;
    std::string cognome;
    std::string numeroTelefono;
    Dottore* dottoreRichiesto;
    public:
    Paziente();
    ~Paziente();
    Paziente(const std::string&, const std::string&, const std::string&, Dottore*);
    Paziente(const Paziente&p);
    Paziente& operator=(const Paziente&p);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getNumeroTelefono() const;
    Dottore* getDottore() const;
    void setNome(const std::string& n);
    void setCognome(const std::string& cognome);
    void setNumeroTelefono(const std::string& numTel);
    void setDottore(Dottore*);

    std::string toString() const;
};

#endif
