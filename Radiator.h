#pragma once
#include "Device.h"
#include "Schedule.h"

class Radiator :
    public Device
{
private:
    float temperature;
    unique_ptr<Schedule> schedule = make_unique<Schedule>();

public:
    Radiator(string name, bool on, float temp) : Device(name, on), temperature(temp), schedule(nullptr) { temperature += rand() % 4 - 2; }
    Radiator(string name, bool on) : Device(name, on), schedule(nullptr) { temperature = 0.0f + rand() % 25; }

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

};

    