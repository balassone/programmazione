#include "Polinomio.h"
#include <iostream>
using std::ostream;

Polinomio::Polinomio()
    : dimensione{1},coefficienti{new double[dimensione]}{ //Inizializzo la dimensione del polinomio ad 1 ed alloco spazio in memoria heap per contenere un double di valore 0.0
        coefficienti[0]=0.0;
    }


Polinomio::Polinomio(double costante)
    : dimensione{1},coefficienti{new double[1]} { //Inizializzo la dimensione del polinomio ad 1 ed alloco spazio in memoria heap per contenere un double di valore pari ad una costante
        coefficienti[0]=costante;
    }

Polinomio::Polinomio(double coeff[],int dim)
    : dimensione{dim}, coefficienti{new double[dim]}{
        for(int i=0;i<dim;i++){
            coefficienti[i]=coeff[i];
        }
    }

Polinomio::Polinomio(const Polinomio& pol)
    : dimensione{pol.dimensione},coefficienti{new double[pol.dimensione]} {
        for(int i=0;i<pol.dimensione;i++){
            coefficienti[i]=pol.coefficienti[i];
        }
    }

Polinomio::~Polinomio(){
    delete[] coefficienti; //dealloco lo spazio in memoria riservato al contenere i vari coefficienti
}

Polinomio& Polinomio::operator=(const Polinomio& pol){
    if(this==&pol){ //se i due puntatori coincidono
        return *this; //allora ritorna il valore puntato da this che è un puntatore all'oggetto che ha invocato la funzione
    }
    else{
        delete[] coefficienti; //dealloco lo spazio riservato in memoria per i coefficienti
        dimensione=pol.dimensione;
        coefficienti=new double[pol.dimensione];
        for(int i=0;i<pol.dimensione;i++){
            coefficienti[i]=pol.coefficienti[i];
        }
        return *this;
    }
}

Polinomio& Polinomio::operator+=(const Polinomio& pol){
    int nuovaDim=((this->dimensione)>pol.dimensione)? (this->dimensione):pol.dimensione;
    double* nuoviCoeff=new double[nuovaDim];
    for(int i=0; i<nuovaDim;i++){
        nuoviCoeff[i]=0.0; //Inizializzo i coefficienti del nuovo polinomio a 0
    }
    for(int i=0; i<dimensione;i++){
        nuoviCoeff[i]+=coefficienti[i];
    }
    for(int i=0; i<pol.dimensione;i++){
        nuoviCoeff[i]+=pol.coefficienti[i];
    }
    delete[] coefficienti; //dealloco lo spazio in memoria riservato ai coefficienti dell'oggetto che chiama la funzione perche il risultato deve essere messe nell'oggetto stess
    dimensione=nuovaDim;
    coefficienti=nuoviCoeff; //faccio puntare coefficienti alla stessa area di memoria di nuoviCoefficienti
    return *this;
    //al termine di questa funzione non viene deallocato lo spazio in memoria puntato da nuoviCoeff poichè non è quello che volgiamo dato che questo spazio in memoria deve essere 
    //puntato da coefficienti.
    //Inoltre al termine della funzione la variabile nuoviCoeff viene implicitamente deallocata
}

Polinomio& Polinomio::operator*=(double x){
    for(int i=0;i<dimensione;i++){
        coefficienti[i]=coefficienti[i]*x;
    }
    return *this;
}

bool Polinomio::operator==(const Polinomio& pol){
    if(dimensione!=pol.dimensione){
        return false;
    }
    else{
        for(int i=0;i<dimensione;i++){
            if(coefficienti[i]!=pol.coefficienti[i]) return false;
        }
        return true;
    }
}

Polinomio operator+(const Polinomio& pol1,const Polinomio& pol2){
    Polinomio nuovoPolinomio=pol1; //viene richiamato il copy constructor
    nuovoPolinomio.operator+=(pol2);
    return nuovoPolinomio; //viene richiamato il copu constructor
    //nuovoPolinomio è una variabile locale e quindi viene deallocata al termine della funzione e per quuesto
    //non viene passato il riferimento.
}

Polinomio operator*(const Polinomio& pol,double x){
    Polinomio nuovoPolinomio=pol;
    nuovoPolinomio.operator*=(x);
    return nuovoPolinomio;
}

Polinomio operator*(double x,Polinomio& pol){
    Polinomio nuovoPolinomio=pol;
    nuovoPolinomio.operator*=(x);
    return nuovoPolinomio;
}


ostream& operator<<(ostream& output,const Polinomio& pol){
    for(int i=pol.dimensione-1;i>0;i--){
        output<<pol.coefficienti[i]<<"x^"<<(i)<<" + ";
    }
    output<<pol.coefficienti[0];
    return output;
}


/*Polinomio& Polinomio::operator*(const Polinomio& pol){
    int k=0;
    int nuovaDimensione=(this->dimensione)+pol.dimensione-1;
    double* nuoviCoefficienti=new double[nuovaDimensione];
    for(int i=0;i<nuovaDimensione;i++){
        nuoviCoefficienti[i]=0.0;
    }
    for(int i=0;i<dimensione;i++){
        nuoviCoefficienti[i]=coefficienti[i];
    }
    for(int j=0;j<pol.dimensione;j++){
        k++;
        int i=0;
        for((i+k);(i+k+j)<nuovaDimensione;i++){
            nuoviCoefficienti[i+k+j]+=pol.coefficienti[j];
        }
    }
    delete[] coefficienti;
    dimensione=nuovaDimensione;
    coefficienti=nuoviCoefficienti;
    return *this;
}
*/


