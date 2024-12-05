#include "SleepTimer.h"

void SleepTimer::start(int mins) {
    timeRemaining = mins;

    while (timeRemaining > 0) {
        isRunning = true;
        this_thread::sleep_for(chrono::seconds(1));
        timeRemaining--;
    }
    stop();
}

void SleepTimer::stop() {
    isRunning = false;
    cout << "Sleep timer finished";
}

void SleepTimer::extend(int time) {
    timeRemaining += time;
}