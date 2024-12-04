#pragma once
#include "Device.h"

class Speaker :
    public Device
{
private:
    bool playing;
    int volume;

public:
    Speaker(string name, bool on, int vol = 0) : Device(name, on), volume(vol) { playing = on; }

    void quickView() override;
    void displayInfo() override;
    void editProperty() override;
    void oneClick() override;
    string getValue() const override;

    void setVolume(int v);
    void setVolume();
    void play();
    void stop();
};

