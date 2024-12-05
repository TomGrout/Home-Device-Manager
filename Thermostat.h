#pragma once
#include "Device.h"
class Thermostat :
    public Device
{
private:
    float temperature;

public:
    Thermostat(string name, bool on, float temp = 0.0f) : Device(name, on), temperature(temp) { temperature = round(temperature); }

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

    void heatingBoost();
    void heatingBoost(int val);
};

