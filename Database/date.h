#pragma once

#include <iostream>

using namespace std;

class Date {
public:
	Date(size_t year, size_t month, size_t day) :
		year_(year), month_(month), day_(day) {}
	size_t GetYear() const;
	size_t GetMonth() const;
	size_t GetDay() const;
private:
	const size_t year_;
	const size_t month_;
	const size_t day_;
};

Date ParseDate(istream& stream);

ostream& operator<< (ostream& stream, const Date& date);

bool operator< (const Date& lhs, const Date& rhs);
bool operator<= (const Date& lhs, const Date& rhs);
bool operator> (const Date& lhs, const Date& rhs);
bool operator>= (const Date& lhs, const Date& rhs);
bool operator== (const Date& lhs, const Date& rhs);
bool operator!= (const Date& lhs, const Date& rhs);

