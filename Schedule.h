#pragma once
#include <vector>
#include <iostream>

using namespace std;

//schedule class:
//add on time
//view remaining time
//set time range

class Schedule{

    private:

        struct MyTime
        {
        public:
            int hours, mins;

            // constructor
            MyTime(int hrs = 0, int mns = 0) : hours(hrs), mins(mns) {}


            friend ostream& operator<<(ostream& os, const MyTime& t) {
                os << t.hours << ":" << (t.mins < 10 ? "0" : "") << t.mins;
                return os;
            }

            bool operator==(const MyTime& t) const {
                return hours == t.hours && mins == t.mins;
            }

            bool operator<(const MyTime& t) const {
                return hours < t.hours || (hours == t.hours && mins < t.mins);
            }
        };

        struct ScheduleEntry
        {
        private:
            MyTime onTime;
            MyTime offTime;

        public:
            ScheduleEntry(MyTime on, MyTime off) : onTime(on), offTime(off) {}

            friend ostream& operator<<(ostream& os, const ScheduleEntry& s) {
                os << "Turns on at " << s.onTime.hours << ":" << (s.onTime.mins < 10 ? "0" : "") << s.onTime.mins;
                os << "Turns off at " << s.offTime.hours << ":" << (s.offTime.mins < 10 ? "0" : "") << s.offTime.mins;
                return os;
            }
        };

     vector<ScheduleEntry> entries;

    public:
        void addSchedule(const MyTime& on, const MyTime& off);
        void displaySchedule() const;


};

