#include "WWW.h"
#include <list>
#include <iostream>
WWW::WWW(int n){
	web = new std::list<int>[n];
	for (int i{0}; i<n;++i){
		Page p(i,0,static_cast<double>(1.0)/n);
		pages.push_back(p);
	}
}

void WWW::addLink(int pa, int pb){
	//Inserire pagina b nella lista della pagina a
	web[pa].push_front(pb);
	pages[pa].nLinks++;
}

void WWW::pageRank(){
	double *newP=new double[nPages];
	for(int i=0; i<nPages; ++i){
		for(auto j{web[i].begin()}; j!= web[i].end(); ++j){
			newP[*j]+=pages[i].P/pages[i].nLinks;
		}
	}
	for(int i{0}; i<nPages; ++i){
		pages[i].P=(1.0-delta)/nPages +delta*newP[i];
	}
}

void WWW::printRanks(){
	for(int i{0}; i<nPages;++i){
		std::cout << "Page " << i << "\t ranks:" << pages[i].P << std::endl;
	}
}
