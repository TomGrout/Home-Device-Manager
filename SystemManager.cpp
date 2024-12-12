#include "SystemManager.h"
 
SystemManager::SystemManager() {}

SystemManager* SystemManager::instantiation = NULL;
SystemManager* SystemManager::getSystemManager(){
    if (!instantiation)
        instantiation = new SystemManager();
    return instantiation;
}

SystemManager::~SystemManager(){
    for (Device* device : devices) {
        try {
            delete device;
        }
        catch (exception e) {
            cout << "A device could not be deleted\a" << endl;
        }
    }
    devices.clear();
}

// display all created devices
void SystemManager::displayAll() {
    vector<Device*>::iterator it(devices.begin());
    while (it != devices.end())
    {
        (*it)->displayInfo();
        it++;
    }
}

// load up devices from text file
void SystemManager::loadDevicesFromFile(const string& filename) {
    ifstream infile(filename);
    string name, type;
    bool state;
    int value;
    float flt;

    while (infile >> type >> name >> state){
        if (type == "Sensor") {
            infile >> value >> flt;
            devices.push_back(new Sensor(name, state, value, flt));
        }
        else if (type == "Thermostat") {
            infile >> flt;
            devices.push_back(new Thermostat(name, state, flt));
        }
        else if (type == "Radiator"){
            infile >> flt;
            devices.push_back(new Radiator(name, state, flt));
        }
        else {
            infile >> value;
            if (type == "Lights") devices.push_back(new Lights(name, state, value));
            else if (type == "Speaker") devices.push_back(new Speaker(name, state, value));
            else if (type == "Socket") devices.push_back(new Socket(name, state, value));

        }
    }
    infile.close();
}

// write created devices to text file
void SystemManager::saveDevicesToFile(const string& filename) {
    ofstream outfile(filename);
    for (Device* device : devices) {
        outfile << device->getType().erase(0, 6) << " " << device->getName() << " " << device->IsOn() << " " << device->getValue() << endl;
    }
    outfile.close();
}

// quickly list devices
void SystemManager::quickList() {
    if (numOfDevices <= 5) {
        for (Device* device : devices) {
            device->quickView();
            cout << ", \n";
        }
    }
    else {
        for (Device* device : devices) {
            device->quickView();
            cout << ",  ";
        }
    }
}

void SystemManager::addDevice(string& type, const string& name){
    bool canCreate = true;
    int invalidNameInt;
    vector<string> validTypes = { "light", "lights", "sensor", "temperaturehumiditysensor", "speaker", "radiator", "heater", "valve", "socket", "plug", "thermostat",  };

    for (Device* device : devices) {
        if (device->getName() == name) {
            cout << "A device with that name already exists. \a" << endl;
            canCreate = false;
        }
    }
    
    istringstream inttest(name);
    if (inttest >> invalidNameInt) {
        if (stoi(name) > 0 || stoi(name) < 10) {
            cout << "Device name cannot be a numerical digit 1-9\a" << endl;
            canCreate = false;
        }
    }
    
    transform(type.begin(), type.end(), type.begin(), tolower);
    if (find(validTypes.begin(), validTypes.end(), type) == validTypes.end()){
        cout << "Invalid type name. Accepted types: Light, Speaker, TemperatureHumiditySensor(Sensor), Socket, Thermostat, Radiator\a" << endl;
        canCreate = false;
    }

    if (canCreate) {
        //new devices start off
        devices.push_back(DeviceFactory::instance().createDevice(type, name, 0));       

        if (DeviceFactory::instance().createDevice(type, name, 0) != nullptr){
            cout << "New " << type << " '" << name << "' added." << endl;
        }
    }
}

Device* SystemManager::findDeviceByName(string name) {
    for (Device* device : devices) {
        if (device->getName() == name) return device;
    }
    return nullptr;
}

void SystemManager::sortDevicesByName(){
    vector<Device*> sortedDevices = devices;

    sort(sortedDevices.begin(), sortedDevices.end(), [](Device* a, Device* b) {
        return a->getName() < b->getName();
    });
    cout << "Devices sorted by name:" << endl;
    for (vector<Device*>::iterator it = sortedDevices.begin(); it != sortedDevices.end(); ++it) {
        cout << (*it)->getName();
        if (it != sortedDevices.end() - 1) cout << ", ";
    }
    cout << '\n';
}

void SystemManager::sortDevicesByType(){
    vector<Device*> sortedDevices = devices;

    sort(sortedDevices.begin(), sortedDevices.end(), [](Device* a, Device* b) {
        if (a->getType() == b->getType()) return a->getName() < b->getName();
        return a->getType() < b->getType();
        });
    std::cout << "Devices sorted by type (then name):" << endl;
    for (vector<Device*>::iterator it = sortedDevices.begin(); it != sortedDevices.end(); ++it) {
        cout << (*it)->getName();
        if (it != sortedDevices.end() - 1) cout << ", ";
    }
    std::cout << '\n';

}

void SystemManager::deleteSpecificDevice(){
    string inputDevice;
    Device* deleteDevice;

    cout << "Enter the exact name of the device to delete" << endl;
    cin >> inputDevice;
    deleteDevice = SystemManager::getSystemManager()->findDeviceByName(inputDevice);

    if (deleteDevice != nullptr) {                 //if find not null
        try {
            delete deleteDevice;
            remove(devices.begin(), devices.end(), deleteDevice);   //1
            devices.pop_back();
            cout << "Device deleted successfully." << endl;
        }
        catch (exception e) {
            cout << "Device could not be deleted. ";
        }
        
    }
    else {
        cout << "Couldn't find that device. " << endl;
        return;
    }
    cin.clear();

}

