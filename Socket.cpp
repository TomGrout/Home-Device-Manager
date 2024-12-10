#include "Socket.h"

void Socket::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	displayUsage();
}

void Socket::editProperty(){
	int choice;
	cout << "1 - name \n2 - toggle on/off \n3 - sleep timer \n4 - cancel" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		setName();
		break;

	case 2:
		if (IsOn()) turnOff();
		else turnOn();
		break;

	case 3:
		int time;
		cout << "Enter how long the device will turn off after (minutes): ";
		cin >> time;
		startTimer(time);
		break;

	case 4:
		break;

	default:
		cout << "Incorrect input, request cancelled" << endl;
		break;
	}
}

void Socket::oneClick(){
	turnOn();
}

string Socket::getValue() const {
	return to_string(usage);
}

void Socket::displayUsage() {
	auto end = high_resolution_clock::now();

	usage += duration_cast<seconds>(end - start).count();

	cout << "Usage: " << usage << "kW" << endl;
}

void Socket::startTimer(int mins)
{
	turnOn();

	thread t([this, mins]() {
		st.start(mins);
		turnOff();
		cout << getName() << " turned off." << endl;
		});
	t.detach();

}