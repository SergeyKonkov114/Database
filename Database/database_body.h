#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "date.h"
#include "EventStorage.h"

using namespace std;

struct EventInfo {
	Date date;
	string event;
};

ostream& operator<< (ostream& stream, const EventInfo& event_info);

class Database {
public:
	void Add(const Date& date, const string& event);

	void Print(ostream& stream) const;

	template <typename Predicate>
	int RemoveIf(Predicate predicate) {
		int result = 0;
		for (auto& item : database) {
			const Date& date = item.first;
			result += item.second.RemoveIf([predicate, date](const string& event) {
				return predicate(date, event);
				});
		}
		for (auto it = begin(database); it != end(database); ) {
			if (it->second.GetEvents().empty()) {
				database.erase(it++);
			}
			else {
				it++;
			}
		}
		return result;
	}

	template <typename Predicate>
	vector<EventInfo> FindIf(Predicate predicate) const {
		vector<EventInfo> correct_events;
		for (const auto& item : database) {
			for (const auto& event : item.second.GetEvents()) {
				if (predicate(item.first, event)) {
					correct_events.push_back(EventInfo{ item.first, event });
				}
			}
		}
		return correct_events;
	}

	EventInfo Last(const Date& date) const;

private:
	map<Date, EventsStorage> database;
};
