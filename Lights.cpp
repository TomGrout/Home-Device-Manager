#include "Lights.h"

void Lights::quickView() {
	cout << getName() << " " << (IsOn() ? "[ON " + (to_string(brightness) + "%]") : "[OFF] ");
}


void Lights::displayInfo() {
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	cout << "Brightness: " << brightness << "%" << endl;
}

void Lights::editProperty() {
	int choice;
	cout << "1 - name \n2 - toggle on/off \n3 - brightness \n4 - sleep timer \n5 - cancel" << endl;
	cin >> choice; string stChoice; int time;

	switch (choice) {
	case 1:
		setName();
		break;

	case 2:
		if (IsOn()) turnOff();
		else turnOn();
		cout << "Device turned " << IsOn() ? "on" : "off";
		break;

	case 3:
		setBrightness();
		break;

	case 4:
		cout << "1 - new / 2 - extend / 3 - stop ";
		cin >> stChoice;

		if (stChoice == "1") {
			cout << "Enter how long the device will turn off after (minutes): ";
			cin >> time;
			startTimer(time);
		}
		else if (stChoice == "2") {
			cout << "Enter how long to extend timer by (minutes): ";
			cin >> time;
			timer.extend(time);
		}
		else if (stChoice == "3") {
			timer.stop();
		}
		else {
			cout << "Invalid choice" << endl;
		}
		break;

	case 5:
		break;

	default:
		cout << "Invalid input, request cancelled" << endl;
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

void Lights::startTimer(int mins){

	if (timer.isRunning) {
		cout << "Timer already active. You may extend or stop the current timer. " << endl;
		return;
	}

	turnOn();

	thread t([this, mins]() {
		timer.start(mins);
		turnOff();
		cout << getName() << " turned off.\n" << endl;
		});
	t.detach();

}
