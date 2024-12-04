#pragma once
#include <iostream>
#include <string>
#include <typeinfo> 
#include <list>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

static int numOfDevices = 0;

class Device
{
private: 
	bool On;
	string name;
	string type;

public:
	virtual void turnOn();
	virtual void turnOff();

	Device(const std::string& initialName = ("Device" + to_string(numOfDevices)), bool on = false);
	virtual ~Device();

	virtual void quickView() {
		cout << getName() << ": " << (IsOn() ? "[ON] " : "[OFF] ") << endl;
	}
	virtual void displayInfo() = 0;
	virtual void editProperty() = 0;
	virtual void oneClick() = 0;
	virtual string getValue() const {
		return "0"; 
	}

	void setName();
	string getName() const;
	string getType() const;
	bool IsOn() const;

};

