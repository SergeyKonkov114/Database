#include "EventStorage.h"

void EventsStorage::Add(const string& event) {
	auto result = events_set_.insert(event);
	if (result.second) {
		events_.push_back(event);
	}
}

vector<string> EventsStorage::GetEvents() const {
	return events_;
}