#include "Article.h"
#include <sstream>
Article::Article(const std::vector<std::string>& au, const std::string& ti, const int& yr, const std::string& rivtle, const int& rivnm, int pg1, int pg2) : Publication{au, ti, yr}, rivtitle{rivtle}, rivnum{rivnm} {
	numpages=new int[2]{pg1,pg2};
	artCount++;
}

Article::~Article(){
	artCount--;
	delete[] numpages;
}

std::string Article::toString(){
	std::ostringstream out;
	out << Publication::toString() << " " << rivtitle << ", " << rivnum << " [" << numpages[0] << "," << numpages[1] << "]";
	return out.str();
}
