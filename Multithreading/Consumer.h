#pragma once
#include "IThread.h"
#include "Producer.h"
#include <numeric>

class Consumer : public IThread
{
	Producer* producer;
	double average;
	std::mutex averageMutex;
	void ThreadRoutine() override;
public:
	Consumer(Producer* producer);
	double GetAverage();
};
