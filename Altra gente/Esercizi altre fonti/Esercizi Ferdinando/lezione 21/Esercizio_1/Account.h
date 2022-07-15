#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account{
public:
    //costruttore
    Account(int = 0,const std::string& = " ",const std::string& = " ",double = 0);
    //funzioni set e get
    void setNumeroConto(int);
    void setNome(const std::string&);
    void setCognome(const std::string&);
    void setSaldo(double);
    int getNumeroConto() const;
    std::string getNome() const;
    std::string getCognome() const;
    double getSaldo() const;

private:
    int numeroConto; //un int è rappresentato su 4 byte
    char nome[15]; //un char è rappresentato su 1 byte; dunque in questo caso ho 15 byte. Il quindicesimo byte è il carattere di fine stringa /0
    char cognome[15];// ...
    double saldo; //un double è rappresentato su 8 byte;
    //Rappresento il come ed il cognome come char di caratteri e non come stringa perchè per accedere in maniera casuale al file, devo far si che ogni record abbia una lunghezza fissata

};

#endif