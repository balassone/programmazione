#ifndef STUD_H
#define STUD_H

#include "Insegnamento.h"
#include "DLinkedList.h"

#include <string>

class Studente{
    friend bool operator <(const Studente&lhs, const Studente&rhs);
    friend bool operator >(const Studente&lhs, const Studente&rhs);
    friend std::ostream& operator<<(std::ostream& out, const Studente& stu);
    public:
    Studente() : nome {""}, cognome {""}, matricola {""} {DLinkedList<Insegnamento*> insegnamenti;}
    ~Studente() {
        while(!(insegnamenti.empty()))
            {insegnamenti.removeFront();}
        }
    Studente(const Studente&stud);
    Studente& operator = (const Studente& stud);
    Studente(const std::string &nm, const std::string&cnm, const std::string&mat)
        : nome{nm}, cognome{cnm}, matricola{mat} {DLinkedList<Insegnamento*> insegnamenti;}

    

    void setNome(const std::string&nm);
    void setCognome(const std::string&cnm);
    void setMatricola(const std::string&mat);
    void esameSuperato(Insegnamento* materia);
    std::string getNome() const;
    std::string getCognome() const;
    std::string getMatricola() const;

    bool operator == (const Studente&stud);

    int calcoloCrediti() const;

    std::string toString() const;

    private:
    std::string nome;
    std::string cognome;
    std::string matricola;
    DLinkedList<Insegnamento*> insegnamenti;
    

};


#endif