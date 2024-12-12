#pragma once
#include "Device.h"
#include "SleepTimer.h"
#include "Schedule.h"

class Lights :
    public Device
{
private:
    int brightness = 0;
    SleepTimer timer;

public:
    Lights(string name, bool on, int brightness = 0) : Device(name, on), brightness(brightness) {}

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

    void setBrightness();
    void setBrightness(int val);
    void startTimer(int mins);

};

