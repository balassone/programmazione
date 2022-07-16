#ifndef DATE_H
#define DATE_H

#include<array>
#include<iostream>

class Date{
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	explicit Date(int d=1, int m=1, int y=1900);
	bool operator<(const Date&) const;
	bool operator==(const Date& d) const {return year==d.year&&month==d.month&&day==d.day;}
private:
	int day;
	int month;
	int year;
	static const std::array<int, 13> days;
};

#endif
