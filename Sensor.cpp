#include "Sensor.h"


void Sensor::quickView(){
    cout << getName() << (IsOn() ? " [" + (to_string(temperature) + "\370C / " + to_string(humidity) + "%]") : " [OFF] ");
}

void Sensor::displayInfo(){
    cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
    cout << "Temperature: " << round(temperature) << "\370C" << endl;
    cout << "Humidity: " << humidity << "%" << endl;
}

void Sensor::editProperty(){
	int choice;
	cout << "1 - name \n2 - view usage \n3 - cancel" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		this->setName();
		break;

	case 2:
		this->displayUsage();
		break;

	case 3:
		break;

	default:
		cout << "Incorrect input, request cancelled" << endl;
		break;
	}
}

void Sensor::oneClick()
{
	cout << "Temperature: " << temperature;
	cout << "Humidity: " << humidity;
}

string Sensor::getValue() const
{
	return to_string(humidity) + " " + to_string(temperature);
}

void Sensor::displayUsage()
{
    auto end = high_resolution_clock::now();

    usage = duration_cast<seconds>(end - start).count();

    cout << "Usage: " << usage << endl;
}