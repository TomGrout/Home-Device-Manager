#include "Schedule.h"



//Schedule::Schedule(const string& name){
//    std::time_t now = std::time(0);
//    onTime.tm_hour = 0;
//    offTime.tm_hour = 0;
//}
//
//ostream& operator<<(ostream& os, const Schedule& t)
//{
//    os << t.onTime.tm_hour << "hrs, " << t.onTime.tm_min << "mins." << endl;
//    return os;
//}
//
//ostream& operator<<(ostream& os, const Schedule::timer& t)
//{
//    os << t.start.tm_hour << "hrs, " << t.start.tm_min << "mins." << endl;
//    return os;
//}
//
//void Schedule::setOnTime(int hour, int minute) {
//    onTime.tm_hour = hour;
//    onTime.tm_min = minute;
//    std::cout << "On time set to "
//        << hour << ":" << minute << "\n";
//}
//
//void Schedule::setOffTime(int hour, int minute) {
//    offTime.tm_hour = hour;
//    offTime.tm_min = minute;
//    std::cout << "Off time for set to "
//        << hour << ":" << minute << "\n";
//}
//
//tm Schedule::addTime(const tm& original, int hours, int minutes, int seconds) {
//    time_t originalTime = mktime(const_cast<tm*>(&original));
//    originalTime += seconds + (minutes * 60) + (hours * 3600);
//    return;
//}
//
//void Schedule::addTimeToTimer(bool isOnTime, int hours, int minutes, int seconds) {
//    if (isOnTime) {
//        onTime = addTime(onTime, hours, minutes, seconds);
//        std::cout << "On time is now "
//            << onTime.tm_hour << ":" << onTime.tm_min << "\n";
//    }
//    else {
//        offTime = addTime(offTime, hours, minutes, seconds);
//        std::cout << "Off time is now  "
//            << offTime.tm_hour << ":" << offTime.tm_min << "\n";
//    }
//}
//
//void Schedule::setTimer(int hours, int minutes, int seconds) {
//    //if (!IsOn()) {
//    //    turnOn();
//    //}
//    std::cout << "Setting timer: "
//        << hours << " hours, " << minutes << " minutes, "
//        << seconds << " seconds.\n";
//
//    // Calculate the new off time based on current time
//    std::time_t now = std::time(0);
//    std::tm currentTime = *std::localtime(&now);
//    std::tm newOffTime = addTime(currentTime, hours, minutes, seconds);
//
//    // Schedule turn off
//    offTime = newOffTime;
//    std::cout << " will turn OFF at "
//        << offTime.tm_hour << ":" << offTime.tm_min << "\n";
//}
//
//void Schedule::addDeviceTimer(const std::string& device, int startHour, int startMinute, int endHour, int endMinute) {
//    timer t;
//    std::time_t now = std::time(0);
//    t.start = *std::localtime(&now);
//    t.start.tm_hour = startHour;
//    t.start.tm_min = startMinute;
//
//    t.end = *std::localtime(&now);
//    t.end.tm_hour = endHour;
//    t.end.tm_min = endMinute;
//
//    deviceTimers[device] = t;
//
//    std::cout << "Added timer for device '" << device << "' from "
//        << startHour << ":" << startMinute << " to "
//        << endHour << ":" << endMinute << ".\n";
//}
//
//void Schedule::showDeviceTimers() const {
//    std::cout << "Device Timers:\n";
//    map<string, timer>::const_iterator it = deviceTimers.begin();
//
//    while (it != deviceTimers.end()) {
//        cout << "Device name: " << it->first
//            << ", Schedule: " << it->second << endl;
//        ++it;
//    }
//}
//
//void Schedule::showRemainingTime() const {
//    std::cout << "Schedule for " << ":\n";
//
//    if (!deviceTimers.empty()) {
//        Schedule::showDeviceTimers();
//    }
//    else {
//        std::cout << "  No additional device timers set.\n";
//    }
//}
