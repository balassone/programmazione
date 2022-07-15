#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
int Lcs(string&,string&,int,int);
int max(int,int);

int main(){

    string c1{"ciao"};
    string c2{"casa"};
    int l1=0;
    int l2=0;
    int tab[100][100];

    for(unsigned int i=0; i<c1.length(); i++){
        l1++;
        for(unsigned int j=0; j<c2.length(); j++){
            l2++;
            tab[l1][l2]=tab[i][j];
        }
    }



    for(int i=0;i<l1;i++){
        tab[i][0]=Lcs(c1,c2,i,0);
    }
    for(int j=0; j<l2;j++){
        tab[0][j]=Lcs(c1,c2,0,j);
    }

    for(int i=1;i<l1;i++){
        for(int j=1;j<l2;j++){
            tab[i][j]=Lcs(c1,c2,i,j);
        }
    }

    for(int i=0;i<l1;i++){
        for(int j=0; j<l2; j++)
            cout<<tab[i][j];
        }

    //cout<<"La Lsc è "<<tab[l1][l2];
    




}

int Lcs(string& c1, string& c2,int l1,int l2){
    if(l1==0 || l2==0) return 0;
    else if(c1[l1]==c2[l2]){
        return 1+Lcs(c1,c2,l1-1,l2-1);
    }
    else{
        return max(Lcs(c1,c2,l1,l2-1),Lcs(c1,c2,l1-1,l2));
    }
}
    
    int max(int x, int y){
    int max=(x>y)? x:y;
    return max;
}
