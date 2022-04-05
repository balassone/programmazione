#include<string>
#include<cmath>

class DollarAmount{
public:
	explicit DollarAmount(const int64_t&);
	explicit DollarAmount(const int64_t&, const int64_t&);
	void add(const DollarAmount&);
	void subtract(const DollarAmount&);
	void divide(const int&);
	void addInterest(const int& rate, const int& divisor);
	std::string toString() const;
private:
	int64_t amount;
};
