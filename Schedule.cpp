#include "Schedule.h"

void Schedule::addSchedule(Schedule* schedule) {

}

shared_ptr<Schedule> Schedule::createSchedule() {
	string timeInput;

	cout << "Enter the schedule start time (e.g. 18:00): ";
	cin >> timeInput;

	if (timeInput.length() > 5 || timeInput.length() < 2) {
		cout << "Invalid input." << endl;
		//return nullptr;
	}
	else {
		int onhrs = stoi(timeInput.substr(0, timeInput.find(':')));
		int onmns = stoi(timeInput.substr(timeInput.find(':') + 1, 2));		//1

		cout << onhrs << onmns;

		if (onhrs > 24 || onhrs < 0 || onmns > 59 || onmns < 0) {
			cout << "Invalid input." << endl;
			//return nullptr;
		}
		else {
			shared_ptr<MyTime> onTim = make_shared<MyTime>(onhrs, onmns);
			//onTime = MyTime(onhrs, onmns);
			cout << *onTim; 

			cout << "Enter the schedule end time (e.g. 20:00): ";
			cin >> timeInput;

			if (timeInput.length() > 5 || timeInput.length() < 2) {
				cout << "Invalid input." << endl;
				//return nullptr;
			}
			else {
				int offhrs = stoi(timeInput.substr(0, timeInput.find(':')));
				int offmns = stoi(timeInput.substr(timeInput.find(':') + 1, 2));

				if (offhrs > 24 || offhrs < 0 || offmns > 59 || offmns < 0) {
					cout << "Invalid input." << endl;
					//return nullptr;
				}
				else {
					shared_ptr<MyTime> offTim = make_shared<MyTime>(offhrs, offmns);
					//offTime = MyTime(offhrs, offmns);
					cout << *offTim;

					shared_ptr<Schedule> schedule = make_shared<Schedule>(onTim, offTim);
					return schedule;
				}
			}
		}
	}
}