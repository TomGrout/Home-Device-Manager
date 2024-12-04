#include "Schedule.h"

void Schedule::addSchedule(const MyTime& on, const MyTime& off) {
    entries.emplace_back(on, off);
}

void Schedule::displaySchedule() const {
    for (const auto& entry : entries) {
        std::cout << entry << "\n";
    }
}
