#include "Studente.h"

using std::string;
using std::ostringstream;

Studente::Studente(const Studente &stud){
    nome = stud.nome;
    cognome = stud.cognome;
    matricola = stud.matricola;
    insegnamenti = stud.insegnamenti;
}

Studente& Studente::operator=(const Studente&stud){
    if(!(this == &stud)){
        nome = stud.nome;
        cognome = stud.cognome;
        matricola = stud.matricola;
        while(!(insegnamenti.empty())){insegnamenti.removeFront();}
        insegnamenti = stud.insegnamenti;
    }
    return *this;
}

bool Studente::operator == (const Studente&stud){
    return(nome == stud.nome && cognome == stud.cognome
        && matricola == stud.matricola && insegnamenti == stud.insegnamenti);
}

void Studente::setNome(const string& nm){nome = nm;}
void Studente::setCognome(const string&cnm){cognome = cnm;}
void Studente::setMatricola(const string&mat){matricola = mat;}
void Studente::esameSuperato(Insegnamento* materia){
    if(!(insegnamenti.find(materia)))
    insegnamenti.addBack(materia);
    else 
    std::cout << "aggiunta non effettuata: esame già superato!";
}
string Studente::getNome() const{return nome;}
string Studente::getCognome() const{return cognome;}
string Studente::getMatricola() const{return matricola;}

string Studente::toString() const {
    ostringstream out;
    out << "STUDENTE \n"
    << " NOME STUDENTE :  "<< getNome()<<std::endl
    <<" COGNOME STUDENTE : "<< getCognome()<<std::endl
    <<" MATRICOLA : "<< getMatricola()<<std::endl
    << "CREDITI ACCUMULATI " << calcoloCrediti()<<std::endl
    << "LISTA INSEGNAMENTI CONSEGUITI \n"<<insegnamenti.toString()<<std::endl;
    return out.str();
}

int Studente::calcoloCrediti() const{
    int creditiComplessivi{0};
    DNode<Insegnamento*>* n =insegnamenti.header->next;
    while(n != insegnamenti.trailer){
        creditiComplessivi += n->elem->getCrediti();
        n = n->next;
    }
    if (creditiComplessivi > 180)
    {
        creditiComplessivi = 180;
    }
    return creditiComplessivi;
    
}
bool operator <(const Studente&lhs, const Studente&rhs){
    return lhs.calcoloCrediti() < rhs.calcoloCrediti();
}
bool operator >(const Studente&lhs, const Studente&rhs){
    return lhs.calcoloCrediti() > rhs.calcoloCrediti();
}

std::ostream& operator<<(std::ostream& out, const Studente& stu){
    out <<stu.toString();
    return out;
}