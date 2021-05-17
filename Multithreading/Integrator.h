#pragma once
#include "IThread.h"

//definite integral calculator
class Integrator : public IThread
{
public:
	//thread state
	enum Status
	{
		IDLE,
		WORKING
	};
private:
	std::vector<double> data;	//integral schedule
	double step;	//integral step
	Status status;
	double result;
	std::mutex dataMutex;	//synchronization fields: data and step
	std::mutex statusMutex;	//synchronization fields: status
	std::mutex resultMutex;	//synchronization fields: result
	void SetStatus(Status);
	void ThreadRoutine() override;
public:
	Integrator();
	void Count(const std::vector<double>&, const double);	//get data and integral step
	Status GetStatus();
	double GetResult();


};

