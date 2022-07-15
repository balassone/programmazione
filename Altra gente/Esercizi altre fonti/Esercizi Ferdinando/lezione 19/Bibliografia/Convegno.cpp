#include "Convegno.h"
#include <string>
#include <sstream>
#include <vector>
using std::vector;
using std::ostringstream;
using std::endl;
using std::string;

Convegno::Convegno(const string& tit,const vector<string> aut,const Data& dat,const string& sed,int pag)
    :Pubblicazione(tit,aut,dat) {
        setSedeConvegno(sed);
        setNumeroPagine(pag);
    }

void Convegno::setSedeConvegno(const string& sed){
    sedeConvegno=sed;
}

void Convegno::setNumeroPagine(int pag){
    numeroPagine=pag;
}

string Convegno::getSedeConvegno() const{return sedeConvegno;}
int Convegno::getNumeroPagine() const{return numeroPagine;}


string Convegno::toString() const{
    ostringstream out;
    out<<Pubblicazione::toString()<<"Sede convegno: "<<sedeConvegno<<endl<<"numero pagine: "<<numeroPagine<<endl;
    return out.str();
}