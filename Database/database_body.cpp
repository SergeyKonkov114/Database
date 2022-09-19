#include "database_body.h"
#include <algorithm>
#include <iomanip>
#include <utility>


void Database::Add(const Date& date, const string& event) {
	database[date].Add(event);
}

void Database::Print(ostream& stream) const {
	for (const auto& item : database) {
		for (const auto& event : item.second.GetEvents()) {
			stream << item.first << ' ' << event << endl;
		}
	}
}

EventInfo Database::Last(const Date& date) const {
	auto last = database.upper_bound(date);
	if (last == begin(database)) {
		throw invalid_argument("No entries");
	}
	--last;
	return EventInfo{ last->first, last->second.GetEvents().back() };
}

ostream& operator<< (ostream& stream, const EventInfo& event_info) {
	stream << event_info.date << ' ' << event_info.event;
	return stream;
}