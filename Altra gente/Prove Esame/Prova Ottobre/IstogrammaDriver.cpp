#include <array>
#include <vector>
#include <iostream>
#include "Insegnamento.h"
#include "Studente.h"
#include "quickSort.h"

using std::string;
using std::vector;
using std::array;
using std::cout;

/*
- la funzione **istogramma_crediti()** che riceve in ingresso l’insieme degli studenti e calcola
 l’istogramma del numero di crediti superati dall’insieme dei nostri studenti. Visto che ogni studente 
 non puo’ superare piu’ di 180 crediti l’istogramma e’ un vettore di 181 elementi in cui in ogni posizione *k*
  c’e’ il numero di studenti che ha superato k crediti.
    - Ad esempio istogramma[0] contiene il numero di studenti che hanno superato 0 crediti, istogramma[9]
     contiene il numero di studenti che hanno superato 9 crediti, istogramma[18] contiene il numero di studenti
      che hanno superato 18 crediti, etc..
*/
template<typename T>
void printArray(vector<T>&v);
void creaIstogramma(vector<Studente*>&stud);
void stampaIstogramma();
void insertStudente(vector<Studente*>&stud, Studente* s);
void aggiuntaCrediti(vector<Studente*>&stud, Studente* s, Insegnamento* i);
void modificaIstogramma(Studente*s, int pr);
array<vector<Studente*>,181>istogramma{};


int main() {
  vector<Insegnamento*> insegnamenti;
  Insegnamento a1{"Analisi 1", 9, "Lina Mallozzi"};
  Insegnamento f1{"Fisica 1", 6, "Laura Valore"};
  Insegnamento fI{"Fondamenti di Informatica",9, "Angelo Chianese"};
  Insegnamento f2{"Fisica 2", 6, "Luca Lista"};
  Insegnamento a2{"Analisi 2", 6, "Nunzia Antonietta D'Auria"};
  Insegnamento a1cosimo{a1};
  a1cosimo.setDocente("Nunzia Gavitone");
  Insegnamento db{"Basi di Dati", 9, "Vincenzo Moscato"};
  Insegnamento fsd{"Fondamenti di Sistemi Dinamici", 9, "Vincenzo Lippiello"};
  Insegnamento ca{"Controlli Automatici", 9, "Santini Stefania"};

  insegnamenti.push_back(&a1);
  insegnamenti.push_back(&f1);
  insegnamenti.push_back(&fI);
  insegnamenti.push_back(&f2);
  insegnamenti.push_back(&a2);
  insegnamenti.push_back(&a1cosimo);
  insegnamenti.push_back(&db);
  insegnamenti.push_back(&fsd);
  insegnamenti.push_back(&ca);
  cout << "*----------Lista insegnamenti----------* \n\n";
  printArray(insegnamenti);


  Studente sdl{"Simone", "De Lucia", "N46004895"};
  Studente nazi{"Gabriel", "Covone", "N46003345"};
  Studente jac{"Joseph Alan", "Catchpole", "N46002006"};

  vector<Studente*> studenti;

  studenti.push_back(&sdl);
  studenti.push_back(&nazi);
  studenti.push_back(&jac);
  nazi.esameSuperato(&a1cosimo);
  nazi.esameSuperato(&f1);
  Studente naziClone{nazi};
  studenti.push_back(&naziClone);
  sdl.esameSuperato(&a1);
  sdl.esameSuperato(&a2);
  sdl.esameSuperato(&f1);
  sdl.esameSuperato(&f2);
  sdl.esameSuperato(&fI);
  jac.esameSuperato(&f1);
  jac.esameSuperato(&fI);
  jac.esameSuperato(&f2);
  jac.esameSuperato(&a2);
  cout << "*----------Lista Studenti----------* \n\n";
  printArray(studenti);
  jac.esameSuperato(&db);
  jac.esameSuperato(&fsd);
  jac.esameSuperato(&ca);
  cout << "*----------Lista Studenti Dopo aggiunta esami----------* \n\n";
  printArray(studenti);
  cout << "*----------Lista Studenti Dopo ordinamento----------* \n\n";
  quickSort(studenti);
  printArray(studenti);
  ca.setCrediti(190);
  cout <<jac.toString();
  creaIstogramma(studenti);
  cout << "stampa prima istogramma \n";stampaIstogramma();

  aggiuntaCrediti(studenti, &nazi, &f2);

  cout << "stampa istogramma dopo che uno studente ha aggiunto un insegnamento in coda \n";stampaIstogramma();

  cout << "stampa array finale \n"; printArray(studenti);
}

void insertStudente(vector<Studente*>&stud, Studente* s){
  stud.push_back(s);
  quickSort(stud);
}
void aggiuntaCrediti(vector<Studente*>&stud, Studente* s, Insegnamento* i){
  int vecchiCrediti = s->calcoloCrediti(); // prende vecchi crediti per lo scambio di posizione nell'istogramma
  s->esameSuperato(i); //segnala l'esame come superato
  quickSort(stud);   //l'aumento di crediti comporta l'ordinamento del vettore di studenti
  modificaIstogramma(s, vecchiCrediti);   //modifica la posizione nell'istogramma
}
void modificaIstogramma(Studente *s, int pr){
  for(int i = 0; i<istogramma[pr].size(); i++){
    if(istogramma[pr][i] == s){
      istogramma[pr].erase(istogramma[pr].begin()+i);
      break;
    }
  }
  istogramma[s->calcoloCrediti()].push_back(s);
}

template<typename T>
void printArray(vector<T>&v){

  for (int i = 0; i<v.size(); i++){
    cout <<*(v[i])<< "\n";
  }
}
  

void creaIstogramma(vector<Studente*>&stud){
    for (Studente* i : stud)
    {
      istogramma[i->calcoloCrediti()].push_back(i);
    }
}
void stampaIstogramma(){
    for(int i=0; i<181; i++){
      if(istogramma[i].size() != 0)
      cout << "Numero di studenti con "<< i << "crediti: "<< istogramma[i].size()<<"\n"; 
    }
}


