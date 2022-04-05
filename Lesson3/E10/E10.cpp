#include "E10.h"

DollarAmount::DollarAmount(const int64_t& newAmount)
: amount{0} {
	if(newAmount>0){
		amount=newAmount;
	}
}
DollarAmount::DollarAmount(const int64_t& dollars, const int64_t& cents)
: amount{0} {
	if(dollars>0){
		amount+=(dollars*100);
	}
	if (cents>0){
		amount+=cents;
	}	
}

void DollarAmount::add(const DollarAmount& right){
	amount+=right.amount;
}

void DollarAmount::subtract(const DollarAmount& right){
	amount-=right.amount;
}
void DollarAmount::divide(const int& divisor){
	if(amount%divisor>4&& amount%divisor<10){
		amount=(amount/divisor)+100;
	} else {
		amount=(amount/divisor);
	}
}
void DollarAmount::addInterest(const int& rate, const int& divisor){
	DollarAmount interest{(amount * rate + divisor/2)/divisor};
	add(interest);
}

std::string DollarAmount::toString() const{
	std::string dollars{std::to_string(amount/100)};
	std::string cents{std::to_string(std::abs(amount%100))};
	return dollars + "." + (cents.size()==1?"0":"") + cents;
}
