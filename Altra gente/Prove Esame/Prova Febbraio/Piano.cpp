#include <sstream>
#include "Piano.h"

using std::string;

Piano::Piano(int c, const std::string&f, const std::string&l, float p)
    : colore{c}, fornitore{f}, tipoLegno{l}, prezzo{p} {}

/*Piano& Piano::operator=(const Piano& p){
    colore = p.colore;
    fornitore = p.fornitore;
    tipoLegno = p.tipoLegno;
    colore = p.colore;
}
*/

void Piano::setColore(int col){colore = col;}
void Piano::setFornitore(const std::string& f){fornitore = f;}
void Piano::setLegno(const std::string& l){tipoLegno = l;}
void Piano::setPrezzo(float p){prezzo = p;}

int Piano::getColore() const {return colore;}
std::string Piano::getFornitore() const {return fornitore;}
std::string Piano::getLegno() const {return tipoLegno;}
float Piano::getPrezzo() const {return prezzo;}

string Piano::toString() {
    std::ostringstream output;
    output << "PIANO \n CODICE COLORE: " << colore
    <<"\n FORNITORE : " << fornitore
    <<"\n TIPOLOGIA LEGNO " << tipoLegno
    <<"\n PREZZO : "<< prezzo;
    return output.str();
}