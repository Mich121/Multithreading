#pragma once
#include "Integrator.h"
#include <vector>
#include <mutex>
class IntegratorPool
{
	std::vector<Integrator *> pool;
public:
	IntegratorPool(const size_t);
	virtual ~IntegratorPool();	//stop threads and delete memory alocated dynamically
	Integrator * GetInstance(); //get instance of object from Integrator class
	size_t GetLoad();	//number of objects which are processing task
};

