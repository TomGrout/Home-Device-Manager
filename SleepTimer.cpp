#include "SleepTimer.h"

void SleepTimer::start(int mins) {
    timeRemaining = mins;
    lock_guard<mutex> guard(mtx);

    while (timeRemaining > 0) {
        isRunning = true;
        this_thread::sleep_for(chrono::seconds(1));
        --timeRemaining;
    }
    cout << "Sleep timer finished. ";
}

void SleepTimer::stop() {
    lock_guard<mutex> guard (mtx);
    isRunning = false;
    timeRemaining = 0;
    cout << "Sleep timer finished" << endl;
}

void SleepTimer::extend(int time) {
    lock_guard<mutex> guard(mtx);

    if (isRunning) {
        timeRemaining += time;
        cout << "Time remaining: " << timeRemaining << endl;
    }
    else {
        cout << "No sleep timer found to extend" << endl;
    }
}