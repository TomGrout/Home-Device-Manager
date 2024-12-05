#include "Device.h"

// constructor
Device::Device(const std::string& initialName, bool on) : name(initialName), On(on) {
    numOfDevices++;
    srand(time(NULL));
}

// destructor
Device::~Device() {
    numOfDevices--;
}

void Device::setName() {
    cout << "\nNew name for " << name << ": ";
    std::string n;
    getline(cin >> ws, n);
    name = n;
    cout << getType().erase(0, 6) << " renamed to " << name << endl;
}

float Device::round(float value){
    float rounded = (int)(value * 100 + .5);
    return (float)rounded / 100;
}

string Device::getName() const {
    return name;
}

string Device::getType() const {
    return (typeid(*this).name());
}

void Device::quickView(){
    cout << getName() << " " << (IsOn() ? "[ON}" : "[OFF] ") << endl;
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
