#include <iostream>
#include <thread>
#include <chrono>

#include "consumer.h"
#include "buffer.h"
#include "sync.h"

using namespace std;

void consumer() {

    for (int i = 0; i < 5; i++) {

        unique_lock<mutex> lock(mtx);

        notEmpty.wait(lock, [] {
            return !buffer.empty();
        });

        int item = buffer.front();
        buffer.pop();

        cout << "Consumed: " << item << endl;

        notFull.notify_one();

        lock.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}