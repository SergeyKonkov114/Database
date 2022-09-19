#pragma once

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class EventsStorage {
public:
	void Add(const string& event);

	vector<string> GetEvents() const;

	template<typename Predicate>
	int RemoveIf(Predicate predicate) {
		auto it = stable_partition(begin(events_), end(events_), predicate);
		int result = static_cast<int>(it - begin(events_));
		for (auto i = begin(events_); i != it; ++i) {
			events_set_.erase(*i);
		}
		events_.erase(begin(events_), it);
		return result;
	}

private:
	vector<string> events_;
	set<string> events_set_;
};
