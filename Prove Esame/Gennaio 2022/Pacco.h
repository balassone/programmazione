#include <string>
#include <sstream>
#include "Date.h"
#ifndef PACCO_H
#define PACCO_H
class Pacco{
    public:
        Pacco();
        Pacco(const std::string&, const std::string&, const Date&, const double&);
        Pacco& setMittente(const std::string&);
        const std::string& getMittente() const;
        Pacco& setDestinatario(const std::string&);
        const std::string& getDestinatario() const;
        Pacco& setDate(const Date&);
        const Date& getDate() const;
        Pacco& setPeso(const double&);
        const double& getPeso() const;
        bool operator<(const Pacco&);
        virtual std::string toString() const;
    private:
        std::string mittente;
        std::string destinatario;
        Date consegna;
        double peso;
};
#endif