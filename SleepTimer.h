#pragma once
#include <thread>
#include <chrono>
#include <atomic>
#include <iostream>
#include "Device.h"

using namespace std;

class SleepTimer
{
private:
	thread countdown;

public:
	atomic<bool> isRunning;
	int timeRemaining = 0;	//time in mins

	SleepTimer(int time = 0) : timeRemaining(time), isRunning(true) {}

	void extend(int time);
	void start(int mins);

    ~SleepTimer() {
        stop();
        if (countdown.joinable()) countdown.join();
    }
	
	void stop();
};

