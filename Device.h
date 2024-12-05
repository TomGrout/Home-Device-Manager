#pragma once
#include <iostream>
#include <string>
#include <typeinfo> 
#include <list>
#include <algorithm>
#include <vector>
#include <chrono>
#include <memory>
#include <stdlib.h>
#include <atomic>

using namespace std;

static int numOfDevices = 0;

class Device
{
private: 
	atomic<bool> On;
	string name;
	string type;

protected:
	virtual void turnOn();
	virtual void turnOff();
	void setName();
	float round(float value);

public:
	Device(const std::string& initialName = ("Device" + to_string(numOfDevices)), bool on = false);
	virtual ~Device();

	virtual void quickView();
	virtual void displayInfo() = 0;
	virtual void editProperty() = 0;
	virtual void oneClick() = 0;
	virtual string getValue() const { return "0"; }
	string getName() const;
	string getType() const;
	bool IsOn() const;

};

