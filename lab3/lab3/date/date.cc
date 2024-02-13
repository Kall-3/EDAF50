#include <ctime>  // time and localtime
#include <ostream>
#include <istream>
#include <sstream>
#include <string>
#include "date.h"

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
}
//
// Overload << operator for output
std::ostream& operator<<(std::ostream& output, const Date& date) {
    const int y = date.getYear();
    std::string year = (y > 999) ? std::to_string(date.getYear()) : ((y > 99) ? '0' + std::to_string(date.getYear()) : "00" + std::to_string(date.getYear()));
    std::string month = (date.getMonth() > 9) ? std::to_string(date.getMonth()) : '0' + std::to_string(date.getMonth());
    std::string day = (date.getDay() > 9) ? std::to_string(date.getDay()) : '0' + std::to_string(date.getDay());

    output << year << "-" << month << "-" << day;
    return output;
}

// Overload >> operator for input
std::istream& operator>>(std::istream& input, Date& date) {
    char dash = '-';
    int year, month, day;
    input >> year >> dash >> month >> dash >> day;

    if (!input || year < 0 || month < 0 || month > 12 || day < 0 || day > date.daysPerMonth[date.month]) {
        // Input validation: set state to fail if input is incorrect
        input.setstate(std::ios::failbit);
    } else {
        date.year = year, date.month = month, date.day = day;
    }
    return input;
}

int Date::getYear() const {
	return this->year;
}

int Date::getMonth() const {
	return this->month;
}

int Date::getDay() const {
	return this->day;
}

void Date::next() {
    int month_carry = (this->day / daysPerMonth[this->month - 1]);
    this->day = (this->day % daysPerMonth[this->month - 1]) + 1;

    int year_carry = (this->month + month_carry) / 12;
    this->month = (this->month + month_carry) % 12;
 
    this->year = this->year + year_carry;
}

