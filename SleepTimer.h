#pragma once
#include <thread>
#include <chrono>
#include <atomic>
#include <mutex>
#include <iostream>

using namespace std;

class SleepTimer
{
private:
	thread countdown;
	int timeRemaining = 0;	//time in secs(for testing) mins(production)

public:
	atomic<bool> isRunning;		//very exact
	mutex mtx;

	SleepTimer(int time = 0) : timeRemaining(time), isRunning(false) {}

	void start(int mins);
	void extend(int time);
	void stop();

    ~SleepTimer() {
        stop();
        if (countdown.joinable()) countdown.join();
    }
	
};

