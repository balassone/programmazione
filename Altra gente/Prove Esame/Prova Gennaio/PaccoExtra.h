#ifndef PCCEXTR_H
#define PCCEXTR_H

#include"Pacco.h"



class PaccoExtra: public Pacco{
    public:
    //aggiunte Simone
    PaccoExtra();
    virtual ~PaccoExtra();
    PaccoExtra(const PaccoExtra& p);
    friend bool operator ==(const PaccoExtra& lhs, const PaccoExtra& rhs);
    PaccoExtra& operator= (const PaccoExtra& p);


    PaccoExtra(const string&, const string&, const string&, const string&, const Date&, int);   //modificato: posto la data a tipo di dato costante

    void setNazione(const string&);
    void setContinente(const string&);

    string getNazione()const;
    string getContinente()const;

    virtual int compensobase() override;

    virtual string stampaPacco() override;



    private:
    string nazione;
    string continente;


};

#endif