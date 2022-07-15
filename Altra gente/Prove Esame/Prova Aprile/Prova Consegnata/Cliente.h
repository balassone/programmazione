#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include "Date.h"



class Cliente
{
    //overload operatore <<
    friend std::ostream& operator<<(std::ostream& out, const Cliente &cl);
    //overload operatori di confronto
    friend bool operator < (const Cliente& lhs, const Cliente& rhs);
    friend bool operator > (const Cliente& lhs, const Cliente& rhs);
    friend bool operator == (const Cliente& lhs, const Cliente& rhs); // usato per controllare le prenotazioni
     //operator < (const Cliente& lhs, const Cliente& rhs);
private:
    Date dataPrenotazione;
    std::string nome;
    std::string codiceCartaCredito;
public:
    Cliente() : dataPrenotazione(), nome{""}, codiceCartaCredito{""} {}
    Cliente(const std::string&n, const std::string&card, const Date& data): nome{n}, codiceCartaCredito{card} {dataPrenotazione = data;}
    //BigThree
    ~Cliente() {}
    Cliente(const Cliente&cl);
    Cliente& operator = (const Cliente & cl);
    //setGet
    void setData(const Date& data);
    void setNome(const std::string& n);
    void setCartaCredito(const std::string& carta);
    Date getData() const ;
    std::string getNome () const ;
    std::string getCartaCredito() const ;

    std::string toString() const ;
    
};


#endif

