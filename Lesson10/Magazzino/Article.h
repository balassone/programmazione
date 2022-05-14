#ifndef ARTICLE_H
#define ARTICLE_H
#include <string>
class Article{
public:
	Article(const int&,const std::string&, const int&, const double&);
	Article();
	Article& setCode(const int&);
	int getCode() const;
	Article& setName(const std::string&);
	std::string getName() const;
	Article& setQty(const int&);
	int getQty() const;
	Article& setPricing(const double&);
	double getPricing() const;
	std::string toString();
private:
	int code;
	char name[15];
	int qty;
	double pricing;
};
#endif
