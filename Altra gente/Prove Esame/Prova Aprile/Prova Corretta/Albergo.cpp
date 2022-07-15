#include "Albergo.h"
#include <sstream>
#include <iomanip>


//costruttore senza passaggio di lista
Albergo::Albergo(const std::string &n, float p, int c) : nome{n}, prezzoUnitario{p}  {
    setCategoria(c);         // controlla se la categoria inserita è corretta
    LinkedList<Cliente> prenotazioni;    // inizializza la lista vuota
}
// costruttore con passaggio di lista
Albergo::Albergo(const std::string &n, float p, int c, LinkedList<Cliente>&cl) : nome{n}, prezzoUnitario{p} {
    setCategoria(c);         // controlla se la categoria inserita è corretta
    impostaLista(cl);    // inizializza la lista vuota
}


//Big Three
//implementato il sabato 23/04
Albergo::Albergo(const Albergo&al) : 
    nome{al.nome}, prezzoUnitario{al.prezzoUnitario}, categoria{al.categoria}, prenotazioni{al.prenotazioni}{}

Albergo& Albergo::operator=(const Albergo& al){
    if(!(this == &al)){
        nome = al.nome;
        prezzoUnitario = al.prezzoUnitario;
        categoria = al.categoria;
        prenotazioni = al.prenotazioni;
    }
    return *this;
}

Albergo::~Albergo(){ // permette la deallocazione della linkedlist dalla memoria rimuovendo tutti gli elementi fin quando è vuota
while (!prenotazioni.empty())
    {
        prenotazioni.removeFront();     
    }
}

//setGet
void Albergo::setPrezzo(float p){prezzoUnitario = p;}
void Albergo::setNome(const std::string & n){nome = n;};
void Albergo::setCategoria(int c){
    // controlla se la categoria fornita in ingresso rientra tra il 2 e il 5
    if ((c >=2)&& (c <=5))
    {
        categoria = c;
    }
    else {
        std::cout << "Categoria inserita non valida. Impostata categoria di default pari a 2 stelle";
    }
}
std::string Albergo::getNome() const {return nome;}
float Albergo::getPrezzo() const {return prezzoUnitario;}
int Albergo::getCategoria () const {return categoria;}

//setGetLista
void Albergo::impostaLista(LinkedList<Cliente>&cl){
    if (!(cl.empty()))
    {
        prenotazioni = cl;
    }
    else {
        LinkedList<Cliente> prenotazioni;
    }
}

LinkedList<Cliente> Albergo::getListaPrenotazioni() const {return prenotazioni;}


//ricerca una data disponibile: uso il cliente siccome effettuo overload operatore == e uso liste con template
bool Albergo::cercaData(const Cliente& cl){
    if (prenotazioni.find(cl))
    {
        return true;
    }
    else {
        return false;
    }
    
}



//funzione inserimento  e rimozione cliente all'interno della coda di prenotazioni
void Albergo::inserisciCliente(const Cliente& cl){
    prenotazioni.add(cl);
}
//la rimozione avviene sul cliente che ha la prenotazione più recente(stack)
Cliente Albergo::rimuoviCliente(){
    Cliente temp =prenotazioni.front(); 
    prenotazioni.removeFront();

    return temp;
}
//stampa albergo
std::string Albergo::toString() const{
    std::ostringstream out;

    out<< "\n         DATI ALBERGO: \n"
    << "NOME ALBERGO: "<<nome << "\n"
    << "PREZZO UNITARIO : €"<<std::setprecision(2)<<std::fixed<< prezzoUnitario<< "\n"
    << "CATEGORIA : "<<categoria << " STELLE \n"
    <<"LISTA PRENOTAZIONI CLIENTI : \n\n"
    <<prenotazioni.toString();

    return out.str();
}

// implementati il 23/04

int Albergo::getnumPrenotazioni() const {return prenotazioni.size();}

//i confronti venogno effettuati a seconda della dimensione della coda.
bool operator <(const Albergo&lhs, const Albergo&rhs){
    return lhs.getnumPrenotazioni() < rhs.prenotazioni.size();
}
bool operator >(const Albergo&lhs, const Albergo&rhs){
    return lhs.prenotazioni.size() > rhs.prenotazioni.size();
}
bool operator == (const Albergo&lhs, const Albergo&rhs){
    return lhs.prenotazioni.size() == rhs.prenotazioni.size();
}