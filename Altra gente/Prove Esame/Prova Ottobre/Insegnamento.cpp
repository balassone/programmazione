#include "Insegnamento.h"
#include <sstream>

using std::string;
using std::ostream;
using std::ostringstream;

Insegnamento::Insegnamento(const string &s, int cr, const std::string& doc){
    nome = s;
    setCrediti(cr);
    docente = doc;
}

void Insegnamento::setDocente(const string& doc){docente = doc;}
void Insegnamento::setNome(const string& n){nome = n;}
void Insegnamento::setCrediti(const int cr){(cr > 180)? crediti = 180 : crediti = cr;}
string Insegnamento::getDocente() const {return docente;}
string Insegnamento::getNome() const {return nome;}
int Insegnamento::getCrediti() const {return crediti;}
string Insegnamento::toString() const {
    ostringstream out;
    out << "INSEGNAMENTO \n"
    << "NOME MATERIA : "<<getNome()<<std::endl
    <<"CREDITI MATERIA : "<<getCrediti()<<std::endl
    <<"DOCENTE : "<<getDocente()<<std::endl;
    return out.str();
}
bool operator ==(const Insegnamento&lhs, const Insegnamento& rhs){
        return (lhs.nome == rhs.nome && lhs.crediti && rhs.crediti && lhs.docente == rhs.docente);
}

ostream& operator<<(ostream& out, const Insegnamento& ins){
    out <<ins.toString();
    return out;
}