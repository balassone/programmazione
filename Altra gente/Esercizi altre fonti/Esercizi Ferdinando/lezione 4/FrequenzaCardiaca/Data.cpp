#include "Data.h"
#include <sstream>
#include <iomanip>
#include <string>
using std::string;
using std::ostringstream;
using std::setfill;
using std::setw;

Data::Data(int gg,int ms,int an)
    : giorno{gg}, anno{an} {
        setMese(ms);
    }

void Data::setGiorno(int gg){
    giorno=gg;
}

void Data::setMese(int ms){
    mese=(ms>=1 && ms<=12)? ms:1;
}

void Data::setAnno(int an){
    anno=an;
}

int Data::getGiorno() const{
    return giorno;
}

int Data::getMese() const{
    return mese;
}

int Data::getAnno() const{
    return anno;
} 

string Data::Display() const{
    ostringstream out;
    out<<setw(2)<<setfill('0')<<giorno<<"/"<<setw(2)<<setfill('0')<<mese<<"/"<<setw(4)<<anno;
    return out.str();
}