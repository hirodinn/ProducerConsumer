#include <chrono>
#include <iostream>
#include <thread>

#include "producer.h"
#include "buffer.h"
#include "sync.h"

void producer() {
	for (int i = 0; i < 5; i++) {
		sem_wait(&emptySlots);
		sem_wait(&bufferMutex);

		int item = i + 1;
		buffer.push(item);

		std::cout << "Produced: " << item << std::endl;

		sem_post(&bufferMutex);
		sem_post(&fullSlots);

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
