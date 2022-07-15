#include "Data.h"
#include <array>
#include <iostream>
#include <exception>
#include <iomanip>
#include <string>
#include <sstream>
using std::string;
using std::ostringstream;
using std::ostream;
using std::setfill;
using std::setw;
using std::invalid_argument;
using std::array;
using std::cout;


Data::Data(int gg,int ms,int an){
    setData(gg,ms,an);
}

void Data::setData(int gg,int ms,int an){
    if(validaGiorno(gg,ms,an) && (ms>0 && ms<=12)){
        giorno=gg;
        mese=ms;
        anno=an;
    }
    else
        throw invalid_argument("La data inserita non è corretta");
}


bool Data::validaGiorno(int gg,int ms,int an){
    array<int,mesiAnno> giorniMese{0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(gg<=giorniMese[ms]) return true;
    else if(gg==29 && ms==2 && an%4==0 && (an%100==0 && an%400==0)) return true;
    return false;
}


void Data::helpSomma(int x){
    array<int,mesiAnno> giorniMese{0,31,28,31,30,31,30,31,31,30,31,30,31};
    giorno=giorno+x;
    if(giorno>giorniMese[mese]){
        giorno=giorno-giorniMese[mese];
        mese=mese+1;
        if(mese>12){
            anno=anno+1;
        }
    }
}

void Data::helpDifferenza(int x){
    array<int,mesiAnno> giorniMese{0,31,28,31,30,31,30,31,31,30,31,30,31};
    giorno=giorno-x;
    if(x>=giorno){
        if(mese==1){
            mese=12;
            anno=anno-1;
        }
        else{
            mese=mese-1;
        }
        giorno=giorniMese[mese]-(x-giorno);
    }
}

Data operator+(const Data& d,int x){
    Data nuovaData=d;
    nuovaData.helpSomma(x);
    return nuovaData;
}

Data& Data::operator-(int x){
    this->helpDifferenza(x);
    return *this;

}

Data operator+(int x,const Data& d){
    Data nuovaData=d;
    nuovaData.helpSomma(x);
    return nuovaData;
}

bool Data::operator<(Data& d){
    if(this->anno < d.anno){
        return true;
    }
    else if((this->anno == d.anno) && (this->mese<d.mese)){
        return true;
    }
    else if((this->anno == d.anno) && (this->mese==d.mese) && (this->giorno<d.giorno)){
        return true;
    }
    return false;
}

bool Data::operator==(const Data& d){
    if((giorno==d.giorno) && (mese==d.mese) && (anno=d.anno)){
        return true;
    }
    return false;
}

bool Data::operator>(const Data& d){
    if(anno>d.anno){
        return true;
    }
    else if((anno==d.anno) && (mese>d.mese)){
        return true;
    }
    else if((anno==d.anno) && (mese==d.mese) && (giorno>d.giorno)){
        return true;
    }
    return false;
}

bool Data::operator>=(const Data& d){
    if(anno>d.anno){
        return true;
    }
    else if((anno==d.anno) && (mese>d.mese)){
        return true;
    }
    else if((anno==d.anno) && (mese==d.mese) && (giorno>=d.giorno)){
        return true;
    }
    return false;
}

bool Data::operator<=(const Data& d){
    if(this->anno < d.anno){
        return true;
    }
    else if((this->anno == d.anno) && (this->mese<d.mese)){
        return true;
    }
    else if((this->anno == d.anno) && (this->mese==d.mese) && (this->giorno<=d.giorno)){
        return true;
    }
    return false;
}

bool Data::operator!=(const Data& d){
    if((giorno==d.giorno) && (mese==d.mese) && (anno=d.anno)){
        return false;
    }
    return true;
}

Data& Data::operator++(){
    *this=operator+(*this,1);
    return *this;
}

Data& Data::operator+=(int x){
    *this=operator+(*this,x);
    return *this;
}

ostream& operator<<(ostream& out,Data& d){
    out<<setw(2)<<setfill('0')<<d.giorno<<"/"<<setw(2)<<setfill('0')<<d.mese<<"/"<<setw(4)<<d.anno;
    return out;
}


string Data::getData() const{
    ostringstream out;
    out<<setw(2)<<setfill('0')<<giorno<<"/"<<setw(2)<<setfill('0')<<mese<<"/"<<setw(4)<<anno;
    return out.str();
}