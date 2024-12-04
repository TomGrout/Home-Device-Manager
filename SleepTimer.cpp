#include "SleepTimer.h"

void SleepTimer::Start() {
    while (timeRemaining > 0 && isRunning) {
        this_thread::sleep_for(chrono::seconds(1));
        timeRemaining--;
    }
}


void SleepTimer::stop() {
    isRunning = false;
}

void SleepTimer::extendTime(int time) {
    timeRemaining += time;
}