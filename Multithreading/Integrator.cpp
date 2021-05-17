#include "Integrator.h"

void Integrator::SetStatus(Status stat)
{
	statusMutex.lock();
	status = stat;
	statusMutex.unlock();
}

void Integrator::ThreadRoutine()
{
	while (isRunning())
	{
		if (status == Status::WORKING)
		{
			dataMutex.lock();
			int size = data.size();
			double res = 0.0;
			for (int i = 0; i < size; i++)
			{
				res += data[i] * step;
			}
			dataMutex.unlock();

			resultMutex.lock();
			result = res;
			resultMutex.unlock();

			statusMutex.lock();
			status = Status::IDLE;
			statusMutex.unlock();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

Integrator::Integrator(): IThread(), data(), step(0.0), status(Status::IDLE), result(0.0)
{
}

void Integrator::Count(const std::vector<double>& vec, const double st)
{
	dataMutex.lock();
	data = vec;
	step = st;
	dataMutex.unlock();
}

Integrator::Status Integrator::GetStatus()
{
	return status;
}

double Integrator::GetResult()
{
	return result;
}
