//ClientData.h
#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include<string>

class ClientData{
    public:
        ClientData(int=0, const std::string& = "", const std::string& = "", double=0.0);
       
        void setAccountNumber(int);
        int getAccountNumber() const;
        
        void setLastName(const std::string&);
        std::string getLastName() const;
        
        void setFirstName(const std::string&);
        std::string getFirstName() const;
        
        void setBalance(double);
        double getBalance() const;


    private:
        int accountNumber;
        char lastName[15]; //l'ultimo carattere è /0 quindi in realtà sono 14 caratteri ammissibili
        char firstName[10]; //l'ultimo carattere è /0 quindi in realtà sono 9 caratteri ammissibili
        double balance;
};

#endif