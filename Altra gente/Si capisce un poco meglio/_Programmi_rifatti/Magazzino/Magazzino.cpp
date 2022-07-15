//Magazzino.cpp
#include"Articolo.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using std::string;
using std::fstream;
using std::ofstream;
using std::ios;
using std::ostream;
using std::cout; using std::endl; using std::cerr; using std::cin;

enum class Choice {NEW=1, DELETE, UPDATE, PRINT, EXIT};

Choice enterchoice();

void outputLine(ostream&, const Articolo&);
int getNumber();
void createNewArticle(fstream&);
void updateArticle(fstream&);
void deleteArticle(fstream&);
void printList(fstream&);
void creatingTextFile(fstream&);


int main() {
    fstream inOutFile("hardware.dat", ios::out | ios::in | ios::binary);
    if(!inOutFile){
       cerr<<"File could not be opened"<<endl;
       exit(EXIT_FAILURE);
    }
    

    Choice choice;
    while ((choice=enterchoice()) != Choice::EXIT){
        switch (choice) {
            case Choice::NEW :
                createNewArticle(inOutFile);
                break;
            case Choice::UPDATE :
                updateArticle(inOutFile);
                break;
            case Choice::DELETE :
                deleteArticle(inOutFile);
                break;
            case Choice::PRINT :
                printList(inOutFile);
                break;
            default:
                cerr<<"Not valid choice"<<endl;
                break;
        }
        inOutFile.clear();
        creatingTextFile(inOutFile);
        inOutFile.clear();
        cout<<"Do you want to exit? (y or n)"<<endl;
        char s;
        cin>>s;
        if(s=='y') break;
    }
}

Choice enterchoice(){
    cout<<"Enter your choice:\n"
    <<"1 - Create new article\n"
    <<"2 - Delete an article\n"
    <<"3 - Update an existing article\n"
    <<"4 - Print list of existing articles\n"
    <<"5 - Exit\n\n?";
    int choice;
    cin>>choice;
    return static_cast<Choice>(choice);
}

void createNewArticle(fstream& file) {
    Articolo art;
    int n=getNumber();
    file.seekg((n-1)* sizeof(Articolo));
    file.read(reinterpret_cast<char*>(&art), sizeof(Articolo));

    if(art.getCodice() == 0){
        string name;
        int qty;
        double val;
        cout<<"Enter article's name\n?"; 
        cin>>name;
        cout<<"Enter quantity\n?";
        cin>>qty;
        cout<<"Enter price($)\n?";
        cin>>val;

        art.setCodice(n);
        art.setNome(name);
        art.setQuantita(qty);
        art.setPrezzo(val);

        file.seekp((n-1)*sizeof(Articolo));
        file.write(reinterpret_cast<const char*>(&art), sizeof(Articolo));
    }
    else {
        cerr<< "Account #"<<n<<" already exists."<<endl;
    }
}

void updateArticle(fstream& file) {
    int n = getNumber();
    Articolo art;
    file.seekg((n-1)*sizeof(Articolo));
    file.read(reinterpret_cast<char*> (&art) ,sizeof(Articolo));
    if (art.getCodice() == 0) {
        cerr<<"Article does not exist."<<endl;
    }
    else {
        outputLine(cout, art);      //display the record
        cout<<"Specify name of article (eventually can be changed)"<<endl;
        string nom;
        cin>>nom;
        art.setNome(nom);
        
        cout<<"Quantity?"<<endl;
        int q;
        cin>>q;
        art.setQuantita(q);
        
        cout<<"Price per item($) ?"<<endl;
        double price;
        cin>>price;
        art.setPrezzo(price);

        file.seekp((n-1)* sizeof(Articolo));
        file.write(reinterpret_cast<const char*>(&art), sizeof(Articolo));
    }
}

void deleteArticle(fstream& file){
    int number = getNumber();
    Articolo art;
    file.seekg((number-1)*sizeof(Articolo));
    file.read(reinterpret_cast<char*>(&art), sizeof(Articolo));
    if (art.getCodice() != -1){
        Articolo articoloVuoto;
        file.seekp((number-1)*sizeof(Articolo));
        file.write(reinterpret_cast<const char*>(&articoloVuoto), sizeof(Articolo));

        cout<<"Account #"<<number<<" deleted.\n";
    }
    else {
        cerr<<"Account #"<<number<<" is empty"<<endl;
    }
}

void printList(fstream& file){
    file.seekg(0);
    while (!file.eof()){
        Articolo art;
        file.read(reinterpret_cast<char*>(&art), sizeof(Articolo));
        if (art.getCodice() != 0){
            outputLine(cout, art);
        }
    }
}

int getNumber() {
    cout<<"Enter article number"<<endl;
    int n;
    cin>>n;
    while(n<0 || n>99){
        cout<<"Number must be 0-99\n?"<<endl;
        cin>>n;
    }
    return n;
}

void outputLine (ostream& out, const Articolo& art){
    out<<std::left<<std::setw(8)<<art.getCodice()<<std::setw(20)<<art.getNome()
    <<std::setw(6)<<art.getQuantita()<<std::right<<std::showpoint<<art.getPrezzo()<<endl;
}

void creatingTextFile(fstream& readFromFile){
    ofstream outFile("Magazzino.txt", ios::out);
    
    if (!outFile){
        cerr<<"File could not be created"<<endl;
        exit(EXIT_FAILURE);
    }
    outFile<<std::left<<std::setw(8)<<"Codice"<<std::setw(20)<<"Nome"
    <<std::setw(10)<<"Quantita"<<std::right<<std::showpoint<<"Prezzo($)"<<endl;

    readFromFile.seekg(0);
    Articolo art;
    while (!readFromFile.eof()){
        readFromFile.read(reinterpret_cast<char*>(&art), sizeof(Articolo));
        if (art.getCodice() != 0){
            outputLine(outFile, art);
        }
    }
    outFile.close();
}