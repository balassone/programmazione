#ifndef DATE_H
#define DATE_H

#include<array>
#include<iostream>

class Date{
	friend std::ostream& operator<<(std::ostream&, const Date&);
public:
	explicit Date(int d=1, int m=1, int y=1900);
	void setDate(int, int, int);
	static bool leapYear(int);
	bool operator<(const Date&) const;
private:
	int day;
	int month;
	int year;
	static const std::array<int, 13> days;
};

#endif
