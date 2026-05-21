#include <iostream>
#include <thread>
#include "producer.h"
#include "consumer.h"
#include "buffer.h"
#include "sync.h"

int main()
{
    std::cout << "Starting Producer-Consumer execution...\n";

    init_sync();

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    destroy_sync();

    std::cout << "Producer-Consumer execution finished.\n";
    return 0;
}
