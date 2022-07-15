// Date.h
// Date class definition with overloaded increment operators
#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>

class Date {
  friend std::ostream& operator<<(std::ostream&, const Date&);
  friend Date operator+(int , const Date& );
  friend Date operator+(const Date&, int );
public:
  Date(int d=1, int m = 1, int y = 1900); // default constructor
  void setDate(int, int, int); // set month, day, year
  Date& operator++(); //prefix increment operator
  Date operator++(int); // postfix increment operator
  Date& operator+=(unsigned int); // add days, modify object

  // EXERCISE
   bool operator >(const Date& ) const;
  bool operator >=(const Date&) const;
  bool operator <=(const Date&) const;
  bool operator != (const Date& ) const;


  
  static bool leapYear(int); // is year a leap year?
  bool endOfMonth(int) const; // is day at the end of month?
  bool beginOfMonth(int) const; //
  bool operator <(const Date&) const;
private:
  unsigned int day;
  unsigned int month;
  unsigned int year;
  static const std::array<unsigned int, 13> days; // days per month
  void helpIncrement(); // utility function for incrementing date
  // void helpDecrement(); // utility function for decrementing date
};

#endif
