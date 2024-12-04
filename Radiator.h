#pragma once
#include "Device.h"

class Radiator :
    public Device
{
private:
    float temperature;

public:
    Radiator(string name, bool on, float temp = 0.0f) : Device(name, on), temperature(temp) {}

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

};

