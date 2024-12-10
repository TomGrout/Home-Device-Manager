#pragma once
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <iostream>
#include "Device.h"

using namespace std;

class SleepTimer
{
private:
	thread countdown;
	atomic<bool> isRunning;
	int timeRemaining = 0;	//time in secs
	mutex mtx;

public:

	SleepTimer(int time = 0) : timeRemaining(time), isRunning(true) {}

	void start(int mins);
	void extend(int time);
	void stop();

    ~SleepTimer() {
        stop();
        if (countdown.joinable()) countdown.join();
    }
	
};

