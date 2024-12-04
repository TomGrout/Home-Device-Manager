#pragma once
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

class SleepTimer
{
private:
	int timeRemaining = 0;
	thread countdown;
	atomic<bool> isRunning;

public:
	SleepTimer(int time) : timeRemaining(time) {}

	void extendTime(int time);
	void Start();

    SleepTimer() : timeRemaining(0), isRunning(false) {}

    ~SleepTimer() {
        stop();
        if (countdown.joinable()) countdown.join();
    }
	
	void stop();
};

