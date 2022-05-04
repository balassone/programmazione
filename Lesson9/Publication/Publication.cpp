#include "Publication.h"
#include<sstream>
Publication::Publication (const std::vector<std::string>& au, const std::string& ti, const int& yr):
	authors(au), title(ti), year(yr) {}

const std::vector<std::string>& Publication::getAuthors() {return authors;}

Publication& Publication::setAuthors(const std::vector<std::string>& au){

	authors=au;
	return *this;
}

bool Publication::operator<(const Publication& B){

	if(authors==B.authors) return year<B.year;
	return authors<B.authors;
}

std::string Publication::toString(){
	std::ostringstream out;
	out << " -\t ";

	for(int i{0}; i<authors.size();i++){
		out << authors[i];
		out<<(i==authors.size()-1)?" ":",";
	}
	out<<"("<<year<<")"<<title<<" ";
	return out.str();
}