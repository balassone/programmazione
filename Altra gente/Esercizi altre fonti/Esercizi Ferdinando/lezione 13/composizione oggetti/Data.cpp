#include "Data.h"
#include <array>
#include <exception>
#include <string>
#include <sstream>
#include <iomanip>
using std::setfill;
using std::setw;
using std::ostringstream;
using std::string;
using std::invalid_argument;
using std::array;

Data::Data(int gg,int ms,int an){
    setData(gg,ms,an);
}

void Data::setData(int gg,int ms,int an){
    if(checkGiorno(gg,ms,an)){
        giorno=gg;
        if(ms>0 && ms<=12){
            mese=ms;
            anno=an;
        }
    }
    else
        throw invalid_argument("La data non è corretta");
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

string Data::getData() const{
    ostringstream out;
    out<<setw(2)<<setfill('0')<<giorno<<"/"<<setw(2)<<setfill('0')<<mese<<"/"<<setw(4)<<anno;
    return out.str();
}

bool Data::checkGiorno(int gg,int ms,int an){
    array<int,13> mesiAnno{0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(gg<=mesiAnno[ms]){
        return true;
    }
    else if((gg==29) && (ms==2) && (an%4==0) && (an%100==0) && (an%400==0)){
        return true;
    }
    else{
        return false;
    }
}