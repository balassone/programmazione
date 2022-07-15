#ifndef PIANO_H
#define PIANO_H
#include <string>

class Piano{

    private:
    int colore;
    std::string fornitore;
    std::string tipoLegno;
    float prezzo;

    public:
    Piano() : colore{0}, fornitore{""}, tipoLegno{""}, prezzo{0.0}{}
    virtual ~Piano() {}
    Piano(int c, const std::string& f, const std::string& l, float p);
    void setColore(int col);
    void setFornitore(const std::string& f);
    void setLegno(const std::string& l);
    void setPrezzo(float p);
    int getColore() const;
    std::string getFornitore() const;
    std::string getLegno() const;
    float getPrezzo() const;
    //virtual Piano& operator=(const Piano& p);
    virtual double getArea() const = 0;
    virtual std::string toString(); 

};

#endif