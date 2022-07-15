#include"Date.h"
#include<string>
#include"Pacco.h"
#include"PaccoExtra.h"
#include"NodoP.h"
#include<iostream>
#include<sstream>
#include<exception>
#include"ListaP.h"
#include <vector>


using std::cout;
using std::cin;
using std::ostream;
using std::string;
using std::invalid_argument;
using std::vector;

//sulle date ho messo le parentesi graffe, così facendo non mi da più warning
//inoltre, nei costruttori ho messo il qualificativo const
Pacco P1{"Marco", "Gianluca", {15,3,2022}, 67};
PaccoExtra P2{"Alfredo", "Roberto", "Uganda", "Africa", {17,4,2021}, 70};
PaccoExtra P3{"Giorgio", "Nicola", "Stati Uniti", "America", {22,11,2020}, 55};
Pacco P4{"Saverio", "Gianluca", {15,3,2019}, 33};


std::vector<Pacco*>pacchi{&P1,&P2, &P3, &P4};

int main() {


    ListaP l1;

    l1.add(&P1);
    l1.add(&P2);
    l1.add(&P3);
    l1.add(&P4);

    PaccoExtra P5 = P2;


    cout<<l1.weeklyEarnings()<<std::endl;
    cout <<l1.toString();



    return 0;

}

