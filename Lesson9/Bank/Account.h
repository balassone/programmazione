#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
class Account{
public:	
	explicit Account(const double&);
	Account& credit(const double&);
	Account& debit(const double&);
	double getAmount() const;
	Account& setAmount(const double&);
	virtual std::string toString();
	virtual ~Account()=default;
private:
	double amount;
};
#endif
