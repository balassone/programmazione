#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "Data.h"
#include <string>

class Impiegato{

public:
    Impiegato(const std::string&,const std::string&,Data&,const std::string&,const std::string&,const std::string&);
    virtual ~Impiegato() = default; //Invoco il costruttore di default
    //funzioni membro
    virtual double calcoloStipendio() const = 0; //questa funzione la definisco come pure virtual poichè non può essere cacolato lo stipendio per un generico impiegato
    virtual std::string informazioni() const; //questa funzione la dichiaro come virtual poichè verrà sovrascritta a seconda del tipo di impiegato
    //funzioni set e get
    void setNome(const std::string&);
    void setCognome(const std::string&);
    void setData(Data&);
    void setIndirizzo(const std::string&);
    void setNumero(const std::string&);
    void setCodiceFiscale(const std::string&);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getData() const;
    std::string getIndirizzo() const;
    std::string getNumero() const;
    std::string getCodiceFiscale() const;

private:
    std::string nome;
    std::string cognome;
    Data dataNascita;
    std::string indirizzo;
    std::string numero;
    std::string codiceFiscale;
};

#endif

