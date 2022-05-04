#ifndef CONVEGNI_H
#define CONVEGNI_H
#include "Publication.h"
#include <vector>
#include <string>

class Convegno: public Publication{
	public:
		static int convCount;
		Convegno(const std::vector<std::string>&, const std::string&, const int&, const std::string&, const std::string&, const int&);

		~Convegno();
		std::string toString();
	private:
		std::string convtitle;
		std::string convloc;
		int numpg;
};
#endif
