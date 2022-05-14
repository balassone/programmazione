#include "Article.h"
#include <string>
#include <sstream>
Article::Article(const int& c, const std::string& n, const int& q, const double& p) : code{-1}, name{""}, qty{0}, pricing{0.00} {
	setCode(c);
	setName(n);
	setQty(q);
	setPricing(p);
}
Article::Article() : Article(0,"",0,0) {}
Article& Article::setCode(const int& c){
	if (c>=0 && c <100){
		code=c;
	}
	return *this;
}

int Article::getCode() const{
	return code;
}

Article& Article::setName(const std::string& n){
	size_t length=n.length();
	length=(length<15 ? length : 14);
	n.copy(name,length);
	name[length]='\0';
	return *this;
}

std::string Article::getName() const{
	return name;
}

Article& Article::setQty(const int& q){
	qty=q;
	return *this;
}

int Article::getQty() const {return qty;}

Article& Article::setPricing(const double& p){pricing=p; return *this;}

double Article::getPricing() const {return pricing;}

std::string Article::toString(){
	std::ostringstream out;
	out << getCode() << "\t" << getName() << "\t" << getQty() << "\t" << getPricing();
	return out.str();
}
