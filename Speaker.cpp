#include "Speaker.h"

void Speaker::quickView(){
	cout << getName() << ": " << IsOn() ? "[ON - " + to_string(volume) + "]" : "[OFF] ";
}

void Speaker::displayInfo(){
	cout << "\n" << getType().erase(0, 6) << " Name: " << getName() << endl;
	cout << "Playing: " << (IsOn() ? "Yes " : "No ") << endl;
	cout << "Volume: ";
	for (int i = 0; i < volume; i++) cout << "\376";
	for (int i = 0; i < 10-volume; i++) cout << " ";
	cout << "|" << volume << endl;
}

void Speaker::editProperty(){
	int choice;
	cout << "1 - name \n2 - toggle play/stop \n3 - volume \n4 - cancel" << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		setName();
		break;

	case 2:
		if (playing == true) stop();
		else play();
		cout << "Speaker " << playing ? "on" : "off";
		break;

	case 3:
		setVolume();
		break;

	case 4:
		break;

	default:
		cout << "Invalid input, request cancelled" << endl;
		break;
	}
}

void Speaker::oneClick(){
	if (volume < 5) {
		volume += 1;
		cout << "Volume turned up" << endl;
	}
	else if (volume > 4) {
		volume -= 1;
		cout << "Volume turned down" << endl;
	}
}

string Speaker::getValue() const
{
	return to_string(volume);
}

void Speaker::setVolume(int v){
	volume = v;
	std::cout << "Volume set to: " << volume << endl;
}

void Speaker::setVolume(){
	string v;
	cout << "Set volume: ";
	cin >> v;

	try{
		if (stoi(v) > 10 || stoi(v) < 0) {
			cout << "Invalid volume \a";
		}
		else {
			volume = stoi(v);
			cout << "Volume set to: " << volume << endl;
		}
	}
	catch (exception e) {
		cout << "Invalid input" << endl;
	}
}

void Speaker::play() {
	playing = true;
	turnOn();
}

void Speaker::stop() {
	playing = false;
	turnOff();
}
