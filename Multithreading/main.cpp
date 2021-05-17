/*
#include "Producer.h"
#include "Consumer.h"
#include <iostream>

int main()
{
	const size_t numberOfConsumers = 2;
	Producer* producer = new Producer();
	producer->Start();
	std::vector<Consumer*> consumers;

	for (size_t i = 0; i < numberOfConsumers; i++)
	{
		consumers.push_back(new Consumer(producer));
		consumers.back()->Start();
	}
	while (true)
	{
		char key = getchar();
		if (key == 'q')
			break;
		else if (key == '\n')
		{
			std::cout << "\n";
			std::cout << "Producer data size: " << producer->GetData().size() << std::endl;
			for (size_t i = 0; i < numberOfConsumers; i++)
			{
				std::cout << "Consumer [" << i << "] average" << consumers[i]->GetAverage() << "\n";
			}
			std::cout << "\n";
		}
	}
	for (auto consumer : consumers)
	{
		consumer->Stop();
		delete consumer;
	}
	producer->Stop();
	delete producer;

}
*/

/* RESULTS:
1] data: 340, objects: 200, time without pool:  39206075us, time with pool: 930us
2] data: 2100, objects: 120, time without pool:  24773845us, time with pool: 631us
3] data: 900, objects: 330, time without pool:  57373307us, time with pool: 977us
4] data: 470000, objects: 20, time without pool: 3945888us, time with pool: 8175us
5] data: 80000, objects: 700, time without pool: 108655185us, time with pool: 15384us
*/