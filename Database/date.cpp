#include <iomanip>
#include <tuple>
#include "date.h"


size_t Date::GetYear() const { return year_; }
size_t Date::GetMonth() const { return month_; }
size_t Date::GetDay() const { return day_; }

Date ParseDate(std::istream& stream) {
	size_t year, month, day;
	stream >> year;
	stream.ignore(1);
	stream >> month;
	stream.ignore(1);
	stream >> day;
	return Date(year, month, day);
}

ostream& operator<< (ostream& stream, const Date& date) {
	stream << setfill('0');
	stream << setw(4) << date.GetYear() << '-';
	stream << setw(2) << date.GetMonth() << '-';
	stream << setw(2) << date.GetDay();
	return stream;
}

bool operator< (const Date& lhs, const Date& rhs) {
	auto lhs_key = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
	auto rhs_key = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
	return lhs_key < rhs_key;
}

bool operator> (const Date& lhs, const Date& rhs) {
	auto lhs_key = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
	auto rhs_key = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
	return lhs_key > rhs_key;
}

bool operator== (const Date& lhs, const Date& rhs) {
	auto lhs_key = make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay());
	auto rhs_key = make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
	return lhs_key == rhs_key;
}

bool operator<= (const Date& lhs, const Date& rhs) {
	return !(lhs > rhs);
}
bool operator>= (const Date& lhs, const Date& rhs) {
	return !(lhs < rhs);
}
bool operator!= (const Date& lhs, const Date& rhs) {
	return !(lhs == rhs);
}