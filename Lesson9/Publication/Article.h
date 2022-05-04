#ifndef ARTICLE_H
#define ARTICLE_H
#include "Publication.h"
#include <vector>
#include <string>
class Article: public Publication{
	public:
		static int artCount;
		
		Article(const std::vector<std::string>&, const std::string&, const int&, const std::string&, const int&, int, int);
		~Article();
		std::string toString();

	private:
		std::string rivtitle;
		int rivnum;
		int* numpages;
};
#endif
