#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>
#include<vector>
class Publication{
public:
	Publication(const std::vector<std::string>&, const std::string&, const int&);
	const std::vector<std::string>& getAuthors();
	Publication& setAuthors(const std::vector<std::string>&);

	bool operator<(const Publication&);

	virtual std::string toString();

private:
	std::string title;
	std::vector<std::string> authors;
	int year{1800};
};


#endif
