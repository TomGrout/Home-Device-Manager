#include "Lights.h"

void Lights::quickView() {
	cout << getName() << " " << (IsOn() ? "[ON " + (to_string(brightness) + "%]") : "[OFF] ") << endl;
}


void Lights::displayInfo() {
	cout << "\nDevice Name: " << getName() << endl;        
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	cout << "Brightness: " << brightness << "%" << endl;
}

void Lights::editProperty() {
	int choice;
	cout << "1 - name \n2 - toggle on/off \n3 - brightness \n4 - cancel" << endl;
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
		this->setBrightness();
		break;

	case 4:
		break;

	default:
		cout << "Incorrect input, request cancelled" << endl;
		break;
	}
}

void Lights::oneClick(){
	this->turnOn();
	this->setBrightness(50);
}

string Lights::getValue() const{
	return to_string(brightness);
}

void Lights::setBrightness()
{
	int prevBrightness = brightness;
	int userInput;

	do {
		cin.clear();
		cout << "Set brightness 0 - 100: ";
		cin >> userInput;
	} while (cin.bad() || userInput < 0 || userInput > 100);

	brightness = userInput;

	if (prevBrightness == 0 && brightness > 0) {
		turnOn();
		cout << "Light turned on" << endl;
	}
	if (prevBrightness > 0 && brightness == 0) {
		turnOff();
		cout << "Device turned off" << endl;
	}

	cout << "Brightness set to " << brightness << endl;
}

void Lights::setBrightness(int val)
{
	brightness = val;
	cout << "Brightness set to " << brightness << endl;
}