#pragma once
#include <thread>
#include <vector>
#include <mutex>

//abstract class used for servicing threads
class IThread
{
	//thread state
	enum Status
	{
		STOPPED,
		RUNNING
	};
	std::thread * thr;
	Status status;
public:
	IThread();
	virtual ~IThread();
	void Start();	//thread activation
	void Stop();	//thread stop suddenly
	void Join();	//thread stop safety, wait until ThreadRoutine ends, bad if function dont end for example infinite loop
	bool isRunning();	//get state of thread, true if thread is running
	virtual void ThreadRoutine() = 0;	//pure virtual funtion, describe activity of thread
};

