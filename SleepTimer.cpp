#include "SleepTimer.h"

void SleepTimer::start(int mins) {
    lock_guard<mutex> guard(mtx);

    if (isRunning) {
        cout << "Timer already active. You may extend or stop the current timer. " << endl;
        return;
    }
    else {
        timeRemaining = mins;
        isRunning = true;

        while (timeRemaining > 0) {
            if (!isRunning) return;
            this_thread::sleep_for(chrono::seconds(1));
            --timeRemaining;
        }
        isRunning = false;
        cout << "Sleep timer finished. ";
    }
}

void SleepTimer::stop() {
    lock_guard<mutex> guard (mtx);
    if (isRunning) {
        isRunning = false;
        timeRemaining = 0;
        cout << "Sleep timer finished" << endl;
        return;
    }
    else {
        cout << "No sleep timer found to extend" << endl;
        return;
    }
}

void SleepTimer::extend(int time) {
    lock_guard<mutex> guard(mtx);

    if (isRunning) {
        timeRemaining += time;
        cout << "Time remaining: " << timeRemaining << endl;
        return;
    }
    else {
        cout << "No sleep timer found to extend" << endl;
        return;
    }
}