#include "City.h"
#include "Rilevatore.h"
#include "Rilevamento.h"
#include "Data.h"
#include <list>
using std::list;

void addMeasurement()

int main(){
    Data d1{7,10,2021};
    Rilevamento r1{d1,0.5};
    Data d2{4,12,2020};
    Rilevamento r2{d1,0.4};

    Rilevatore ril{2,4,204};
    ril.addRilevamento(r1);
    ril.addRilevamento(r2);

}