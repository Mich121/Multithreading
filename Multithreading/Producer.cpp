#include "Producer.h"

void Producer::ThreadRoutine()
{
	while (isRunning())
	{
		double randomElement = rand() % 100;
		dataMutex.lock();
		data.push_back(randomElement);
		dataMutex.unlock();
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}
//thread generate random double and add to vector

std::vector<double> Producer::GetData()
{
	std::vector<double> outData;
	dataMutex.lock();
	outData = data;
	dataMutex.unlock();

	return outData;
}
//get vector which have data from ThreadRoutine