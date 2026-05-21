#include <iostream>
#include <thread>
#include <chrono>

#include "consumer.h"
#include "buffer.h"
#include "sync.h"

void consumer() {

    for (int i = 0; i < 5; i++) {

        sem_wait(&fullSlots);
        sem_wait(&bufferMutex);

        int item = buffer.front();
        buffer.pop();

        std::cout << "Consumed: " << item << std::endl;

        sem_post(&bufferMutex);
        sem_post(&emptySlots);

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}