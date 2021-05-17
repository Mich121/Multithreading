#pragma once
#include "IThread.h"

class Producer : public IThread
{
	std::vector<double> data;
	std::mutex dataMutex;

	void ThreadRoutine() override;
public:
	std::vector<double> GetData();
};
