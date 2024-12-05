#include "Socket.h"

void Socket::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	displayUsage();
}

void Socket::editProperty(){
	startTimer(5);
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
	st.start(mins);
	turnOff();
}