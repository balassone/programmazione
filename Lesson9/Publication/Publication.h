#ifndef PUBLICATION_H
#define PUBLICATION_H
#include <string>
#include <vector>
class Publication{
public:
	//constructor
	Publication(const std::vector<std::string>&, const std::string&, const int&);
	//get and set
	const std::vector<std::string>& getAuthors();
	Publication& setAuthors(const std::vector<std::string>&);
	//...
	//comparison
	bool operator<(const Publication&);
	//print
	virtual std::string toString();

private:
	std::string title;
	std::vector<std::string> authors;
	int year{1800};
};


#endif
