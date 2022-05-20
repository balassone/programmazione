#ifndef WWW_H
#define WWW_H
#include <vector>
#include <list>
class WWW{
	public:
		//evitiamo friend, usiamo l'incapsulamento
		class Page{
			public:
				Page(const int& id,const int& nl, const double& p) : pageID{id}, nLinks{nl}, P{p} {}
				friend class WWW; //Altrimenti non vedo le variabili private
			private:
				int pageID;
				int nLinks;
				double P;
		};
		WWW(int);
		void pageRank();
		void addLink(int,int);
		void printRanks();
	private:
		int nPages;
		std::vector<Page> pages;
		std::list<int> *web;
		double delta{0.001};
};
#endif
