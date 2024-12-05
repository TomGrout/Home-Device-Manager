#pragma once
#include <fstream>
#include <sstream>

#include "DeviceFactory.h"
#include "Device.h"
#include "Lights.h"
#include "Speaker.h"
#include "Sensor.h"
#include "Socket.h"
#include "Thermostat.h"
#include "Radiator.h"

class SystemManager
{

public:
	vector<Device*> devices;

	~SystemManager();
	SystemManager (const SystemManager&) = delete;
	SystemManager& operator=(const SystemManager&) = delete;


	static SystemManager* getSystemManager();
	void loadDevicesFromFile(const string& filename);
	void displayAll();
	void saveDevicesToFile(const string& filename);
	void quickList();
	void addDevice(string& type, const string& name);
	Device* findDeviceByName(string name);
	void sortDevicesByName();
	void sortDevicesByType();
	void deleteSpecificDevice();

private:
	SystemManager();
	static SystemManager* instantiation;
};

