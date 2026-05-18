#include <iostream>
#include <thread>
#include "producer.h"
#include "consumer.h"
#include "buffer.h"
#include "sync.h"

int main() {
    std::cout << "Starting Producer-Consumer execution...\n";

    // Create producer and consumer threads
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    // Start/join threads
    producerThread.join();
    consumerThread.join();

    std::cout << "Producer-Consumer execution finished.\n";
    return 0;
}
