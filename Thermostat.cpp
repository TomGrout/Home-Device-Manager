#include "Thermostat.h"

void Thermostat::quickView(){
	cout << getName() << (IsOn() ? "[ON - " + to_string(temperature) + "\370C] " : "[OFF] ");
}

void Thermostat::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	cout << "Heating: " << "whatever" << "%" << endl;
	cout << "Schedule: " << "schedules" << endl;
}

void Thermostat::editProperty(){
	int choice;
	cout << "1 - name \n2 - toggle on/off \n3 - boost heating \n4 - cancel" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		this->setName();
		break;

	case 2:
		if (IsOn()) this->turnOff();
		else this->turnOn();
		break;

	case 3:
		this->heatingBoost();
		break;

	case 4:
		break;

	default:
		cout << "Incorrect input, request cancelled" << endl;
		break;
	}
}

void Thermostat::oneClick(){
	turnOn();
	heatingBoost(10);
	quickView();
}

string Thermostat::getValue() const{

	return to_string(temperature);
}

void Thermostat::heatingBoost(){
	int userInput;

	do {
		cin.clear();
		cout << "Set heating boost 1 - 20: ";
		cin >> userInput;
	} while (cin.bad() || userInput < 1 || userInput > 20);
}

void Thermostat::heatingBoost(int val){
	if ((temperature + val) > 50) {
		cout << "Heating cannot exceed 50\370C" << endl;
	}
	else {
		temperature += val;
		cout << "Heating boosted by an extra " << val << "\370C for one hour" << endl;
	}
}
