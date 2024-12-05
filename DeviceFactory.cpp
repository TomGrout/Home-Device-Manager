#include "DeviceFactory.h"

Device* DeviceFactory::createDevice(const string& type, const string& name, const bool& state)
{
    if (type == "lights" || type == "light") return(new Lights(name, state));
    else if (type == "sensor" || type == "temperaturehumiditysensor") return(new Sensor(name, 1));
    else if (type == "speaker") return(new Speaker(name, state));
    else if (type == "socket") return(new Socket(name, state));
    else if (type == "thermostat") return(new Thermostat(name, state));
    else if (type == "radiator") return(new Radiator(name, state));
    else {
        cout << "warning: could not create device\a" << endl;
        return nullptr;
    }

}
