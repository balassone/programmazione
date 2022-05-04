#include "Convegni.h"
#include <vector>
#include <string>
#include <sstream>
Convegno::Convegno(const std::vector<std::string>& au, const std::string& tle, const int& yr, const std::string& convtle, const std::string& convl, const int&pg) : Publication(au,tle,yr), convtitle{convtle}, convloc{convl}, numpg{pg} {convCount++;}

Convegno::~Convegno(){convCount--;}

std::string Convegno::toString(){
	std::ostringstream out;
	out << Publication::toString() << convtitle << convloc << numpg;
	return out.str();
}
