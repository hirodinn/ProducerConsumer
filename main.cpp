#include <iostream>
#include <thread>
#include "producer.h"
#include "consumer.h"
#include "buffer.h"
#include "sync.h"

std::mutex mtx;
std::condition_variable notFull;
std::condition_variable notEmpty;

int main()
{
    std::cout << "Starting Producer-Consumer execution...\n";

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Producer-Consumer execution finished.\n";
    return 0;
}
