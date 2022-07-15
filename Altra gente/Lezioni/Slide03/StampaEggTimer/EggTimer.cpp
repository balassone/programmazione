#include <iostream>

using std::cout;

int main(){
	
	for(int i=0; i<9;i++){
		for(int k=0; k<9; k++){
			cout<<"#";
			switch (i){
				case 1 :
				case 7 :
				{
					for(;k<7;k++)
					cout <<"*";
				}
				break;
				case 2:
				case 6:
				{
					for(;k<7;k++){
						if(k==0 || k==6)
							cout <<" ";
						else 
							cout <<"*";
					}
				}
				case 3:
				case 5:
				{
					for(;k<7;k++){
						if(k<2 || k>4)
							cout <<" ";
						else 
							cout <<"*";
					}
				}
				case 4:
				{
					for(;k<7;k++){
						if(k==3)
							cout <<"*";
						else 
							cout <<" ";
					}
				}
				default:
				cout <<"";
			}
			
		}
		cout<<"\n";
	}
	
}