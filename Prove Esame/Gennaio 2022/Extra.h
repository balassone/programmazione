#include <string>
#include "Pacco.h"
#ifndef EXTRA_H
#define EXTRA_H
class Extra: public Pacco{
    public:
        Extra();
        Extra(const std::string&, const std::string&, const Date&, const double&, const std::string&, const std::string&);
        Extra& setNazione(const std::string&);
        const std::string& getNazione() const;
        Extra& setContinente(const std::string&);
        const std::string& getContinente() const;
        std::string toString() const;
    private:
        std::string nazione;
        std::string continente;
};

#endif