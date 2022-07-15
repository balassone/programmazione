//Time.cpp
//Time class member-function definitions
#include<iomanip> //per i manipolatori di flusso setw e setfill
#include<stdexcept> //per le eccezioni per argomenti invalidi della classe
#include<string>
#include<sstream>
#include"Time.h" //includo la definizione della classe Time da Time.h

using namespace std;

//funzione che setta il nuovo valore Time usando il tempo universale (24h)
void Time::setTime(int h, int m, int s) {
    //validazione di ore, minuti e secondi
    if ((h>=0 && h<24) && (m>=0 && m<59) && (s<59)) {
        hour=h;
        minute=m;
        second=s;
    } 
    else {
        throw invalid_argument (
            "hour, minute and/or second was out of range");
    }
}

//ritorna Time come stringa in formato universale (24h)
string Time::toUniversalString() const {
    ostringstream output;
    output<<setfill('0')<<setw(2)<<hour<<":"<<setw(2)<<minute<<":"<<setw(2)<<second;
    return output.str();
}

//ritorna Time come stringa in formato standard (12h)
string Time::toStandardString() const {
    ostringstream output;
    output<< ((hour==0 || hour==12) ? 12 : hour % 12) << ":" <<setfill('0')<<setw(2)<<minute<<":"<<setw(2)<<second<<(hour < 12 ? " AM":" PM");
    return output.str();
}
