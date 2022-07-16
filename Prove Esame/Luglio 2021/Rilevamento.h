#ifndef RILEVAMENTO_H
#define RILEVAMENTO_H
#include "Date.h"
class Rilevamento{
    public:
        Rilevamento() = default;
        Rilevamento(const Date&, const int& );
        Rilevamento& operator=(const Rilevamento&);
        Rilevamento& setDate(const Date&);
        const Date& getDate() const;
        Rilevamento& setPPM(const int&);
        int getPPM() const;
        bool operator==(const Rilevamento& r){
            return data==r.data&&ppm==r.ppm;
        }
        bool operator<(const Rilevamento& r){
            return data<r.data;
        }
    private:
        Date data;
        int ppm;
};
#endif