#pragma once
#include "Device.h"

using namespace chrono;

// TEMPRATURE & HUMIDITY SENSOR

class Sensor :
    public Device
{
private:
    steady_clock::time_point start = high_resolution_clock::now();      // start usage timer
    int usage = 0;
    float temperature = 0;
    int humidity = 0;

public:
    Sensor(const string& name, bool on = 1, int humd = 0, float temp = 0.0f) : Device(name, on), temperature(temp), humidity(humd) {}

    void quickView() override;  //one click action
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

    float getTemp() const;
    int getHumd() const;
    void displayUsage();

};

