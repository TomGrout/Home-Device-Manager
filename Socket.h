#pragma once
#include "Device.h"
#include "SleepTimer.h"
#include "Schedule.h"

using namespace chrono;

class Socket :
    public Device
{
private:
    steady_clock::time_point start = high_resolution_clock::now();      // start usage timer
    int usage;
    SleepTimer timer;
    unique_ptr<Schedule> schedule = nullptr;
    vector<shared_ptr<Schedule>> entries;

public:
    Socket(string name, bool on, int usage = 0) : Device(name, on), usage(usage) {}

    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

    void displayUsage();
    void startTimer(int mins);
    void displaySchedule() const;
};

