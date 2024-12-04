#include "Radiator.h"

void Radiator::quickView(){
	cout << getName() << (IsOn() ? "[ON - " + to_string(temperature) + "\370C] " : "[OFF] ");
}

void Radiator::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	cout << "Heating: " << (IsOn() ? to_string(temperature) : "0") << "\370C" << endl;
	cout << "Schedule: " << "schedules" << endl;
}

void Radiator::editProperty(){
	int choice;
	cout << "1 - name \n2 - toggle on/off \n3 - set schedule \n4 - cancel" << endl;
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
		
		break;

	case 4:
		break;

	default:
		cout << "Incorrect input, request cancelled" << endl;
		break;
	}
}

void Radiator::oneClick(){
	turnOn();
	quickView();
}

string Radiator::getValue() const {
	return to_string(temperature);
}
