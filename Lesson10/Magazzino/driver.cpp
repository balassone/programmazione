#include "Article.h"
#include <fstream>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ios;

void newRecord(fstream&);
void deleteRecord(fstream&);
void updateRecord(fstream&);
void printList(fstream&);

int main(){
	int choice{0};
	bool lexit=0;
	fstream file;
	if(!file){
		std::cerr << "Il file non puo' essere aperto!" << endl;
		exit(EXIT_FAILURE);
	}

	while(!lexit){
		file.open("hardware.dat", ios::in | ios::out | ios::binary);
		cout << "*** Programma di gestione magazzino ***" << endl;
		cout << "\n1. Inserire un articolo.";
		cout << "\n2. Cancellare un articolo.";
		cout << "\n3. Aggiornare un articolo.";
		cout << "\n4. Stampa articoli.";
		cout << "\n5. Esci"<<endl;
		do{
			cout << "Inserisci scelta: "; cin>>choice;
		}while(choice>5 && choice<1);

		switch(choice){

			case 1:
				newRecord(file);
				break;
			case 2:
				deleteRecord(file);
				break;
			case 3:
				updateRecord(file);
				break;
			case 4:
				printList(file);
				break;
			case 5:
				lexit=true;
				break;
		}
		file.close();
	}
	
	return 0;
}

void printList(fstream& file){
	Article art;
	file.read(reinterpret_cast<char*>(&art), sizeof(Article));
	while(file){
		if(art.getCode() != 0){
			cout << art.toString() << endl;
		}
		file.read(reinterpret_cast<char*>(&art), sizeof(Article));
	}
}

void newRecord(fstream& file){
	int c;
	std::string n;
	int q;
	double p;
	cout << "Inizializza articolo (codice, nome, qty e prezzo): ";
	cin >> c >> n >> q >> p;
	Article ar{c,n,q,p};
	file.seekp((ar.getCode()-1)*sizeof(Article));
	file.write(reinterpret_cast<char*>(&ar), sizeof(Article));
	
}

void deleteRecord(fstream& file){
	Article ar;
	int num;
	cout << "Numero record da eliminare: ";
	cin >> num;
	file.seekp((num-1)*sizeof(Article));
	file.write(reinterpret_cast<char*>(&ar), sizeof(Article));
}

void updateRecord(fstream& file){
	int num;
	cout << "Che record vuoi modificare? ";
	cin >> num;
	std::string n;
	int q;
	double p;
	cout << "Cambia nome, qty e prezzo: ";
	cin >> n >> q >> p;
	Article ar(num,n,q,p);
	file.seekp((num-1)*sizeof(Article));
	file.write(reinterpret_cast<char*>(&ar), sizeof(Article));
}
