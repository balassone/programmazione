#ifndef ALBERGO_H
#define ALBERGO_H

#include "Cliente.h"
#include "LinkedList.h"
#include <string>


class Albergo
{
//overload operatore di confronto
friend bool operator <(const Albergo&lhs, const Albergo&rhs);
friend bool operator >(const Albergo&lhs, const Albergo&rhs);
friend bool operator == (const Albergo&lhs, const Albergo&rhs);
private:
    std::string nome;
    float prezzoUnitario;
    int categoria =2;   // valore di default per prevenire ingressi errati in fase di inizializzazione
    LinkedList<Cliente>prenotazioni;
public:
    Albergo() : nome{""}, prezzoUnitario{0.0}, categoria{2} {LinkedList<Cliente>prenotazioni;}
    Albergo(const std::string &n, float p, int c, LinkedList<Cliente>&cl); // costruttore con passaggio di lista
    Albergo(const std::string &n, float p, int c); // costruttore senza passaggio di lista: l'albergo verrà inizializzato con coda vuota
    //big three
    Albergo(const Albergo&al);
    ~Albergo();
    Albergo& operator=(const Albergo& al);

    //set and get
    void setPrezzo(float p);
    void setNome(const std::string & n);
    void setCategoria(int c);
    std::string getNome() const ;
    float getPrezzo() const;
    int getCategoria () const;
    void impostaLista(LinkedList<Cliente>&cl);
    LinkedList<Cliente> getListaPrenotazioni() const;

    //funzione per la ricerca di una data
    bool cercaData(const Cliente& cl);

    //inserimento e rimozione di clienti all'interno della lista di prenotazioni
    void inserisciCliente(const Cliente& cl) ;
    Cliente rimuoviCliente();
    
    //stampa informazioni albergo
    std::string toString() const;

    //IMPLEMENTATA IL 23/04: Ottiene informazioni sulla coda delle prenotazioni
    int getnumPrenotazioni() const;

};


#endif