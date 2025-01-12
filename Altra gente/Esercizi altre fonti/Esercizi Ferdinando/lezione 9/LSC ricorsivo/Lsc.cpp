#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

//includo tutti gli using così levo le mazzate da mezzo

int lcs(const string&,const string&,int,int); // definisco la funzione prototipo per la lcs formata dalle due stringhe costanti passate per riferimento e da due interi non dichiarati
int max(int,int); // definisco la funzione max che utilizzo nell'algoritmo della lcs

int main(){
    string c1,c2;
    cout<<"Inserisci due stringhe;"<<endl;
    cout<<"Stringa c1: ";
    cin>>c1;
    cout<<"Scringa c2: ";
    cin>>c2;

    cout<<"La lunghezza della LCS è:\n "<< lcs(c1,c2,c1.length(),c2.length());
    
    //nel main ho il driver del mio programma regolarizzo quindi interfacce input e output

    return 0;
}

int max(int x,int y){
    int max;
    max=(x>y)? x:y;
    return max; //semplice funzione max
}

int lcs(const string& x,const string& y,int lx,int ly){
    if(lx==0 || ly==0){
        return 0;
    }
    else if(x[lx]==y[ly]){
        return 1+lcs(x,y,lx-1,ly-1);
    }
    else{
        return max(lcs(x,y,lx-1,ly),lcs(x,y,lx,ly-1));
    }
}

//Questo programma non è ottimizzato per la complessità temporale poichè il caso peggiore è 2^n a causa del subproblem overlopping
