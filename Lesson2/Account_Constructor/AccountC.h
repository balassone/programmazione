#include<string>

class Account{
public:

	explicit Account(std::string acName)

		 : name{acName} {
	
	}

	void setName(std::string acName){

		name = acName;

	}

	std::string getName() const{

		return name;
}
private:
	std::string name;
};
