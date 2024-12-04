#include "Device.h"

// constructor
Device::Device(const std::string& initialName, bool on) : name(initialName), On(on) {
    numOfDevices++;
}

// destructor
Device::~Device() {
    numOfDevices--;
}

void Device::setName() {
    cout << "\nNew name for " << this->getName() << ": ";
    std::string n;
    getline(cin >> ws, n);
    name = n;
    cout << getType().erase(0, 6) << " renamed to " << name << endl;
}

string Device::getName() const {
    return name;
}

string Device::getType() const {
    return (typeid(*this).name());
}

void Device::displayInfo() {
    cout << "\nDevice Name: " << name << endl;
    cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
}

bool Device::IsOn() const {
    return On == 1;
}

void Device::turnOn() {
	On = true;
}
void Device::turnOff() {
	On = false;
}
