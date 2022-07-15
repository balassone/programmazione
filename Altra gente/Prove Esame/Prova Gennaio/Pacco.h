#ifndef PACCO_H
#define PACCO_H

#include"Date.h"
#include<string>

using std::string;


class Pacco {
    public:
    Pacco();
    Pacco(const string&, const string&, const Date&, int);
    
    //aggiunte Simone
    Pacco(const Pacco& p);
    Pacco& operator = (const Pacco& p);
    virtual ~Pacco();
    friend bool operator == (const Pacco& lhs, const Pacco& rhs); //modificato: posto la data a tipo di dato costante

    void setMittente(const string&);
    void setDestinatario(const string&);
    void setData(const Date&);
    void setKg(int);

    string getMittente()const;
    string getDestinatario()const;
    Date getData()const;
    int getKg()const;

    
    bool operator>(const Pacco&);
    bool operator<(const Pacco&);

    virtual int compensobase();

    virtual string stampaPacco();


    private:
    string mittente;
    string destinatario;
    Date dataconsegna;
    int kg;
    

};

#endif