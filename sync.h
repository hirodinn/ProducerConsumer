#ifndef SYNC_H
#define SYNC_H

#include <condition_variable>
#include <mutex>

extern std::mutex mtx;
extern std::condition_variable notFull;
extern std::condition_variable notEmpty;

#endif
