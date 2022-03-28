#include <string>

class Account{

public:

	void setName(std::string acName){

		name=acName;

	}

	std::string getName() const{

		return name;

	}

private:

	std::string name;

};
