#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{

public:
    explicit Account(double=0.0);
    virtual ~Account() = default;
    //funzioni get e set
    void setSaldo(double);
    double getSaldo() const;
    //prelievo e deposito
    virtual void prelievo(double) =0;
    void deposito(double);

private:
    double saldo;

};

#endif