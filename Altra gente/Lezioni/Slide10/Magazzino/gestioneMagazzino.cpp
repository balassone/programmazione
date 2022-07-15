#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>


using std::cout;
using std::cerr;
using std::cin;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::ios;
using std::fstream;
class Articolo;
enum class Choice{MODIFICA = 1,LETTURA, RESET, USCITA};

void outputLine(ostream&, const Articolo&);
void fileReading();
void fileWriting();
void createFile();
void deleteFile();
void menu();
Choice entraScelta();

int main(){
    menu();
}

class Articolo {
    private:
    short int codice;
    short int quantita;
    float prezzo;
    char nome[36];
    bool isTaken[100]{false}; // controlla se il codice dell'articolo è già stato preso

    public:
    Articolo(const short int cod = 0, const short int qt = 0 , float prz = 0.0, const string& n = "") : quantita {qt}, prezzo {prz} {setCodice(cod); setNome(n);}
    short int getCodice() const {return codice;}
    short int getQuantita() const {return quantita;}
    float getPrezzo() const {return prezzo;}
    string getNome() const {return nome;}
    void getQuantita(const short int qt){quantita = qt;}
    void setPrezzo(const float prz) {prezzo = prz;}
    void setCodice(const short int cod){
        if(cod >= 0 && cod < 100){
            if (!(isTaken[cod])){
                codice = cod;
                isTaken[cod] = true;
            }
        }
        else{
            cout << "errore con il codice del file \n";
        }
    }
    void setNome(const std::string n){
        size_t length(n.size());
        length = (length < 36? length : 35);
        n.copy(nome, length);
        nome[length]= '\0';
    }



};

void createFile() {
    ofstream oArticoli{"hardware.dat", ios::out | ios::binary};
    if (!oArticoli){
        cerr << "Impossibile aprire il file" << std::endl;
        exit(EXIT_FAILURE);
    }

    Articolo mercanzia;

    for(int i{0}; i<100; ++i){
        oArticoli.write(reinterpret_cast<const char *>(&mercanzia), sizeof(Articolo));
    }
    oArticoli.close();

}
void fileWriting(){
    fstream scriviArticoli{"hardware.dat", ios::in | ios::out | ios::binary};
    if (!scriviArticoli){
        cerr << "Impossibile aprire il file" << std::endl;
        exit(EXIT_FAILURE);
    }
    short int codice, quantita;
    float prezzo;
    string nome;

    cout << "Scrivi codice articolo (1 a 100, 0 per finire input)";

    cin >> codice;
    
    while(codice > 0 && codice <= 100){
        cout << "Inserire nome articolo, quantità e prezzo";
        cin >> nome;
        cin >> quantita;
        cin >> prezzo;
        
        Articolo articolo{codice, quantita, prezzo, nome};

        scriviArticoli.seekp((articolo.getCodice()-1) * sizeof(Articolo));
        
        scriviArticoli.write(reinterpret_cast<const char*>(&articolo), sizeof(Articolo));


        cout << "continuare con l'inserimento di un nuovo articolo?";
        cin >> codice;
        
        }
    scriviArticoli.close();

}

void fileReading(){
    ifstream leggiArticoli("hardware.dat", ios::in | ios::binary);
    if (!leggiArticoli){
        cerr << "Impossibile aprire il file" << std::endl;
        exit(EXIT_FAILURE);
    }

    cout << std::left << std::setw(10)<<"Cod" << std::setw(37) << "Nome" << std::setw(5)<< "prezzo" << std::setw(15)<<std::right<<"quantità"<<std::endl;

    Articolo articolo;
    leggiArticoli.read(reinterpret_cast<char*>(&articolo), sizeof(Articolo));

    while(leggiArticoli){
        if(articolo.getCodice() != 0){
            outputLine(std::cout, articolo);
        }
        leggiArticoli.read(reinterpret_cast<char*>(&articolo), sizeof(Articolo));
    }

}

void outputLine(ostream& output, const Articolo& articolo) {
    output << std::left << std::setw(10) << articolo.getCodice()
    << std::setw(37) << articolo.getNome()
    << std::setw(5)<<std::setprecision(2)<<std::right<<std::fixed<<articolo.getPrezzo()
    << std::setw(15)<<std::right << articolo.getQuantita()<<std::endl;

}

void menu(){
    cout << "      ****     BENVENUTO       ***         ";
    Choice input;
    while((input=entraScelta()) !=Choice::USCITA){
        switch (input)
        {
        case Choice::MODIFICA:
            fileWriting();
            break;
        case Choice::LETTURA:
            fileReading();
            break;
        case Choice::RESET:
            createFile();
            break;
        
        default:
            cerr<< "Ingresso non corretto";
            break;
        } 
    };
}

Choice entraScelta() {
    cout <<" \n Selezionare opzione \n1---- modifica File \n2---- leggi file  \n3---- reset valori\n4----esci";
    int scelta;
    cin >> scelta;
    return static_cast<Choice>(scelta);
}
