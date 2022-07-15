//Program calculating Body Mass Index (BMU)
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main () {
  float weight{0};
  float height{0};

  cout<<"Ciao, questo programma calcola l'indice di massa corporea.\n Inserisci il tuo peso(kg): "<<endl;
  cin>>weight;
  cout<<"Adesso inserisci la tua altezza(m): "<<endl;
  cin>>height;

  float BMI=(weight)/(height*height);

  cout<<"Il tuo indice di massa corporea è: "<<BMI<<endl<<endl<<endl;
  cout<<"Tabella dei valori: \n";
  cout<<"Sottopeso: BMI minore di 18.5 \n";
  cout<<"Normale: BMI compreso tra 18.5 e 24.9 \n";
  cout<<"Sovrappeso: BMI compreso tra 25 e 29.9 \n";
  cout<<"Obeso: BMI maggiore o uguale a 30 \n";
  
  return 0;
}
