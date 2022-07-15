#include <iostream>
#include "Piano.h"
#include "ListaP.h"
#include "Rettangolo.h"
#include "Triangolo.h"
#include "Cerchio.h"

using std::cout;
using std::endl;
using std::string;

ListaP magazzino;


int main(){
    Rettangolo R1{3456, "Scuro", "Ikea", 25.50, 5.3, 6.2};
    Triangolo T1{999, "Chiaro", "Leroy Merlin", 27.90, 3.8, 4.8};
    Cerchio C1{221, "Opaco", "Euronics", 32.90, 5};
    Triangolo T2{987, "Rossiccio", "Expert", 21.90, 2.2, 3.5};

    magazzino.insertTable(&R1);
    magazzino.insertTable(&T1);
    magazzino.insertTable(&C1);
    magazzino.insertTable(&T2);

    cout<<magazzino.toString();
}