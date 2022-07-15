#include <iostream>
#include <cstdlib> //Includo questa libreria per usare random e srand
#include <ctime>
using std::cout;
using std::endl;

unsigned int tiroDadi();

int main(){

    enum class risultato{VITTORIA,SCONFITTA,CONTINUA}; //Definisco una classe enumerativa che può assumere 3 valori costanti
    srand(static_cast<unsigned int>(time(0))); //definisco un seme iniziare srand casuale(genera un seme diverso ad ogni istante) che deve essere intero
    unsigned int punteggio{0}; //Inizializzo il punteggio
    unsigned int sommaDadi{tiroDadi()};
    risultato statoGioco;

    switch (sommaDadi)
    {
    case 7:
    case 11:
        statoGioco=risultato::VITTORIA;
        break;
    case 2:
    case 3:
    case 12:
        statoGioco=risultato::SCONFITTA;
        break;
    default: //per tutti gli altri casi
        statoGioco=risultato::CONTINUA;
        punteggio=sommaDadi;
        cout<<"Il punteggio attuale è: "<<sommaDadi<<endl;
        break;
    }

    while(statoGioco==risultato::CONTINUA){
        sommaDadi=tiroDadi();
        if(punteggio==sommaDadi) statoGioco=risultato::VITTORIA;
        else if (sommaDadi==7) statoGioco=risultato::SCONFITTA;
        else statoGioco=risultato::CONTINUA;
    }
    
    if(statoGioco==risultato::VITTORIA){
        cout<<"Il giocatore ha vinto";
    }
    else{
        cout<<"Il giocatore ha perso";
    }

    return 0;





}

unsigned int tiroDadi(){
    int dado1{(rand()%6) + 1};
    int dado2{(rand()&6) + 1};
    int somma=dado1+dado2;

    cout<<"La somma del dado1 e dado 2 è "<<somma<<endl;;
    return somma;
}
