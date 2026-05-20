#include "sync.h"

std::mutex mtx;
std::condition_variable notFull;
std::condition_variable notEmpty;
