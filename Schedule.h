#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//schedule class:
//add on time
//view remaining time
//set time range

class Schedule{

public:
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


    void addSchedule(Schedule* schedule);
    void displaySchedule() const;
    shared_ptr<Schedule> createSchedule();
    Schedule(shared_ptr<MyTime> on, shared_ptr<MyTime> off) : onTime(on), offTime(off) { }

private:
    shared_ptr<MyTime> onTime;
    shared_ptr<MyTime> offTime;


    friend ostream& operator<<(ostream& os, const Schedule& s) {
        os << "Turns on at " << s.onTime->hours << ":" << (s.onTime->mins < 10 ? "0" : "") << s.onTime->mins;
        os << ", turns off at " << s.offTime->hours << ":" << (s.offTime->mins < 10 ? "0" : "") << s.offTime->mins;
        return os;
    }

};

