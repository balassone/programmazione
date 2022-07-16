#ifndef DATE_H
#define DATE_H
#include <string>
#include <sstream>
#include <vector>
class Date{
    friend std::ostream& operator<<(std::ostream&, const Date&);
    public:
        explicit Date(const int& d=1, const int& m=1, const int& y=1900);
        Date(const Date&);
        Date& operator=(const Date&);
        const int& getDay() const;
        Date& setDay(const int& d);
        const int& getMonth() const;
        Date& setMonth(const int& m);
        const int& getYear() const;
        Date& setYear(const int& y);
        std::string toString() const; 
        bool operator==(const Date&) const;
        bool operator<(const Date&) const;
    private:
        int day;
        int month;
        int year;
        std::vector<int> days{31,28,31,30,31,30,31,31,30,31,30,31};
};
#endif