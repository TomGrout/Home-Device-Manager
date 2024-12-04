#include "Socket.h"

void Socket::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Power: " << (IsOn() ? "On " : "Off ") << endl;
	displayUsage();
}

void Socket::editProperty(){

}

void Socket::oneClick(){
	this->turnOn();
}

string Socket::getValue() const {
	return to_string(Usage());
}

void Socket::displayUsage(){
	auto end = high_resolution_clock::now();

	usage += duration_cast<seconds>(end - start).count();

	cout << "Usage: " << usage << "kW" << endl;
}

int Socket::Usage() const {
	auto end = high_resolution_clock::now();
	int tempUsage = usage;
	tempUsage += (duration_cast<seconds>(end - start).count());
	return tempUsage;
}
