#pragma once
#include "Device.h"
#include "Schedule.h"

class Radiator :
    public Device
{
private:
    float temperature;
    unique_ptr<Schedule> schedule;

public:
    Radiator(string name, bool on, float temp = 0.0f) : Device(name, on), temperature(temp), schedule(nullptr) {}

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

};

    