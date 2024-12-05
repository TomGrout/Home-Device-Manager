#pragma once
#include "Device.h"
#include "Lights.h"
#include "Speaker.h"
#include "Sensor.h"
#include "Socket.h"
#include "Thermostat.h"
#include "Radiator.h"

using namespace std;

class DeviceFactory
{
private:
    DeviceFactory() {} 
    ~DeviceFactory() {} 

    DeviceFactory(const DeviceFactory&) = delete;            
    DeviceFactory& operator=(const DeviceFactory&) = delete; 

public:
    static DeviceFactory& instance() {
        static DeviceFactory factoryInstance; 
        return factoryInstance;
    }
    Device* createDevice(const string& type, const string& name, const bool& state);
};

