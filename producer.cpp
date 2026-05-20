#include <chrono>
#include <iostream>
#include <thread>

#include "producer.h"
#include "buffer.h"
#include "sync.h"

void producer() {
	for (int i = 0; i < 5; i++) {
		std::unique_lock<std::mutex> lock(mtx);

		notFull.wait(lock, [] {
			return buffer.size() < BUFFER_SIZE;
		});

		int item = i + 1;
		buffer.push(item);

		std::cout << "Produced: " << item << std::endl;

		notEmpty.notify_one();
		lock.unlock();

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}
